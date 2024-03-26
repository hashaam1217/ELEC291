/*-------------------------------------------------------------------------
   scan_format.c - formatted input conversion

   CopyRight (c) - Jesus Calvino-Fraga (2011-2017)

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

#define BOOL bool

typedef char (*pfn_inputchar)(void);

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
#ifdef isspace
#undef isspace
#endif

#define toupper(c) ((c)&=0xDF)
#define tolower(c) ((c)|=0x20)
#define islower(c) ((unsigned char)c >= (unsigned char)'a' && (unsigned char)c <= (unsigned char)'z')
#define isdigit(c) ((unsigned char)c >= (unsigned char)'0' && (unsigned char)c <= (unsigned char)'9')
#define isspace(c) (((unsigned char)c == (unsigned char)' ') || ((unsigned char)c == (unsigned char)'\t'))

typedef union
{
    long int *     			lptr;
    int *          			iptr;
    float *        			fptr;
    char *         			cptr;
    unsigned long int *     ulptr;
    unsigned int *          uiptr;
    unsigned char *         ucptr;
} value_t;

typedef union
{
    long int l;
    unsigned long int ul;
    float f;
    char c;
} value_l;

char _tfis[16];

static pfn_inputchar input_char;
static value_t value;
static value_l rv;
static int charsInputted;
static int radix;
static int width;
static int assigned;
static int stopchar;

static BOOL   char_argument;
static BOOL   long_argument;
static BOOL   issigned;
static BOOL   input_EOF;
static BOOL   suppressed;
static BOOL   ischar;

static char _input_char( void )
{
	int c;
	c=input_char();
    if (c) charsInputted++;
	else input_EOF=1;
    return (c);
}

static void gets_tfis(void)
{
    int c;
    unsigned int count=0;
    
	if(input_EOF)
	{
		_tfis[0]=0;
		return;
	}

    while (1)
    {
        c=_input_char();
        switch(c)
        {
	        case '\b': // backspace
	            if (count)
	            {
	            	count--;
	            	charsInputted--;
	            }
	            break;
            case ' ':  case '\t': case '\n': case '\r': case 0:
            	if(count)
            	{
	            	_tfis[count]=0;
		            return;	
            	}
            	break;
	        default:
	        	if(c==0)
	        	{
	        		_tfis[count]=0;
	        		input_EOF=1;
	        		return;
	        	}
	        	else if (c==stopchar)
	        	{
	            	_tfis[count]=0;
		            return;	
	        	}
	        	if(count<(sizeof(_tfis)-1)) _tfis[count++]=c;
	            break;
        }
    }
}

static unsigned char char_to_val (char c)
{
	int j=127;

	if (c >= '0' && c <= '9') j=c-'0';
	else if (c >= 'A' && c <= 'F') j=c-'A'+10;
	else if (c >= 'a' && c <= 'f') j=c-'a'+10;
	
	if(j<radix)
		return j;
	else
		return 127;
}

static long int String_to_ULong(char * s)
{
    int j;
    rv.ul=0;

    /* find a valid digit for the radix, '+', or '-' */
    while (*s)
    {
    	j=*s;
    	if (char_to_val((char)j)<radix) break;
        s++;
    }

	while(1)
	{
		j=char_to_val(*s);
		if(j>radix) break;
		rv.ul = (rv.ul * radix); // By separating rv=rv*radix+j in to two lines, 4 bytes of ram are saved
		rv.ul += j;
		s++;
	}
    return (rv.ul);
}

static long int String_to_Long(char * s)
{
    BOOL sign = 0;
    int j;
    rv.l=0;

    /* find a valid digit for the radix, '+', or '-' */
    while (*s)
    {
    	j=*s;
    	if (char_to_val((char)j)<radix) break;
        if ((char)j == '-' || (char)j == '+') break;
        s++;
    }

    sign = (*s == '-');
    if (*s == '-' || *s == '+') s++;

	String_to_ULong(s);

    return (sign ? -rv.l : rv.l);
}

#ifdef SCANF_FLOAT
double atof2(const char * s)
{
    float value;
    int iexp_off=0;
    int iexp=0;
    BOOL sign, esign, dot_flag=0;

    //Skip leading blanks
    while (isspace(*s)) s++;

    //Get the sign
    if (*s == '-')
    {
        sign=1;
        s++;
    }
    else
    {
        sign=0;
        if (*s == '+') s++;
    }

    //Get the number

    for (value=0.0; isdigit(*s) || (*s == '.'); s++)
    {
    	if(*s == '.') 
    	{
    		dot_flag=1;
    	}
    	else
    	{
	        value=((float)10.0)*value;
	        value+=(*s-'0');
	        if(dot_flag) iexp_off++;
	    }
    }
        
    //Finally, the exponent
 
    if ( ((*s)=='E') || ((*s)=='e') )
    {
        s++;
	    //Get the exponent sign
	    if (*s == '-')
	    {
	        esign=1;
	        s++;
	    }
	    else
	    {
	        esign=0;
	        if (*s == '+') s++;
	    }

	    for (iexp=0; isdigit(*s); s++)
	    {
	        iexp=10*iexp;
	        iexp+=(*s-'0');
	    }
        if(esign) iexp*=-1;
  	}
 	
    iexp-=iexp_off;
    
    while(iexp!=0)
    {
        if(iexp<0)
        {
            value*=(float)0.1;
            iexp++;
        }
        else
        {
            value*=(float)10.0;
            iexp--;
        }
    }
    
    if(sign) value*=-1.0;
    return (value);
}
#endif

void uart_puts(const char *str);

int _scan_format (pfn_inputchar pfn, const char *format, va_list ap)
{
    int c;
        
    input_char = pfn;

    charsInputted = 0;
    assigned = 0;
    input_EOF = 0;

    while( c=*format++ )
    {
        if ( c=='%' )
        {
            issigned      = 1;
            char_argument = 0;
            radix         = 0;
            width         = 0;
            suppressed    = 0;
            ischar        = 0;

get_conversion_spec:

            c = *format++;
            stopchar = *format;

            if (isdigit(c))
            {
                width = 10*width + (c - '0');
                goto get_conversion_spec;
            }

            if (islower(c))
            {
                c = toupper(c);
            }

            switch( c )
            {
	            case 'B':
	                char_argument = 1;
	                goto get_conversion_spec;
	            case 'L':
	                long_argument = 1;
	                goto get_conversion_spec;
	            case '*':
	            	suppressed = 1;
	            case '%':
	                goto get_conversion_spec;
	                
	            case 'C':
	            	ischar=1;
	
	            case 'S':
	                if(suppressed==0) value.cptr=va_arg(ap, char *);
	                if(width==0) width=ischar?1:255;
	                #define chrcnt radix // Variable radix recycled as char counter.  Saves one byte of internal RAM...
	                chrcnt=0; 
	                while(1)
	                {
	                	if(chrcnt<width) c=_input_char();
	                	if(input_EOF && (chrcnt==0)) break;
	                	if (  (c==0) || ( ( (c==' ') || (c=='\t') || (c=='\r') || (c=='\n') ) && ischar==0) || (chrcnt==width) )
	                	{
	                		if(chrcnt!=0)
	                		{
	                			if(suppressed==0)
	                			{
			                		assigned++;
			                		*value.cptr=0;
		                		}
		                		chrcnt=0;
		                		break;
		                	}
	                	}
	                	else if (c=='\b')
	                	{
	                		if(chrcnt!=0)
	                		{
		                		if(suppressed==0) value.cptr--;
		                		chrcnt--;
	                		}
	                	}
	                	else
	                	{
	                		if(suppressed==0)
	                		{
		                		*value.cptr=c;
		                		value.cptr++;
	                		}
	                		chrcnt++;
	                	}
	                }
	                break;
	
	            //case 'P': // Don't know what to do with pointers yet...
	            //    break;
	
	            case 'U':
	            	issigned=0;
	            case 'D':
	            case 'I':
	                radix = 10;
	                break;
	
	            case 'O':
	            	issigned=0;
	                radix = 8;
	                break;
	
	            case 'X':
	            	issigned=0;
	                radix = 16;
	                break;

	            case 'F':
	            case 'E':
	            case 'G':
	                gets_tfis();
	                if( (_tfis[0]!=0) && (suppressed==0) )
	                {
	                    value.fptr=va_arg(ap, float *);
#ifdef SCANF_FLOAT	                    
		                *value.fptr=atof2(_tfis);
#endif
		                assigned++;
	                }
	                break;
	            
	            /*No input is consumed. The corresponding argument shall be a pointer to
				signed integer into which is to be written the number of characters read from
				the input stream so far by this call to the fscanf function. Execution of a
				%n directive does not increment the assignment count returned at the
				completion of execution of the fscanf function. No argument is converted,
				but one is consumed.*/    
	            case 'N':
	                value.iptr = va_arg(ap, int *);
	            	*value.iptr= charsInputted;
	            	break;
	                
	            default:
	                break;
            }
            
            if(radix)
            {
			    gets_tfis();
			    if( (_tfis[0]!=0) && (suppressed==0) )
                {
					value.lptr=va_arg(ap, long *); // Any pointer in the union will do!
					assigned++;
                
                	if(issigned)
                	{
						if (long_argument)
						{
						    *value.lptr=(long)String_to_Long(_tfis);
						}
						else if (char_argument)
						{
						    *value.cptr=(char)String_to_Long(_tfis);
						}
						else
						{
						    *value.iptr=(int)String_to_Long(_tfis);
						}
					}
					else
					{
						if (long_argument)
						{
						    *value.ulptr=(unsigned long)String_to_ULong(_tfis);
						}
						else if (char_argument)
						{
						    *value.ucptr=(unsigned char)String_to_ULong(_tfis);
						}
						else
						{
						    *value.uiptr=(unsigned int)String_to_ULong(_tfis);
						}
					}
				}
			}
        }
        
        if(input_EOF) 
        {
            while( c=*format++ )
		    {
		        if ( c=='%' )
		        {
		        	c=*format;
		        	if ( (c=='n') || (c=='N') )
		        	{
		                value.iptr = va_arg(ap, int *);
		            	*value.iptr= charsInputted;
		        	}
		        }
		    }
        }
    }
    return assigned;
}

const char *bufr;

static char get_char_from_string(void)
{
	char c;
    c = *bufr++ ;
    return c;
}

int vsscanf (const char *buf, const char *format, va_list ap)
{
    int i;
    bufr = buf;
    i = _scan_format( get_char_from_string, format, ap );
    return i;
}


int sscanf (const char *buf, const char *format, ...)
{
    va_list arg;
    int i;

    va_start (arg, format);
    bufr = buf;
    i = _scan_format(get_char_from_string, format, arg );
    va_end (arg);

    return i;
}

pfn_inputchar pfn_ic=NULL;

void set_stdin_to(pfn_inputchar pfn)
{
	pfn_ic=pfn;
}

int vscanf (const char *format, va_list ap)
{
	if(pfn_ic==NULL) return -1;
    return _scan_format( pfn_ic, format, ap );
}

int scanf (const char *format, ...)
{
    va_list arg;
    int i;

	if(pfn_ic==NULL) return -1;

    va_start (arg, format);
    i = _scan_format( pfn_ic, format, arg );
    va_end (arg);

    return i;
}

