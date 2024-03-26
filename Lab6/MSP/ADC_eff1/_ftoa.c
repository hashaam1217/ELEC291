/*-------------------------------------------------------------------------
  _ftoa.c - float to ASCII conversion

		 Floating point support by - Jesus Calvino-Fraga (2017)

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

-------------------------------------------------------------------------*/

union float_long_bytes
{
	float f;
	unsigned long l;
	unsigned char b[4];
};

void _ftoa (float a, char * _taos)
{
	volatile union float_long_bytes flb;
	int sign='+';
	int bin_exp;
	int dec_exp=0; // Decimal exponent
	unsigned char bcd_man[5]={0x00, 0x00, 0x00, 0x00, 0x00}; // BCD mantisa has at least 8/9 digits
	int j, k;
	
	if(a!=0.0)
	{
		flb.f=a;
		
		sign=(flb.b[3]&0x80)?'-':'+';
		bin_exp=(((flb.b[3]&0x7f)<<1)|((flb.b[2]&0x80)?1:0))-127;
		flb.b[3]=0;
		flb.b[2]|=0x80; // Most significant bit in FP 24-bit mantissa is implicit 1
	
		// Initialize BCD exponent
		dec_exp=8; // We set it to eight because we end up with 8 decimal digits.
	
		// In order to proceed, the FP exponent needs to be >24. If not, we need to multiply the FP mantissa by 10 until FP exponent >24.
		while (bin_exp<=24)
		{
			flb.l*=10;
			dec_exp--; // Every time we multiply by ten we decrement the decimal exponent by one
			// Normalize the FP mantissa by shifting the product right.
	    	while(flb.b[3]!=0)
	    	{
	    		if(flb.b[0]&1) flb.l+=1;// We are loosing a bit, so round up
	    		flb.l>>=1;
	    		bin_exp++; // After every shift increment the FP exponent.
	    	}
		}
		
		// Binary to BCD conversion loop
		for(j=0; j<(bin_exp+1); j++)
		{
			
			//Multiply bcd_mantisa by two. If needed apply bcd correction before left shift 
			for(k=0; k<5; k++)
			{
				if((bcd_man[k]&0x0f)>0x04) bcd_man[k]+=0x03; // Correction for LSD
				if((bcd_man[k]&0xf0)>0x40) bcd_man[k]+=0x30; // Correction for MSD
			}
			// Now shift left the bcd mantisa array
			for(k=4;k>0; k--)
			{
				bcd_man[k]<<=1;
				if(bcd_man[k-1]&0x80) bcd_man[k]|=1;
			}
			bcd_man[0]<<=1;
			if(flb.b[2]&0x80) bcd_man[0]|=1; // Add the last bit of the binary mantissa
			flb.l<<=1; // Shift binary mantisa left one bit to access the next significant bit		
			
			// Check for overflow and adjust the bcd mantissa and decimal exponent accordingly
			if(bcd_man[4]&0xf0)
			{
				for(k=0; k<4; k++) bcd_man[k]=(bcd_man[k]>>4)|(bcd_man[k+1]<<4);
				bcd_man[4]=(bcd_man[4]>>4);
				dec_exp++;
			}
		}
		
		if(bcd_man[4]==0 )
		{
			for(k=4; k>0; k--) bcd_man[k]=(bcd_man[k]<<4)|(bcd_man[k-1]>>4);
			bcd_man[0]=(bcd_man[0]<<4);
			dec_exp--;
		}
	}
	
	k=0;
	_taos[k++] =sign;
	_taos[k++] =(bcd_man[4]%0x10)+'0';
	_taos[k++] ='.';
	for(j=3; j>=0; j--)
	{
		_taos[k++] =(bcd_man[j]/0x10)+'0';
		_taos[k++] =(bcd_man[j]%0x10)+'0';
	}
	_taos[k++]='E';
	if(dec_exp<0)
	{
		dec_exp*=-1;
		_taos[k++]='-';
	}
	else
	{
		_taos[k++]='+';
	}
	_taos[k++]=(dec_exp/10)+'0';
	_taos[k++]=(dec_exp%10)+'0';
	_taos[k++]=0;
}
