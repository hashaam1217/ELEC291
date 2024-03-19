/*-------------------------------------------------------------------------
  print_format.c - formatted output conversion

		 Written By - Martijn van Balen aed@iae.nl (1999)
		 Floating point support by - Jesus Calvino-Fraga (2011)

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

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>

typedef void (*pfn_outputchar)(char c);

#define BOOL unsigned int

#define PTR value.ptr

#define ptr_t const char *

#ifdef toupper
#undef toupper
#endif
#ifdef tolower
#undef tolower
#endif
#ifdef islower
#undef islower
#endif
#ifdef isdigit
#undef isdigit
#endif

#define toupper(c) ((c)&=0xDF)
#define tolower(c) ((c)|=0x20)
#define islower(c) ((unsigned char)c >= (unsigned char)'a' && (unsigned char)c <= (unsigned char)'z')
#define isdigit(c) ((unsigned char)c >= (unsigned char)'0' && (unsigned char)c <= (unsigned char)'9')

#define DEFAULT_FLOAT_PRECISION 6

typedef union
{
    unsigned char  byte[5];
    long           l;
    unsigned long  ul;
    float          f;
    const char     *ptr;
    int *iptr;
} value_t;

static pfn_outputchar output_char;
static value_t value;
static int charsOutputted;
static int radix;
static int width;
static int decimals;
static int  length;
static unsigned int i;

static BOOL   lower_case;
static BOOL   f_argument;
static BOOL   e_argument;
static BOOL   g_argument;
static BOOL   left_justify;
static BOOL   zero_padding;
static BOOL   prefix_sign;
static BOOL   prefix_space;
static BOOL   signed_argument;
static BOOL   char_argument;
static BOOL   long_argument;
static BOOL   pound_argument;
static BOOL   lsd;
static BOOL   fflag;

#define OUTPUT_CHAR(c) _output_char (c)
static void _output_char( unsigned char c )
{
    output_char(c);
    charsOutputted++;
}

char ASCII[]="0123456789ABCDEF";
char ASCII2[]="0123456789abcdef";

static void output_digit( unsigned char n )
{
    _output_char( lower_case?ASCII2[n&0xf]:ASCII[n&0xf] );
}

#define OUTPUT_2DIGITS( B )   output_2digits( B )
static void output_2digits( unsigned char b )
{
    output_digit( b>>4   );
    output_digit( b&0x0F );
}


static void calculate_digit( void )
{
    register unsigned long ul = value.ul;
    register unsigned char b4 = value.byte[4];
    
    i = 32;

    do
    {
        b4 = (b4 << 1);
        b4 |= (ul >> 31) & 0x01;
        ul <<= 1;

        if (radix <= b4 )
        {
            b4 -= radix;
            ul |= 1;
        }
    }
    while (--i);
    value.ul = ul;
    value.byte[4] = b4;
}

#define reqWidth width
#define reqDecimals decimals
#define left left_justify
#define zero zero_padding
#define sign prefix_sign
#define space prefix_space


#ifdef PRINTF_FLOAT
char _taos[16]; // To ASCII output string used by _ftoa()

union float_long_bytes
{
	float f;
	unsigned long l;
	unsigned char b[4];
};

void _ftoa (float a)
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
	_taos[k++] =ASCII[bcd_man[4]%0x10];
	_taos[k++] ='.';
	for(j=3; j>=0; j--)
	{
		_taos[k++] =ASCII[bcd_man[j]/0x10];
		_taos[k++] =ASCII[bcd_man[j]%0x10];
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
	_taos[k++]=ASCII[dec_exp/10];
	_taos[k++]=ASCII[dec_exp%10];
	_taos[k++]=0;
}

static void output_f (void)
{
    int exp, minWidth;
    
    exp=(_taos[13]-'0')*10+(_taos[14]-'0');
    if(_taos[12]=='-') exp*=-1;
    minWidth=1;

    if(exp>0)
    {
        for(i=3; i<10; i++)
        {
            minWidth++;
            _taos[i-1]=_taos[i];
            _taos[i]='.';
            exp--;
            if(exp==0) break;
        }
    }

    if(exp<0)
    {
        _taos[2]=_taos[1];
        _taos[1]='.';
        exp++;
    }

    if(reqDecimals)
    {
    	minWidth+=reqDecimals+1;
    }
    else
    {
    	if(pound_argument) minWidth++;
    }
    
    if ((_taos[0]=='-') || sign || space) minWidth++;

    if (!left)
    {
        if (zero)
        {
            if (_taos[0]=='-')  OUTPUT_CHAR('-');
            else if (sign)  OUTPUT_CHAR('+');
            else if (space) OUTPUT_CHAR(' ');

            if (_taos[1]=='.')
            {
                OUTPUT_CHAR('0');
                reqWidth--;
            }

            while (reqWidth>minWidth) { OUTPUT_CHAR('0'); reqWidth--; }
        }
        else
        {
            while (reqWidth>minWidth) { OUTPUT_CHAR(' '); reqWidth--; }

            if (_taos[0]=='-')  OUTPUT_CHAR('-');
            else if (sign)  OUTPUT_CHAR('+');
            else if (space) OUTPUT_CHAR(' ');

            if (_taos[1]=='.')
            {
                OUTPUT_CHAR('0');
                reqWidth--;
            }
        }
    }
    else // Left aligment
    {
        if (_taos[0]=='-')
        {
            OUTPUT_CHAR('-');
            reqWidth--;
        }
        else if (sign)
        {
            OUTPUT_CHAR('+');
            reqWidth--;
        }
        else if (space)
        {
            OUTPUT_CHAR(' ');
            reqWidth--;
        }

        if (_taos[1]=='.')
        {
            OUTPUT_CHAR('0');
            reqWidth--;
        }
    }

    // output the number
    for(i=1, fflag=0; _taos[i]!='E'; i++)
    {
        if(_taos[i]=='.')
        {
        	while(exp>0)
        	{
        		OUTPUT_CHAR ('0');
        		exp--;
        	}
            fflag=1;
            if(reqDecimals==0) 
            {
            	if(pound_argument)
            		OUTPUT_CHAR ('.');
            	break;
            }
        }
        else if (fflag)
        {
         	while(exp<0)
        	{
        		if(reqDecimals>0)
        		{
	        		OUTPUT_CHAR ('0');
	            	reqDecimals--;
            	}
            	exp++;
            }
        }
        if((fflag==0) || (reqDecimals>0) )
        {
       		OUTPUT_CHAR (_taos[i]);
       		if((fflag)&&(_taos[i]!='.')) reqDecimals--;
       	}
        reqWidth--;
        if((reqDecimals<=0) && (fflag)) break;
    }

    while(reqDecimals>0)
    {
        OUTPUT_CHAR('0');
        reqDecimals--;
    }

    if (left)
    {
        while (reqWidth--)
        {
            OUTPUT_CHAR(' ');
        }
    }
}

static void output_e (void)
{	
	if( (reqDecimals) || (pound_argument) )
	{
		reqWidth-=(7+reqDecimals);
	}
	else
	{
		reqWidth-=6; // No decimal point or decimals
	}
	
	i=0;
	if( (_taos[0]=='+') && (!sign) )
	{
		_taos[0]=' ';
		if (!space)
		{
			i++;
			reqWidth++;
		}
	}
		
	if(!left)
	{
		while( reqWidth>0 )
		{
			OUTPUT_CHAR(' ');
			reqWidth--;
		}
	}
	
    for(fflag=0; _taos[i]!=0; i++)
    {
        if(_taos[i]=='E')
        {
        	if(lower_case) _taos[i]='e';
            while(reqDecimals>0)
		    {
		        OUTPUT_CHAR('0');
		        reqDecimals--;
		    }
            fflag=1;
        }
        if( (i<2) || ( (i>=2) && (reqDecimals>0) ) || (fflag) )
        {
       		OUTPUT_CHAR (_taos[i]);
       		if(i>2) reqDecimals--;
       	}
       	else
       	{
       		if((i==2) && (pound_argument))
      			OUTPUT_CHAR ('.');
       	}
    }
    
	if(left)
	{
		while( reqWidth>0 )
		{
			OUTPUT_CHAR(' ');
			reqWidth--;
		}
	}
    
}
#endif

int _print_format (pfn_outputchar pfn, const char *format, va_list ap)
{
    int c;
    output_char = pfn;

    // reset output chars
    charsOutputted = 0;
    
    while( c=*format++ )
    {

        if ( c=='%' )
        {
            left_justify    = 0;
            zero_padding    = 0;
            prefix_sign     = 0;
            prefix_space    = 0;
            signed_argument = 0;
            char_argument   = 0;
            long_argument   = 0;
            pound_argument  = 0;
            f_argument      = 0;
            e_argument      = 0;
            g_argument      = 0;
            radix           = 0;
            width           = 0;
            decimals        = -1;

get_conversion_spec:

            c = *format++;

            if (c=='%')
            {
                OUTPUT_CHAR(c);
                continue;
            }

            if (isdigit(c))
            {
                if (decimals==-1)
                {
                    width = 10*width + (c - '0');
                    if (width == 0)
                    {
                        /* first character of width is a zero */
                        zero_padding = 1;
                    }
                }
                else
                {
                    decimals = 10*decimals + (c-'0');
                }
                goto get_conversion_spec;
            }

            if (c=='.')
            {
                if (decimals==-1) decimals=0;
                else
                    ; // duplicate, ignore
                goto get_conversion_spec;
            }

            if (islower(c))
            {
                c = toupper(c);
                lower_case = 1;
            }
            else
                lower_case = 0;

            switch( c )
            {
            case '-':
                left_justify = 1;
                goto get_conversion_spec;
            case '+':
                prefix_sign = 1;
                goto get_conversion_spec;
            case ' ':
                prefix_space = 1;
                goto get_conversion_spec;
            case 'B':
                char_argument = 1;
                goto get_conversion_spec;
            case 'L':
                long_argument = 1;
                goto get_conversion_spec;
            case '#':
            	pound_argument = 1;
            	goto get_conversion_spec;
            case '*':
            	if(decimals==-1)
            	{
                    width = va_arg(ap,int);
                }
                else
                {
                    decimals = va_arg(ap,int);
                }
            	goto get_conversion_spec;

            case 'C':
                c = va_arg(ap,int);
                OUTPUT_CHAR( c );
                break;

            case 'S':
                PTR = va_arg(ap,ptr_t);

                length = strlen(PTR);
                if ( decimals == -1 )
                {
                    decimals = length;
                }
                if ( ( !left_justify ) && (length < width) )
                {
                    width -= length;
                    while( width-- != 0 )
                    {
                        OUTPUT_CHAR( ' ' );
                    }
                }

                while ( (c = *PTR)  && (decimals-- > 0))
                {
                    OUTPUT_CHAR( c );
                    PTR++;
                }

                if ( left_justify && (length < width))
                {
                    width -= length;
                    while( width-- != 0 )
                    {
                        OUTPUT_CHAR( ' ' );
                    }
                }
                break;

            case 'P':
                PTR = va_arg(ap,ptr_t);
				OUTPUT_2DIGITS( value.byte[1] );
				OUTPUT_2DIGITS( value.byte[0] );
                break;

            case 'D':
            case 'I':
                signed_argument = 1;
                radix = 10;
                break;

            case 'O':
                radix = 8;
                break;

            case 'U':
                radix = 10;
                break;

            case 'X':
                radix = 16;
                break;

            case 'F':
                f_argument=1;
                break;

            case 'E':
                e_argument=1;
                break;

            case 'G':
                g_argument=1;
                break;
              
            case 'N':
                value.iptr = va_arg(ap,int *);
            	*value.iptr= charsOutputted;
            	break;
                
            default:
                // nothing special, just output the character
                OUTPUT_CHAR( c );
                break;
            }

            if ( (f_argument) || (e_argument) || (g_argument))
            {
                value.f=va_arg(ap,double);
#ifdef PRINTF_FLOAT
				_ftoa(value.f);
    			// display some decimals as default
				if (reqDecimals==-1) reqDecimals=DEFAULT_FLOAT_PRECISION;

				if(g_argument)
				{
					int fexp;
					fexp=value.byte[3]&0x7F; // Get the float exponent
					fexp<<=1;
					if(value.byte[2]&0x80) fexp|=0x01;
					
					if( (fexp>(127+24)) || (fexp<(127-24)) )
					{
						e_argument=1;
					}
					if(value.f==0.0)
					{
						e_argument=0;
					}
				}
                if(e_argument)
                {
                    output_e();
                }
                else
                {
                    output_f();
                }
#endif 
            }
            else if (radix != 0)
            {
                unsigned char store[6];
                unsigned char *pstore = &store[5];
                
                // store value in byte[0] (LSB) ... byte[3] (MSB)
                if (char_argument)
                {
                    value.l = va_arg(ap,int);
                    if (!signed_argument)
                    {
                        value.l &= 0xFF;
                    }
                }
                else if (long_argument)
                {
                    value.l = va_arg(ap,long);
                }
                else // must be int
                {
                    value.l = va_arg(ap,int);
                    if (!signed_argument)
                    {
                        value.l &= 0xFFFF;
                    }
                }
                
                if( (pound_argument) && (value.l!=0) )
                {
                	if(radix==8)
                	{
                		OUTPUT_CHAR( '0' );
                	}
                	else if (radix==16)
                	{
               			OUTPUT_CHAR( '0' );
                		if(lower_case)
                			OUTPUT_CHAR( 'x' );
                		else
                			OUTPUT_CHAR( 'X' );
                	}
                }

                if ( signed_argument )
                {
                    if (value.l < 0)
                        value.l = -value.l;
                    else
                        signed_argument = 0;
                }

                length=0;
                lsd = 1;

                do
                {
                    value.byte[4] = 0;
                    calculate_digit();
                    if (!lsd)
                    {
                        *pstore = (value.byte[4] << 4) | (value.byte[4] >> 4) | *pstore;
                        pstore--;
                    }
                    else
                    {
                        *pstore = value.byte[4];
                    }
                    length++;
                    lsd = !lsd;
                }
                while( value.ul );

                if (width == 0)
                {
                    // default width. We set it to 1 to output
                    // at least one character in case the value itself
                    // is zero (i.e. length==0)
                    width=1;
                }

                /* prepend spaces if needed */
                if (!zero_padding && !left_justify)
                {
                    while ( width > (unsigned char) (length+1) )
                    {
                        OUTPUT_CHAR( ' ' );
                        width--;
                    }
                }

                if (signed_argument) // this now means the original value was negative
                {
                    OUTPUT_CHAR( '-' );
                    // adjust width to compensate for this character
                    width--;
                }
                else if (length != 0)
                {
                    // value > 0
                    if (prefix_sign)
                    {
                        OUTPUT_CHAR( '+' );
                        // adjust width to compensate for this character
                        width--;
                    }
                    else if (prefix_space)
                    {
                        OUTPUT_CHAR( ' ' );
                        // adjust width to compensate for this character
                        width--;
                    }
                }

                /* prepend zeroes/spaces if needed */
                if (!left_justify)
                    while ( width-- > length )
                    {
                        OUTPUT_CHAR( zero_padding ? '0' : ' ' );
                    }
                else
                {
                    /* spaces are appended after the digits */
                    if (width > length)
                        width -= length;
                    else
                        width = 0;
                }

                /* output the digits */
                while( length-- )
                {
                    lsd = !lsd;
                    if (!lsd)
                    {
                        pstore++;
                        value.byte[4] = *pstore >> 4;
                    }
                    else
                    {
                        value.byte[4] = *pstore & 0x0F;
                    }
                    output_digit( value.byte[4] );
                }
                if (left_justify)
                {
                    while (width-- > 0)
                    {
                        OUTPUT_CHAR( ' ' );
                    }
                }
            }
        }
        else
        {
            // nothing special, just output the character
            OUTPUT_CHAR( c );
        }
    }

    return charsOutputted;
}

pfn_outputchar pfn_oc=NULL;

void set_stdout_to(pfn_outputchar pfn)
{
	pfn_oc=pfn;
}

int printf (const char *format, ...)
{
    va_list arg;
    int i;

	if(pfn_oc==NULL) return -1;
	
    va_start (arg, format);
    i = _print_format( pfn_oc, format, arg );
    va_end (arg);

    return i;
}

int vprintf (const char *format, va_list ap)
{
	if(pfn_oc==NULL) return -1;
    return _print_format( pfn_oc, format, ap );
}

int puts (const char *s)
{
    int i = 0;

	if(pfn_oc==NULL) return -1;
    output_char = pfn_oc;

    while (*s)
    {
        OUTPUT_CHAR(*s++);
        i++;
    }
    OUTPUT_CHAR('\n');
    return i+1;
}

static char * obuf;

static void put_char_to_string( char c )
{
    *obuf++ = c;
}

int sprintf (char *buf, const char *format, ...)
{
    va_list arg;
    int i;

    va_start (arg, format);
    obuf=buf;
    i = _print_format( put_char_to_string, format, arg );
    *obuf = 0;
    va_end (arg);

    return i;
}

int vsprintf (char *buf, const char *format, va_list ap)
{
    int i;
    obuf=buf;
    i = _print_format( put_char_to_string, format, ap );
    *obuf = 0;
    return i;
}

