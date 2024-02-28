/*
    s51.c: simulator main

    Copyright (C) 2009-2012  Jesus Calvino-Fraga, jesusc (at) ece.ubc.ca
    
	This program is free software; you can redistribute it and/or modify it
	under the terms of the GNU General Public License as published by the
	Free Software Foundation; either version 2, or (at your option) any
	later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <time.h>
#include "s51.h"

/* The interrupt system generates an LCALL to the appropriate
service routine, provided that the instruction in progress
is not a RETI or any write to the IE or IP registers. 
The ensures that at least one more instruction is executed
before any interrupt is vectored to.*/
extern unsigned char interrupt_stall;
extern int sjmp_intself;

extern int connected;
void send_telnet(char * buff, int size);
UINT ServerThread(LPVOID pParam);

unsigned char get_code (unsigned int Addr);
unsigned char get_xdata (unsigned int Addr);
void set_xdata_to (unsigned int Addr, unsigned char Val);
void update_parity (void);
int check_interrupts (void);
void do_timer_0_1 (void);
void do_timer_2 (void);

extern unsigned char int_level[5];
extern unsigned char int_level_cur;

unsigned char validbyte, keepediting;
extern char hexval[];
#define EQ(A,B) !strcmp((A),(B))
#define EQU(A,B) !stricmp((A),(B))
#define	lowof(x) ((unsigned char)(x%0x100))
#define highof(x) ((unsigned char)(x/0x100))

char fname[0x1000]="";
char oname[0x1000]="";
FILE * sof=NULL;
int run_on_start=0;
unsigned int overlap_start=0x10000;
unsigned int overlap_end=0;

unsigned char chartohex(char c)
{
	unsigned char i;
	i=toupper(c)-'0';
	if(i>9) i-=7; //letter from A to F
	return i;
}

void outbyte(unsigned int x)
{
	putchar(hexval[(x&0xff)/0x10]);
	putchar(hexval[(x&0xff)&0xf]);
}

void outword(unsigned int x)
{
	outbyte(highof((x&0xffff)));
	outbyte(lowof((x&0xffff)));
}

//Get a byte from the serial port with echo
unsigned char getbyte (void)
{
	unsigned char i, j=0, k;

	for (k=0; k<2; k++)
	{
		i=_getch();
		putchar(i==(unsigned char)' '?'x':i);
		if(!isxdigit(i))
		{
			validbyte=0;
			if(i==(unsigned char)' ')
			{
				keepediting=1;
				if(k==0) putchar('x');
			}
			else keepediting=0;
			return j;
		}
		j=j*0x10+chartohex(i);
	}
	keepediting=1;
	validbyte=1;
	return j;
}

//A very simple memory editor
void modifymem(int index,  char loc)
{
	unsigned char j, k=0;

	while(1)
	{
		if(k==0)
		{
        	putchar('\n');
        	putchar(loc);
        	putchar(':');
        	if((loc=='D')||(loc=='I'))
        		outbyte(index%0x100);
        	else
        		outword(index%0x10000);
        	putchar(':');
		}
		putchar(' ');

        if((loc=='D')||(loc=='I'))
        	j=Data[index%0x100];
        else
        	j=get_xdata(index%0x10000);
		outbyte(j);

		putchar('.');
		j=getbyte();
		if((!validbyte)&&(!keepediting)) break;
		if(validbyte)
		{
        	if((loc=='D')||(loc=='I'))
        		Data[index%0x100]=j;
        	else
        		set_xdata_to(index%0x10000, j);
		}
		putchar('\b');
		putchar('\b');

        if((loc=='D')||(loc=='I'))
        	j=Data[index%0x100];
        else
        	j=get_xdata(index%0x10000);
		outbyte(j);

		index++;
		k++;
		k&=7;
	}
	putchar('\n');
}

void Init_Registers (void)
{
	int j;
	
	for(j=0; j<0x100; j++) Sfr[j]=0;
	SP=0x07;
	PC=0;
	
	for(j=0; j<5; j++) int_level[j]=0;
	int_level_cur=0;
	interrupt_stall=0;
}

void run (void)
{
	int j;
	opcode=Code[PC];
	for(j=0; j<op[opcode].cycles; j++)
	{
		do_timer_0_1();
		do_timer_2();
	}
	interrupt_stall=0;
	op[opcode].do_ptr();
	if (interrupt_stall==0) check_interrupts();
	update_parity();
}

void show_registers (void)
{
	int j;
    unsigned char rbank;	// Registers

	rbank=(PSW>>3)&0x3;
	
	printf("\nPC=%04x A=%02x B=%02x DPH=%02x DPL=%02x SP=%02x PSW=%02x Bank=%d\n",
		PC, ACC, B, DPH, DPL, SP, PSW, rbank);

	for(j=0; j<8; j++)
	{
		printf("R%d=%02x  ", j, Data[(rbank*8)+j]);
	}
	printf("\n");
}

void Break_Set (unsigned int addr)
{
	addr&=0xffff;
	Breaks[addr/8]|=(0x01<<(addr%8));
}

void Break_Clr (unsigned int addr)
{
	addr&=0xffff;
	Breaks[addr/8]&=~(0x01<<(addr%8));
}

void Break_Clr_All (void)
{
	int j;
	for(j=0; j<0x10000/8; j++) Breaks[j]=0;
}

int Break_Check (unsigned int addr)
{
	addr&=0xffff;
	return (Breaks[addr/8]&(1<<(addr%8)))?1:0;
}

int main(int argc, char ** argv)
{
    int nRetCode= 0;
	unsigned char c;
	int j, k, addr;
    unsigned char rbank;
	char ch_buf[]="0123456789abcdef";
	char buff[1000];
	char par1[101], par2[101], par3[101];
	int numpars;
	int hasequ=0, hasdot=0;
	
    Init_Registers();
	Break_Clr_All();

    if(argc>1)
    {
		for(k=1; k<argc; k++)
		{
			if(argv[k][0]=='-')
			{
				switch(argv[k][1])
				{
					case 'o': // Serial output file
						strcpy(oname, &argv[k][2]);
					break;
					case 'r': // Timed run option
						run_on_start=atoi(&argv[k][2]);
						if(run_on_start<=0) run_on_start=5; // Default 5 second max
					break;
					case 'x':
						if(argv[k][2]=='s')
						{
							sscanf(&argv[k][3], "%x", &overlap_start);
							//overlap_start=atox(&argv[k][3]);
							if(overlap_end<=overlap_start) overlap_end=0xffff;
							printf("code & xdata overlap starts at %04x\n", overlap_start);
						}
						else if (argv[k][2]=='e')
						{
							overlap_end=atoi(&argv[k][3]);
						}
					break;

					case '?':
					case 'h':
						printf("\n8051 simulator\n");
						printf("By Jesus Calvino-Fraga\n");
						printf("\nAvailable options:\n");
						printf("'o[filename]': Serial port output file.\n");
						printf("'r[time]': Timed run interval (seconds).\n");
						printf("'xs[value]': XDATA / CODE overlap start.\n");
						printf("'xe[value]': XDATA / CODE overlap end.\n");
						printf("'?' 'h': This help.\n");
						printf("The default serial port can be access via telnet localhost:23\n");
						exit(0);
					break;

					default:
						printf("WARNING: Unknown option '%c'\n", argv[k][1]);
					break;
				}
			}
			else
			{
				strcpy(fname, argv[k]);
				j=ReadHexFile(fname, Code);
    			if(j<0)
    			{
					printf("ERROR: Could not open file %s\n", fname);
    				return 2;
    			}
				if(j==0)
				{
					printf("ERROR: File %s doesn't have any HEX records.\n", fname);
    				return 3;
				}
			}
		}
    }
    else
    {
    	printf("ERROR: S51 needs a hex file to proceed\n");
    	return 1;
    }
	
	if(run_on_start>0)
	{
		time_t ltime1, ltime2;

		if(oname[0]!=0)
		{
			sof=fopen(oname, "a");
			if(sof==NULL)
			{
				printf("ERROR: Could not create/open file %s\n", oname);
    			return 2;
			}
		}

		time(&ltime2);
		ltime1=ltime2+run_on_start;
		sjmp_intself=0;
		while(1)
		{
			run();
			if(sjmp_intself)
			{
				fclose(sof);
				return 0;
			}
			time(&ltime2);
			if(ltime2>=ltime1)
			{
				fprintf(sof, "\n\nWARNING: Simulation timeout after %d seconds.\n", run_on_start);
				fclose(sof);
				return 0;
			}
		}
	}

    _beginthread( ServerThread, 0, NULL );
    
    while(1)
    {
		update_parity();
    	printf ("S51>");
		buff[0]=0;
		gets(buff);
		for(j=0, hasequ=0, hasdot=0; buff[j]!=0; j++)
		{
			if(buff[j]=='=')
			{
				buff[j]=' ';
				hasequ=1;
			}
			if(buff[j]=='.')
			{
				buff[j]=' ';
				hasdot=1;
			}
		}
		par1[0]=0; par1[0]=0; par2[0]=0; 
		numpars=sscanf(buff, "%100s %100s %100s", par1, par2, par3);
 
		if ( (EQU(par1, "?")) || (EQU(par1, "HELP")) )
		{ 
 			printf( 
			"\nS51 commands:\n\n"
			"  H: Reload hex file\n"
			"  R: show registers\n"
			"  G: go, run program\n"
			"  K: reset program\n"
			"  S, STEP: step into instruction\n"
			"  T: trace program execution\n"
			"  BS add: set breakpoint at 'add'\n"
			"  BC add: clear breakpoint at 'add'\n"
			"  BRL: list breakpoints\n"
			"  BRC: clear all breakpoints\n"
			"  D add len: display 'len' bytes of DATA memory starting at 'add'\n"
			"  C add len: display 'len' bytes of CODE memory starting at 'add'\n"
			"  I add len: display 'len' bytes of IDATA memory starting at 'add'\n"
			"  X add len: display 'len' bytes of XDATA memory starting at 'add'\n"
			"  MD add: modify DATA memory at 'add'\n"
			"  MI add: modify IDATA memory at 'add'\n"
			"  MX add: modify XDATA memory at 'add'\n"
			"  FD add len value: set 'len' bytes of  DATA to 'value' starting at 'add'\n"
			"  FI add len value: set 'len' bytes of IDATA to 'value' starting at 'add'\n"
			"  FX add len value: set 'len' bytes of XDATA to 'value' starting at 'add'\n"
			"  U start end: dissasemble lines from 'start' to 'end'\n" 
			);
   		}
		else if (EQU(par1, "h"))
		{
			Init_Registers();
			if(numpars>1)
			{
				sprintf(fname, "%s.%s", par2, par3);
				printf("\rLoading file %s...", fname);
    			if(ReadHexFile(fname, Code)<0)
    			{
    				printf("File %s not found\n", fname);
    			}
				else 
				{
					Break_Clr_All();
					printf(" done.\n");
				}
			}
			else
			{
				printf("\rLoading file %s...", fname);
    			if(ReadHexFile(fname, Code)<0)
    			{
    				printf("File %s not found\n", fname);
    			}
				else
				{
					printf(" done.\n");
				}
			}
		}
		else if ( (EQU(par1, "k")) || (EQU(par1, "RESET")) )
		{
			printf("\rResetting... ", argv[1]);
    		Init_Registers();
			printf(" done.\n");
		}
		else if ( (EQU(par1, "s")) || (EQU(par1, "STEP")) ) // Single Step
		{
			printf("Press q to stop, any other key to step\n");
			while(1)
			{
				char c;
				
				disassemble (Code, PC, PC+1);
				run();
				c=_getch();
				if(tolower(c)=='q')
				{
					break;
				}
				else if (tolower(c)=='r')
				{
					show_registers();
				}
			}
		}
		else if ( (EQU(par1, "u")) || (EQU(par1, "DIS")) )
		{
			if(numpars>1)
			{
				sscanf(par2, "%x", &j);
			}
			else
			{
				j=PC;
			}
			j&=0xffff;

			if(numpars>2)
			{
				sscanf(par3, "%x", &k);
			}
			else
			{
				k=j+1;
			}
			k&=0xffff;

			disassemble (Code, j, k);
		}
		else if ( (EQU(par1, "r")) || (EQU(par1, "REG")) )
		{
			show_registers();
		}
		else if ( (EQU(par1, "d")) || (EQU(par1, "DATA")) )
		{
		    printf("\n");
		    for(j=0; j<0x80; j++)
		    {
		    	if((j&0x0f)==0) printf("%02x: ", j);
		    	printf("%02x ", Data[j]);
		    	if(Data[j]>=' ')
		    		ch_buf[j&0x0f]=Data[j];
		    	else
		    		ch_buf[j&0x0f]='.';
		    	if((j&0x0f)==0x07) printf("- ");
		    	if((j&0x0f)==0x0f) printf("   %s\n", ch_buf);
		    }
		}
		else if ( (EQU(par1, "c")) || (EQU(par1, "CODE")) )
		{
			int len;
			len=0x80;
			if(numpars==1)
			{
				printf("Start:");
				scanf("%x", &k);
			}
			else if(numpars==2)
			{
				sscanf(par2, "%x", &k);
			}
			else if(numpars==3)
			{
				sscanf(par3, "%x", &len);
			}
			k&=0xfff0;

		    for(j=k; j<(len+k); j++)
		    {
		    	if((j&0x0f)==0) printf("%04x: ", j);
		    	printf("%02x ", get_code(j));
		    	if(get_code(j)>=' ')
		    		ch_buf[j&0x0f]=get_code(j);
		    	else
		    		ch_buf[j&0x0f]='.';
		    	if((j&0x0f)==0x07) printf("- ");
		    	if((j&0x0f)==0x0f) printf("   %s\n", ch_buf);
		    }
		}
		    
		else if ( (EQU(par1, "x")) || (EQU(par1, "XDATA")) )
		{
			int len;
			len=0x80;
			if(numpars==1)
			{
				printf("\nStart:");
				scanf("%x", &k);
				k&=0xfff0;
			}
			else if(numpars==2)
			{
				sscanf(par2, "%x", &k);
			}
			else if(numpars==3)
			{
				sscanf(par3, "%x", &len);
			}

		    for(j=k; j<(len+k); j++)
		    {
		    	if((j&0x0f)==0) printf("%04x: ", j);
		    	printf("%02x ", get_xdata(j));
		    	if(get_xdata(j)>=' ')
		    		ch_buf[j&0x0f]=get_xdata(j);
		    	else
		    		ch_buf[j&0x0f]='.';
		    	if((j&0x0f)==0x07) printf("- ");
		    	if((j&0x0f)==0x0f) printf("   %s\n", ch_buf);
		    }
		}
		    
		else if ( (EQU(par1, "i")) || (EQU(par1, "IDATA")) )
		{
		    printf("\n");
		    for(j=0x80; j<0x100; j++)
		    {
		    	if((j&0x0f)==0) printf("%02x: ", j);
		    	printf("%02x ", Data[j]);
		    	if(Data[j]>=' ')
		    		ch_buf[j&0x0f]=Data[j];
		    	else
		    		ch_buf[j&0x0f]='.';
		    	if((j&0x0f)==0x07) printf("- ");
		    	if((j&0x0f)==0x0f) printf("   %s\n", ch_buf);
		    }
		}
		    
		else if ( (EQU(par1, "g")) || (EQU(par1, "GO")) )
		{
		    printf("\nRunning.  Press 'k' to reset. Press any other key to break.\n");
		    j=0;
			sjmp_intself=0;
		    while(1)
		    {
			    run();
				if(Break_Check(PC))
				{
					printf("Break point reached at address %04x\n", PC);
					break;
				}
				else if(sjmp_intself)
				{
					printf("sjmp $ with interrupts disabled detected.  Stoping simulation.\n");
					break;
				}
		    	j++;
		    	if(j==10000) //Only call kbhit() once in a while because it slows down the simulation
		    	{
			    	j=0;
				    if (kbhit())
				    {
				    	c=_getch();
				    	if(c=='k')
				    	{
				    		Init_Registers(); // Reset
				    	}
				    	else
				    	{
				    		break;
				    	}
				    }
			    }
		    }
		}
		else if (EQU(par1, "MD"))
		{
			if(numpars==1)
			{
				printf("\nStart:");
				scanf("%x", &k);
				k&=0xf0;
			}
			else
			{
				sscanf(par2, "%x", &k);
				k&=0xf0;
			}

			modifymem(k, 'D');
		}
		else if (EQU(par1, "MI"))
		{
			if(numpars==1)
			{
				printf("\nStart:");
				scanf("%x", &k);
				k&=0xf0;
			}
			else
			{
				sscanf(par2, "%x", &k);
				k&=0xf0;
			}
			modifymem(k, 'I');
		}
		else if (EQU(par1, "MX"))
		{
			if(numpars==1)
			{
				printf("\nStart:");
				scanf("%x", &k);
				k&=0xfff0;
			}
			else
			{
				sscanf(par2, "%x", &k);
				k&=0xfff0;
			}
			modifymem(k, 'X');
		}

		else if (EQU(par1, "BS")) // Break set
		{
			if(numpars==1)
			{
				printf("\nAddress:");
				scanf("%x", &k);
				k&=0xffff;
			}
			else
			{
				sscanf(par2, "%x", &k);
				k&=0xffff;
			}
			Break_Set(k);
		}

		else if (EQU(par1, "BC")) // Break clear
		{
			if(numpars==1)
			{
				printf("\nAddress:");
				scanf("%x", &k);
				k&=0xffff;
			}
			else
			{
				sscanf(par2, "%x", &k);
				k&=0xffff;
			}
			Break_Clr(k);
		}

		else if (EQU(par1, "BCA")) // Break clear all
		{
			Break_Clr_All();
		}

		else if (EQU(par1, "BL")) // Break list
		{
			for(k=0; k<0x10000; k++)
			{
				if(Break_Check(k))
				{
					printf("%04x\n", k);
				}
			}
		}

		else if ( (EQU(par1, "t")) || (EQU(par1, "TRACE")) )
		{
		    printf("\nRunning.  Press 'k' to reset. Press any other key to break.\n");
		    j=0;
		    while(1)
		    {
				addr=disassemble (Code, PC, PC+1)-PC;
			    run();
				if( op[opcode].nbytes != addr )
				{
					printf("Size mistmatch found. addr=%04x, PC=%04x\n", addr, PC);
					break;
				}
				rbank=(PSW>>3)&0x3;
				
		    	printf("\nPC=%04x A=%02x B=%02x DPH=%02x DPL=%02x SP=%02x PSW=%02x Bank=%d\n",
		    		PC, ACC, B, DPH, DPL, SP, PSW, rbank);

		    	for(k=0; k<8; k++)
		    	{
		    		printf("R%d=%02x  ", k, Data[(rbank*8)+k]);
		    	}
		    	printf("\n");

		    	j++;
		    	if(j==10) //Only call kbhit() once in a while because it slows down the simulation
		    	{
			    	j=0;
				    if (kbhit())
				    {
				    	c=_getch();
				    	if(c=='k')
				    	{
				    		Init_Registers(); // Reset
				    	}
				    	else
				    	{
				    		break;
				    	}
				    }
			    }
		    }
		}
			
		else if ( (EQU(par1, "q")) || (EQU(par1, "QUIT")) || (EQU(par1, "EXIT")))
		{
		    printf("\nBye!\n");
		    return nRetCode;
		}

		else if( strlen(par1)==0 )
		{
			printf("\r");
		}
		
		else
		{
			int nbit, val;

			// Check for SFR names
			for(j=0; j<0x80; j++)
			{
				if(EQU(par1, sfrn[j]))
				{
					//printf("%s is at %02x\n", par1, j+0x80);
					if(hasdot)
					{
						nbit=atoi(par2)&0x7;
						if(hasequ)
						{
							sscanf(par3, "%x", &val);
							if(val==1)
							{
								Sfr[j+0x80]|=(1<<nbit);
							}
							else if(val==0)
							{
								Sfr[j+0x80]&=~(1<<nbit);
							}
							else
							{
								printf("Invalid bit value\n");
							}
						}
						else
						{
							printf("%c\n", (Sfr[j+0x80]&(1<<nbit))?'1':'0' );
						}
					}
					else
					{
						if(hasequ)
						{
							sscanf(par2, "%x", &val);
							Sfr[j+0x80]=val;
						}
						else
						{
							printf("%02x\n", Sfr[j+0x80]);
						}
					}
					break;
				}
			}
			if(j==0x80)
			{
				for(j=0; j<0x80; j++)
				{
					if(EQU(par1, bitn[j]))
					{
						nbit=j&0x7;

						if(hasequ)
						{
							sscanf(par2, "%x", &val);
							if(val==1)
							{
								Sfr[(j&0xf8)+0x80]|=(1<<nbit);
							}
							else if(val==0)
							{
								Sfr[(j&0xf8)+0x80]&=~(1<<nbit);
							}
							else
							{
								printf("Invalid bit value\n");
							}
						}
						else
						{
							printf("%c\n", (Sfr[(j&0xf8)+0x80]&(1<<nbit))?'1':'0' );
						}
						break;
					}
				}
			}
			if(j==0x80) printf("What? (%s)\n", par1);
		}

		//purge input
		while (kbhit())	c=_getch();

    }
	
    return nRetCode;
}