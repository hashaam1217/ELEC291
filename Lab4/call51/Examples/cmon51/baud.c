#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
	double baud[]={150, 300, 600, 1200, 2400, 4800,
	               9600, 19200, 38400, 57600, 115200, 0};

	double Oscillator=22118400;
	int th1, j, k, rcap2;
	double BaudRate, BaudError;
	char buff[128];

	if(argc>1) Oscillator=atof(argv[1]);
	if (Oscillator<100.0) Oscillator*=1e6;

	printf("//For an oscillator frequency of %4.4fMHz...\n", Oscillator/1.0e6);
	printf("\n//For timer 1, these are the correct values for TH1:\n");

	for(k=1; k<3; k++)
	{
		printf("//For k=%d:\n", k);
		for(j=0; baud[j]!=0.0; j++)
		{
			th1=256.5-((k*Oscillator)/(32*12*baud[j]));
			if(th1==256) th1=0;
			if(th1>=0)
			{
				BaudRate=(k*Oscillator)/(32*12*(256-th1));
				BaudError=(fabs(baud[j]-BaudRate)*100.0)/baud[j];
				if(BaudError<10.0)
				{
					sprintf(buff, "TIMER1_K%d_%.0f", k, baud[j]);
					printf("#define %-18s %#02x ", buff, th1);
					if (BaudError>=0.1)
					    printf("/*%baud=%.0f, error=%.1f%%*/\n", BaudRate, BaudError);
					else
						printf("\n");
				}
			}
		}
	}

	printf("\n//If timer 2 is used to generate the baud rate,\n"
	         "//these are the correct values for [RCAP2H, TCAP2L]:\n");

	for(j=0; baud[j]!=0.0; j++)
	{
		rcap2=65536.5-((Oscillator)/(32*baud[j]));
		if(rcap2==65536) rcap2=0;
		if(rcap2>=0)
		{
			BaudRate=(Oscillator)/(32*(65536-rcap2));
			BaudError=(fabs(baud[j]-BaudRate)*100.0)/baud[j];
			if(BaudError<5.0)
			{
				sprintf(buff, "TIMER2_%.0f", baud[j]);
				printf("#define %-14s %#04x ", buff, rcap2);
				if (BaudError>=0.1)
				    printf("/*%baud=%.0f, error=%.1f%%*/\n", BaudRate, BaudError);
				else
					printf("\n");
			}
		}
	}
}
