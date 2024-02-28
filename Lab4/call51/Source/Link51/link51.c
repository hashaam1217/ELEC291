/*  link51.c: Call51 Linker/Locator

    Copyright (C) 2011-2012  Jesus Calvino-Fraga, jesusc (at) ece.ubc.ca
       
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

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#define _POSIX_
#include <limits.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#if defined(_MSC_VER)
#pragma warning (disable : 4996)
int _access( const char *path, int mode );
#endif

#if defined(_WIN64)
#pragma warning (disable : 4244)
#pragma warning (disable : 4267)
#endif

#if !defined(PATH_MAX) || (PATH_MAX < 2048)
#  undef  PATH_MAX
#  define PATH_MAX 2048         /* define a reasonable value */
#endif

#if !defined(_MAX_DRIVE)
#	define _MAX_DRIVE PATH_MAX
#endif

#if !defined(_MAX_DIR)
#	define _MAX_DIR PATH_MAX
#endif

#if !defined(_MAX_FNAME)
#	define _MAX_FNAME PATH_MAX
#endif

#if !defined(_MAX_EXT)
#	define _MAX_EXT PATH_MAX
#endif

#if !defined(_MAX_PATH)
#	define _MAX_PATH PATH_MAX
#endif

#define _makepath mymakepath
#define _splitpath mysplitpath

#if defined(_MSC_VER)
#define strcasecmp _stricmp
#define strncasecmp _strnicmp
#define vsnprintf _vsnprintf
#define snprintf _snprintf
#define access _access
#define unlink _unlink
#pragma warning (disable : 4996)
// Add _CRT_SECURE_NO_WARNINGS to the project instead of the pragma above
#endif

#define _makepath mymakepath
#define _splitpath mysplitpath

#define HASHTABSIZE	4999

struct symbol {
	char          *name;     // The symbol name using A51 rules.
	char          *filename; // File were the symbol is declared public.
	unsigned int  liboffset; // Zero if the symbol is public in an '.obj' file.  Otherwise, the offset of the module in the '.lib' file.
	unsigned int  used;      // How many times this symbol has been used.
	unsigned char flags;     // See constants below.
	unsigned char type;      // See constants below.
	unsigned long value;     // The numeric value after evaluating expressions.
	unsigned int  size;      // Size in bytes this symbol represents (for DSEG, ISEG, XSEG, BSEG, and segments).
	unsigned int  counter;   // The program counter for code segments.
	struct symbol *segment;  // The segment this symbol belongs to.  For segments, it points to previous branch of the base segment.
	struct symbol *next;     // The next symbol with the same hash value.
};

// The five default absolute segments.
struct symbol *abs_cseg;
struct symbol *abs_dseg;
struct symbol *abs_iseg;
struct symbol *abs_xseg;
struct symbol *abs_bseg;
struct symbol *current_cseg;

// Symbol types:
#define UNDEF	0
#define LABEL	1
#define CSEG    2
#define DSEG    3
#define ISEG    4
#define BSEG    5
#define XSEG    6
#define EQU     7
#define SET     8
#define MAC     9
#define RSEG   10

char Symbol_type_initial[]="ULCDIBXESMR"; //What a lucky coincidence there are note repeated letters!

// Symbol flags
#define PLAIN_SYM   0x00
#define PREDEFINED  0x01
#define CONSTANT    0x02
#define SEGMENT     0x04
#define RELOCATABLE 0x08
#define OVERLAYABLE 0x10
#define EXTERN_SYM  0x20
#define PUBLIC_SYM  0x40
#define BASE_SEG    0x80

#define EQ(A,B) !strcasecmp((A),(B))

#define MODULE       1
#define OPTC51       2
#define PRINTF_FLOAT 3
#define SEGMENTS     4
#define LOCALS       5
#define PUBLICS      6
#define EXTERNALS    7
#define CODE         8


char path_buffer[_MAX_PATH];
char ProgName[_MAX_PATH];
char drive[_MAX_DRIVE];
char dir[_MAX_DIR];
char fname[_MAX_FNAME];
char ext[_MAX_EXT];

char NewLibName[_MAX_PATH];
char ldrive[_MAX_DRIVE];
char ldir[_MAX_DIR];
char lfname[_MAX_FNAME];
char lext[_MAX_EXT];

char map_filename[_MAX_PATH]="";
char hex_filename[_MAX_PATH]="";
char lkr_filename[_MAX_PATH]="";

char optc51[0x1000]="";
int printf_float=0;

#define OPT_NONE     0
#define OPT_ADD_OBJ  1
#define OPT_EXT_OBJ  2
#define OPT_DEL_OBJ  3
#define OPT_ADD_LIST 4
#define OPT_DUMP_SYM 5
#define OPT_DUMP_MOD 6

char **ObjName=NULL;
int NumObjFiles=0;
char **LibName=NULL;
int NumLibFiles=0;
char **PathName=NULL;
int NumPathNames=0;

#define version "1.0"

int error_count=0; // Used to count the errors

int code_start=0x0000,  code_end=0x10000;  //Default is 64k
int xdata_start=0x0000, xdata_end=0x10000; //Default is 64k
int data_start=0x00,    data_end=0x80;     //The first 128 bytes of internal memory
int idata_start=0x00,   idata_end=0x100;   //All the internal memory
int bit_start=0x00,     bit_end=0x80;      //The 128 bit addresable variables in internal RAM

char chr='a';
char data_legend[0x2000]=
	"\nLegend:\n"
	"\t0: Register bank 0\n"
	"\t1: Register bank 1\n"
	"\t2: Register bank 2\n"
	"\t3: Register bank 3\n"
	"\tB: bits (see 'BIT map' below)\n"
;

#define GetLastChar(x) strchr(x, '\0')
#define NullTerminate(x) x[i] = '\0'

void mysplitpath(const char *path, char *drive, char *dir, char *fName, char *ext)
{
    char separator = '\\';

	char *endPoint = NULL,
	*pos = (char*) path,
	*temp = NULL,
	*lastChar = NULL;
	
	unsigned int i = 0,
	unixStyle = 0;
	
	/* initialize all the output strings in case we have to abort */
	if(drive) { strcpy(drive, ""); }
	if(dir) { strcpy(dir, ""); }
	if(fName) { strcpy(fName, ""); }
	if(ext) { strcpy(ext, ""); }

	/* find the end of the string */
	lastChar = GetLastChar(path);
	
	if(path[0] == '/')
	{
		separator = '/';
		unixStyle = 1;
	}
	else
	{
		separator = '\\';
	}

	/* first figure out whether it contains a drive name */
	endPoint = strchr(path, separator);
	
	/* unix style drives are of the form "/drivename/" */
	if(unixStyle)
	{
		endPoint = strchr(endPoint + 1, separator);
	}
	
	/* we found a drive name */
	if(endPoint && (endPoint < lastChar))
	{
		if(drive)
		{
			for(i = 0; pos + i < endPoint; i++)	drive[i] = pos[i];
			NullTerminate(drive); /* null terminate the the drive string */
		}

		pos = endPoint;
	}
	else if(unixStyle)
	{

		if(drive)
        {
        	for(i = 0; (pos + i) < lastChar; i++) drive[i] = pos[i];
			NullTerminate(drive);
		}

		return;
	}
	else /* this happens when there's no separators in the path name */
	{
		endPoint = pos;
	}

    /* next, find the directory name, if any */
    temp = pos;

    while(temp && (endPoint < lastChar) )
    {
        temp = strchr(endPoint + 1, separator);

        if(temp)
        {
            endPoint = temp;
        }
    }

    /* if true, it means there's an intermediate directory name */
    if( (endPoint) && (endPoint > pos) && (endPoint < lastChar))
    {
        if(dir)
        {
            for(i = 0; (pos + i) <= endPoint; i++)
                dir[i] = pos[i];

            NullTerminate(dir);
        }

        pos = ++endPoint;
    }
    else /* this happens when there's no separators in the path name */
    {
        endPoint = pos;
    }

    /* find the file name */
    temp = pos;

    while(temp && (endPoint < lastChar))
    {
        temp = strchr(endPoint + 1, '.');

        if(temp)
        {
            endPoint = temp;
        }
    }

    if( (endPoint > pos) && (endPoint < lastChar))
    {
        if(fName)
        {
            for(i = 0; pos + i < endPoint; i++)
                fName[i] = pos[i];

            NullTerminate(fName);
        }

        pos = endPoint;
    }
    else if(endPoint == pos)
    {
        /* in this case there is no extension */
        if(fName)
        {
            for(i = 0; (pos + i) < lastChar; i++)
                fName[i] = pos[i];

            fName[i] = '\0';
        }

        return;
    }

    /* the remaining characters just get dumped as the extension */
    if(ext)
    {
        for(i = 0; pos + i < lastChar; i++)
            ext[i] = pos[i];

        NullTerminate(ext);
    }

}

/* example of the kind of things you might have to deal with (though unlikely):
drive = "C:\"
dir = "\MyDocuments\"
fName = "budget"
ext = "doc" (not the need to add the dot)
*/

void mymakepath(char *path, const char *drive, const char *dir, const char *fName, const char *ext)
{
    char separator = '\\';
	char *lastChar = NULL;
	char *pos = NULL;
	
	unsigned int i = 0,
	unixStyle = 0,
	sepCount = 0; /* number of consecutive separators */
	
	
	if(!path)
	return;
	
	/* Initialize the path to nothing */
	strcpy(path, "");
	
	if(drive)
	{
		if(drive[0] == '/')
		{
			unixStyle = 1; separator = '/';
		}
	
		sepCount = 0;
		pos = (char*) drive;
		lastChar = GetLastChar(drive);
	
		if(lastChar == pos)
		goto directory;
	
		for(; pos < lastChar; pos++)
		{
			sepCount = ( (*pos) == separator ) ? sepCount + 1 : 0;
			
			/* filter out any extra separators */
			if(sepCount > 1) { continue; }
			
			path[i++] = (*pos);
		}
	
		if( (i) && path[i-1] != separator)
		path[i++] = separator;
	
		NullTerminate(path);
	}
	
	directory:
	
	if(dir)
	{
		sepCount = 0;
		pos = (char*) dir;
		lastChar = GetLastChar(dir);
		
		if(pos == lastChar)
		goto fileName;
	
		/* no character in the path yet? have to add that first separator */
		if(!i)	path[i++] = separator; sepCount++;
		
		/* getting rid of any extra separators */
		while( ((*pos) == separator) && (pos < lastChar) )	pos++;
	
		for( ; pos < lastChar; pos++)
		{
			sepCount = ( (*pos) == separator ) ? sepCount + 1 : 0;
			if(sepCount > 1) { continue; }
			path[i++] = (*pos);
		}
	
		if( (i) && path[i-1] != separator)
		path[i++] = separator;
	
		NullTerminate(path);
	}
	
	fileName:
	
	if(fName)
	{
		pos = (char*) fName;
		lastChar = GetLastChar(fName);
		
		if(lastChar == pos)
		goto extension;
		
		for(sepCount = 0; pos < lastChar; pos++)
		{
			sepCount = ( (*pos) == '.' ) ? sepCount + 1 : 0;
			if(sepCount > 1) { continue; }
			path[i++] = (*pos);
		}
		
		NullTerminate(path);
	}
	
	extension:
	
	if(ext)
	{
		sepCount = 0;
		pos = (char*) ext;
		lastChar = GetLastChar(ext);
		
		if(lastChar == pos)
		return;
		
		if(i && (path[i - 1] != '.'))
		{ path[i++] = '.'; sepCount++; }
		
		for(; pos < lastChar; pos++)
		{
			sepCount = ( (*pos) == '.' ) ? sepCount + 1 : 0;
			if(sepCount > 1) { continue; }
			path[i++] = (*pos);
		}
		
		NullTerminate(path);
	}
	else
	{
		lastChar = GetLastChar(path) - 1;
		
		/* backpedal until we get rid of all the dots b/c what's the use of a dot on an extensionless file? */
		while(lastChar > path)
	    {
	        if((*lastChar) != '.')
	            break;
	
	        (*lastChar) = '\0';
	        lastChar--;
	    }
	}
}

#undef GetLastChar
#undef NullTerminate


void print_error(const char *fmt, ...)
{
    va_list args;
    char buf[2048];

	error_count++;
    va_start(args, fmt);

    vsnprintf(buf, sizeof(buf), fmt, args);
    printf("LINK ERROR: %s\n", buf);
}

void print_test(const char *fmt, ...)
{
    va_list args;
    char buf[2048];

    va_start(args, fmt);

    vsnprintf(buf, sizeof(buf), fmt, args);
    printf("%s", buf);
}

void clean (char * s)
{
	int i, j;
	j=strlen(s);
	for(i=0; i<j; i++)
	{
		if (s[i]==',') s[i]=' ';
		if ( (s[i]=='\r') || (s[i]=='\n') )
		{
			s[i]=0;
			return;
		}
	}
}

int sort_compare( const void *str1, const void *str2 )
{
   // Compare strings
   return strcmp( *(char**) str1, *(char**) str2 );
}

void sort_strings(char *** Str_P, int * N_P)
{
	#define N (*N_P)
	#define Str (*Str_P)

	// Quick sort is much better than buble sort and it is part of the C library!
	qsort( (void *)Str, (size_t)N, sizeof(char *), sort_compare );
	
	#undef N
	#undef Str
}

void add_string(char *** Str_P, int * N_P, char * newstr)
{
	#define N (*N_P)
	#define Str (*Str_P)

	N++;
	Str = (char **) realloc (Str, N * sizeof (char *));
	if(Str==NULL)
	{
		print_error("Insufficient memory.\n");
		exit(2);
	}
	Str[N-1]=(char *)malloc(strlen(newstr)+1);
	if(Str[N-1]==NULL)
	{
		print_error("Insufficient memory.\n");
		exit(2);
	}
	else
	{
		strcpy(Str[N-1], newstr);
	}

	#undef N
	#undef Str
}

void free_strings(char *** Str_P, int * N_P)
{
	#define N (*N_P)
	#define Str (*Str_P)
	
	int i;

	for(i=0; i<N; i++)	free(Str[i]);
	free(Str);
	N=0;
	Str=NULL;
	
	#undef N
	#undef Str
}

void GetNameFromPath(char * path, char * name)
{
    int i, j;

    for(i=0; path[i]!=0; i++);
    for(; i>=0; i--)
    {
    	if((path[i]=='\\') || (path[i]=='/')) break;
    }
    for(j=0, i++; (path[i]!='.')&&(path[i]!=0); i++, j++) name[j]=path[i];
    name[j]=0;
}

void GetExtFromPath(char * path, char * ext)
{
    int i;

    for(i=0; path[i]!=0; i++);
    for(; i>=0; i--)
    {
    	if(path[i]=='.') break;
    }
	strcpy(ext, &path[i+1]);
	//Make it lowercase
	for(i=0; ext[i]!=0; i++) ext[i]=tolower(ext[i]);
}


void ChangeExtension(char * path, char * ext)
{
    int i;

    for(i=0; path[i]!=0; i++);
    for(; i>=0; i--)
    {
    	if( (path[i]=='.') || (path[i]=='\\') || (path[i]=='/') ) break;
    }
    if(i>=0)
    {
	    if(path[i]=='.')
	    {
	        path[i+1]=0;
	        strcat(path, ext);
	    }
	    else
	    {
	        print_error("Filename '%s' must have an extension\n", path);
	        exit(1);
	    }
    }
    else
    {
        print_error("Empty filename\n");
        exit(1);
    }
}

void CleanLine(char * buff)
{
    int j, l;
    l=strlen(buff);
    for(j=0; j<l; j++)
    {
        if((buff[j]=='\n')||(buff[j]=='\r')) buff[j]=0;
    }
}

int set_options (char * opt)
{
    int rvalue=0, unknown=0;
    static char Help[] =
    "Usage: %s [-option] f1.obj f2.obj ... fn.obj l1.lib l2.lib ... ln.lib\n\n"
    "Available options:\n\n"
    "  v                 - Displays program version.\n"
	"  code_start value  - Code segment start.\n"
	"  code_end value    - Code segment end.\n"
	"  xdata_start value - Xdata segment start.\n"
	"  xdata_end value   - Xdata segment end.\n"
 	"  data_start value  - Data segment start.\n"
	"  data_end value    - Data segment end.\n"
	"  idata_start value - Idata segment start.\n"
	"  idata_end value   - Idata segment end.\n"
	"  bit_start value   - Bit segment start.\n"
	"  bit_end value     - Bit segment end.\n"
	"  hex name          - Intel hex output file name.\n"
	"  map name          - Map file output file name.\n"
 	"  path name         - Search path for library files.\n"
    "  h,?               - This help.\n";

    switch (opt[0])
    {
        default:
            unknown=1;
        case 'h':
        case '?':
        case 'v':
            printf("%s: CALL51 linker, version %s\n", ProgName, version);
            printf("by Jesus Calvino-Fraga\n\n");
            if (unknown) printf("Unknown option: %c\n", opt[0]);
            if (opt[0]=='v') exit(0);
            printf(Help, ProgName);
            exit(1);
        break;
    }
    return (rvalue);
}

void GetLineInt (int argc, char **argv, int * j, int * val)
{
	if(++(*j)<argc)
	{
		sscanf(argv[*j], "%i", val);
	}
}

void GetLineStr (int argc, char **argv, int * j, char * s)
{
	if(++(*j)<argc)
	{
		sscanf(argv[*j], "%s", s);
	}
}

void ProcLineOptions (int argc, char **argv)
{
    int i, j, k;
	char ext[PATH_MAX];
	char tmpname[PATH_MAX+2]; // the +2 is for ">0" at the end of the object file
	FILE * f;
	char buffer[0x10*_MAX_PATH];
	char tag[0x20+_MAX_PATH];
	char val[0x20+_MAX_PATH];

    /*Get the program name*/
    GetNameFromPath(argv[0], ProgName);

	if(argc<2)
	{
		print_error("%s needs at least one file to link", argv[0]);
		exit(1);
	}

    for (j=1; j<argc; j++)
    {
        if(argv[j][0]=='-')
        {
			if(EQ(&argv[j][1], "code_start"))
				GetLineInt (argc, argv, &j, &code_start);
			else if(EQ(&argv[j][1], "code_end"))
				GetLineInt (argc, argv, &j, &code_end);
			else if(EQ(&argv[j][1], "xdata_start"))
				GetLineInt (argc, argv, &j, &xdata_start);
			else if(EQ(&argv[j][1], "xdata_end"))
				GetLineInt (argc, argv, &j, &xdata_end);
			else if(EQ(&argv[j][1], "data_start"))
				GetLineInt (argc, argv, &j, &data_start);
			else if(EQ(&argv[j][1], "data_end"))
				GetLineInt (argc, argv, &j, &data_end);
			else if(EQ(&argv[j][1], "idata_start"))
				GetLineInt (argc, argv, &j, &idata_start);
			else if(EQ(&argv[j][1], "idata_end"))
				GetLineInt (argc, argv, &j, &idata_end);
			else if(EQ(&argv[j][1], "bit_start"))
				GetLineInt (argc, argv, &j, &bit_start);
			else if(EQ(&argv[j][1], "bit_end"))
				GetLineInt (argc, argv, &j, &bit_end);
			else if(EQ(&argv[j][1], "hex"))
				GetLineStr (argc, argv, &j, hex_filename);
			else if(EQ(&argv[j][1], "map"))
				GetLineStr (argc, argv, &j, map_filename);
			else if(EQ(&argv[j][1], "path"))
				add_string(&PathName, &NumPathNames, argv[j]);
            else for(i=1; argv[j][i]!=0 ; i++)
                if (set_options(&argv[j][i])) break;
        }
        else
        {
			GetExtFromPath(argv[j], ext);
			if( (EQ(ext, "obj")) || (EQ(ext, "o")) )
			{
				if( (access( argv[j], 4 )) != -1 )  // 4: Read permission?
				{
					sprintf(tmpname,"%s>0", argv[j]);
					add_string(&ObjName, &NumObjFiles, tmpname);
				}
				else
				{
					print_error("Object file '%s' not found.\n", argv[j]);
					exit(5);
				}
			}
			else if( (EQ(ext, "lib")) || (EQ(ext, "l")) )
			{
				if( (access( argv[j], 4 )) != -1 )  // 4: Read permission?
				{
					add_string(&LibName, &NumLibFiles, argv[j]);
				}
				else
				{
					for(k=0; k<NumPathNames ; k++)
					{
						sprintf(buffer,"%s\\%s", PathName[k], argv[j]); //WARNING: Works for Windows only.
						if( (access( buffer, 4 )) != -1 )  // 4: Read permission?
						{
							add_string(&LibName, &NumLibFiles, buffer);
							break;
						}
					}
					if(k==NumPathNames)
					{
						print_error("Unable to find library file %s\n", argv[j]);
						exit(5);
					}
				}
			}
			else if( EQ(ext, "lkr") )
			{
				if( (access( argv[j], 4 )) != -1 ) // 4: Read permission?
				{
					strcpy(lkr_filename, argv[j]);
				}
				else
				{
					print_error("Unable to access script file '%s'\n", argv[j]);
					exit(5);
				}
			}
			else
			{
				print_error("Unknown type for file '%s'.\n", argv[j]);
				exit(4);
			}
        }
    }

	if(strlen(lkr_filename)>0)
	{
		//if( (access( lkr_filename, 0 )) != -1 ) printf( "File %s exists\n", lkr_filename );
 
		if ( (f=fopen(lkr_filename, "r")) == NULL )
		{
			print_error("can not open file `%s`", lkr_filename);
			exit(2);
		}

		while(fgets(buffer, sizeof(buffer), f)!=NULL)
		{
			if(buffer[0]!=';')
			{
				for(j=0; buffer[j]!=0; j++)
				{
					if (buffer[j]=='=') buffer[j]=' ';
					if ( (buffer[j]=='\r') || (buffer[j]=='\n') )
					{
						buffer[j]=0;
						break;
					}
				}
				//All the commands in the script file have the form tag=value
				tag[0]=0;
				sscanf(buffer, "%255s", tag); //Get the tag
				strcpy(val, &buffer[strlen(tag)+1]);
				//printf("tag=%s, value=%s\n", tag, val);

				if(strlen(val)>0)
				{
						 if(EQ(tag, "code_start"))  sscanf(val, "%i", &code_start);
					else if(EQ(tag, "code_end"))    sscanf(val, "%i", &code_end);
					else if(EQ(tag, "xdata_start")) sscanf(val, "%i", &xdata_start);
					else if(EQ(tag, "xdata_end"))   sscanf(val, "%i", &xdata_end);
					else if(EQ(tag, "data_start"))  sscanf(val, "%i", &data_start);
					else if(EQ(tag, "data_end"))    sscanf(val, "%i", &data_end);
					else if(EQ(tag, "idata_start")) sscanf(val, "%i", &idata_start);
					else if(EQ(tag, "idata_end"))   sscanf(val, "%i", &idata_end);
					else if(EQ(tag, "bit_start"))   sscanf(val, "%i", &bit_start);
					else if(EQ(tag, "bit_end"))     sscanf(val, "%i", &bit_end);
					else if(EQ(tag, "hex")) strcpy(hex_filename, val);
					else if(EQ(tag, "map")) strcpy(map_filename, val);
					else if(EQ(tag, "obj"))
					{
						if( (access( val, 4 )) != -1 )  // 4: Read permission?
						{
							strcat(val, ">0");
							add_string(&ObjName, &NumObjFiles, val);
						}
						else
						{
							print_error("Object file '%s' not found.\n", val);
							exit(5);
						}
					}
					else if(EQ(tag, "lib"))
					{
						if( (access( val, 4 )) != -1 )  // 4: Read permission?
						{
							add_string(&LibName, &NumLibFiles, val);
						}
						else
						{
							for(k=0; k<NumPathNames ; k++)
							{
								sprintf(buffer,"%s\\%s", PathName[k], val); //WARNING: Works for Windows only.
								if( (access( buffer, 4 )) != -1 )  // 4: Read permission?
								{
									add_string(&LibName, &NumLibFiles, buffer);
									break;
								}
							}
							if(k==NumPathNames)
							{
								print_error("Unable to find library file %s\n", val);
								exit(5);
							}
						}
					}
					else if(EQ(tag, "path")) add_string(&PathName, &NumPathNames, val);
					else
					{
						print_error("Unknown tag '%s' in file '%s'", tag, lkr_filename);
					}
				}
			}
		}
		fclose(f);
	}
}

void print_filename_strings (void)
{
	int j;

	printf("Object files:\n");
	for(j=0; j<NumObjFiles; j++)
	{
		printf("%s\n", ObjName[j]);
	}

	printf("Library files:\n");
	for(j=0; j<NumLibFiles; j++)
	{
		printf("%s\n", LibName[j]);
	}

	printf("Library search paths:\n");
	for(j=0; j<NumPathNames; j++)
	{
		printf("%s\n", PathName[j]);
	}

	printf(" code_start=%04X\n", code_start);
	printf("   code_end=%04X\n", code_end);
	printf("xdata_start=%04X\n", xdata_start);
	printf("  xdata_end=%04X\n", xdata_end);
	printf(" data_start=%02X\n", data_start);
	printf("   data_end=%02X\n", data_end);
	printf("idata_start=%02X\n", idata_start);
	printf("  idata_end=%02X\n", idata_end);
	printf("  bit_start=%02X\n", bit_start);
	printf("    bit_end=%02X\n", bit_end);
}


/* ----------------------------------------------------------------------
 * symtab, hash, looksym:
 *  User symbol table routines.
 *  symtab is the hash table for the symbols.
 *  (chaining is used for collision resolution).
 *
 */

static struct symbol *symtab[HASHTABSIZE];

int hash(char *s)
{
    char *p;
    unsigned int h=0, g;

    for (p=s; *p; p++)
	{
        //h = (h<<4) + toupper(*p); // Case insensitive
        h = (h<<4) + (*p); // Case sensitive
        if ( (g = h&0xf0000000) )
		{
            h = h ^ (g >> 24);
            h = h ^ g;
        }
    }
    return( h % HASHTABSIZE );
}

struct symbol *looksym(char *s)
{
    struct symbol *ptr, *prev;
    char *p;
    int hv;

    hv = hash(s);

    prev = NULL;
    for(ptr=symtab[hv]; ptr; ptr = ptr->next)
	{
        //if( !strcasecmp(ptr->name,s) ) // Case insensitive
        if( !strcmp(ptr->name,s) ) // Case sensitive
		{
            if( prev != NULL )
			{
                prev->next = ptr->next;
                ptr->next = symtab[hv];
                symtab[hv] = ptr;
            }
			ptr->used++;
            return(ptr);
        }
        prev = ptr;
    }

    if ( (p = malloc(strlen(s) + 1)) )
	{
        strcpy(p,s);
    }
	else
	{
        print_error("Cannot allocate %d bytes", strlen(s)+1);
		exit(-1);
    }

    ptr = (struct symbol *) malloc( sizeof(struct symbol) );
    if( ptr == NULL )
	{
        print_error("Cannot allocate %d bytes", sizeof(struct symbol));
		exit(-1);
	}

	ptr->name = p;
	ptr->filename = NULL;
	ptr->liboffset = 0;
    ptr->flags = 0;
    ptr->type = UNDEF;
    ptr->next = symtab[hv];
	ptr->used = 0;
	ptr->value = 0;
	ptr->size = 0;
	ptr->counter = 0;
	ptr->segment = NULL;
    symtab[hv] = ptr;
    return(ptr);
}

/* Clear all symbols */
void clearsym (void)
{
    /* clear all entries in the symbol table */
    memset(symtab, 0, sizeof(struct symbol *) * HASHTABSIZE);
}

/* free all the memory allocated for the symbols */

void freesym(void)
{
    struct symbol *sym, *next;
    int i;

    for (i=0; i<HASHTABSIZE; i++)
	{
        sym = symtab[i];
        while (sym != NULL)
		{
            if (sym->flags&PREDEFINED)
			{
                sym = sym->next;
            }
			else
			{
                if (sym->name) free(sym->name);
                next = sym->next;
                free(sym);
                sym = next;
            }
        }
    }
}

/*Create the five default absolute segments*/

void seginit (void)
{
	abs_cseg=looksym("CSEG");
	abs_cseg->filename=NULL;
	abs_cseg->liboffset=0;
    abs_cseg->type=CSEG;
    abs_cseg->value=0;
    abs_cseg->size=0;
    abs_cseg->counter=0;
	abs_cseg->flags=SEGMENT;

	abs_dseg=looksym("DSEG");
	abs_dseg->filename=NULL;
	abs_dseg->liboffset=0;
    abs_dseg->type=DSEG;
    abs_dseg->value=0;
    abs_dseg->size=0;
    abs_dseg->counter=0;
	abs_dseg->flags=SEGMENT;

	abs_iseg=looksym("ISEG");
	abs_iseg->filename=NULL;
	abs_iseg->liboffset=0;
    abs_iseg->type=ISEG;
    abs_iseg->value=0;
    abs_iseg->size=0;
    abs_iseg->counter=0;
	abs_iseg->flags=SEGMENT;

	abs_xseg=looksym("XSEG");
	abs_xseg->filename=NULL;
	abs_xseg->liboffset=0;
    abs_xseg->type=XSEG;
    abs_xseg->value=0;
    abs_xseg->size=0;
    abs_xseg->counter=0;
	abs_xseg->flags=SEGMENT;

	abs_bseg=looksym("BSEG");
	abs_bseg->filename=NULL;
	abs_bseg->liboffset=0;
    abs_bseg->type=BSEG;
    abs_bseg->value=0;
    abs_bseg->size=0;
    abs_bseg->counter=0;
	abs_bseg->flags=SEGMENT;
}

int symtype (char * s)
{
	if(EQ(s,"code"))  return CSEG;
	if(EQ(s,"data"))  return DSEG;
	if(EQ(s,"idata")) return ISEG;
	if(EQ(s,"bit"))   return BSEG;
	if(EQ(s,"xdata")) return XSEG;
	return UNDEF;
}

void reset_segment_counter (void)
{
    struct symbol *sym, *next;
    int i;

    for (i=0; i<HASHTABSIZE; i++)
	{
        sym = symtab[i];
        while (sym != NULL)
		{
			if(sym->flags&SEGMENT)
			{
				sym->counter=0;
			}
            next = sym->next;
            sym = next;
        }
    }
}

#define NOMASK       0x00
#define CODEMASK     0x02
#define XDATAMASK    0x04
#define CODEOVERLAP  0x20
#define XDATAOVERLAP 0x40
unsigned char memmask[0x10000];
unsigned char codeimage[0x10000];
unsigned char datamask[0x100]; //Used to allocate data, idata, and bit variables
unsigned char datamaskoverlap[0x100];
unsigned char bitmask[0x80]; // bit variables

int assign_code_space (int address, unsigned short int size)
{
	int i, j, toreturn;

	for(i=address; i<(address+size); i++)
	{
		j=i&0xffff;
		if(memmask[j]&CODEMASK) //Already assigned?
		{
			memmask[j]|=CODEOVERLAP;
			toreturn=1;
		}
		else
		{
			memmask[j]|=CODEMASK;
			toreturn=0;
		}
	}
	return toreturn;
}

int find_code_space (int size)
{
	int begin, i, k, cnt;

	for(i=code_start, begin=code_start, cnt=0; i<code_end; i++)
	{
		if(memmask[i]&CODEMASK) //Already assigned?
		{
			begin=i+1;
			cnt=0;
		}
		else
		{
			cnt++;
			if(cnt==size) // Found a chunk big enough!
			{
				for(k=begin; k<(begin+cnt); k++) memmask[k]|=CODEMASK;
				return begin;
			}
		}
	}
	return -1; // Couldn't find a chunk big enough
}


int assign_xdata_space (int address, unsigned short int size)
{
	int i, j, toreturn;

	for(i=address; i<(address+size); i++)
	{
		j=i&0xffff;
		if(memmask[j]&XDATAMASK) //Already assigned?
		{
			memmask[j]|=XDATAOVERLAP;
			toreturn=1;
		}
		else
		{
			memmask[j]|=XDATAMASK;
			toreturn=0;
		}
	}
	return toreturn;
}

int find_xdata_space (int size)
{
	int begin, i, k, cnt;

	for(i=xdata_start, begin=xdata_start, cnt=0; i<xdata_end; i++)
	{
		if(memmask[i]&XDATAMASK) //Already assigned?
		{
			begin=i+1;
			cnt=0;
		}
		else
		{
			cnt++;
			if(cnt==size) // Found a chunk big enough!
			{
				for(k=begin; k<(begin+cnt); k++) memmask[k]|=XDATAMASK;
				return begin;
			}
		}
	}
	return -1; // Couldn't find a chunk big enough
}

int find_data_space (int size, char * name)
{
	int begin, i, k, cnt;
	char buff[0x100];

	//printf("data_start=%02X, data_end=%02X\n", data_start, data_end);
	for(i=data_start, begin=data_start, cnt=0; i<data_end; i++)
	{
		if(datamask[i]!=0) //Already assigned?
		{
			begin=i+1;
			cnt=0;
		}
		else
		{
			cnt++;
			if(cnt==size) // Found a chunk big enough!
			{
				for(k=begin; k<(begin+cnt); k++) datamask[k]|=chr;
				sprintf(buff, "\t%c: %s\n", chr, name);
				strcat(data_legend, buff);
				chr++;
				return begin;
			}
		}
	}
	return -1; // Couldn't find a chunk big enough
}

int find_idata_space (int size, char * name)
{
	int begin, i, k, cnt;
	char buff[0x100];

	for(i=idata_start, begin=idata_start, cnt=0; i<idata_end; i++)
	{
		if(datamask[i]!=0) //Already assigned?
		{
			begin=i+1;
			cnt=0;
		}
		else
		{
			cnt++;
			if(cnt==size) // Found a chunk big enough!
			{
				for(k=begin; k<(begin+cnt); k++) datamask[k]|=chr;
				sprintf(buff, "\t%c: %s\n", chr, name);
				strcat(data_legend, buff);
				chr++;
				return begin;
			}
		}
	}
	return -1; // Couldn't find a chunk big enough
}

int find_bit_space (int size)
{
	int begin, i, k, cnt;

	/*for(i=bit_start; i<bit_end; i++)
	{
		if((i&0xf)==0) printf ("%02x: ", i);
		if(bitmask[i]!=0)
			printf("%c ", bitmask[i]);
		else 
			printf(". ", bitmask[i]);
		if((i&0xf)==0xf) printf ("\n");
	}*/
	for(i=bit_start, begin=bit_start, cnt=0; i<bit_end; i++)
	{
		if(bitmask[i]!=0) //Already assigned?
		{
			begin=i+1;
			cnt=0;
		}
		else
		{
			cnt++;
			if(cnt==size) // Found a chunk big enough!
			{
				for(k=begin; k<(begin+cnt); k++)
				{
					bitmask[k]='U'; // For now mark it as 'U' for used
					datamask[(k/8)+0x20]='B'; // Mark byte as used by bits
				}
				return begin;
			}
		}
	}
	return -1; // Couldn't find a chunk big enough
}

//For absolute segments, other than CODE, reserve the space.  For CODE, the space
//is reserved when the actual code is read after the <CODE ...> marker in the case for
//pass 1 below.
void set_usage_mask (char * modname, int memtype, int start, int size)
{
	int i;
	unsigned char dataloc;

	switch(memtype)
	{
		case CSEG: //Do nothing
		break;
		case DSEG:
		case ISEG:
			for(i=start; i<(start+size); i++)
			{
				if(datamask[i])
				{
					datamaskoverlap[i]=0xff;
				}
				else
				{
					datamask[i]='A';
				}
			}
		break;
		case BSEG:
			for(i=start; i<(start+size); i++)
			{
				if(i<128) // This needs some rework...
				{
					bitmask[i]='U';
					dataloc=(i/8)+0x20;
					
					if(datamask[dataloc])
					{
						datamaskoverlap[dataloc]=0xff;
					}
					else
					{
						datamask[dataloc]|='B';
					}
				}
				else
				{
					print_error("invalid bit location in module `%s`", modname);
				}
			}
		break;
		case XSEG:
			for(i=start; i<(start+size); i++)
			{
				if(memmask[i]&XDATAMASK)
				{
					memmask[i]|=XDATAOVERLAP;
				}
				else
				{
					memmask[i]|=XDATAMASK;
				}
			}
		break;
		default:
			print_error("invalid memory type in module `%s`", modname);
		break;
	}
}

int NewLabelSymbol (char * str, char * fname, int offset, int value, int size)
{
	struct symbol *sym;

	sym=looksym(str);

	if (sym->type == UNDEF)
	{
		sym->liboffset=offset;
		sym->value=value;
		sym->size=size;
		sym->filename=fname;
		sym->flags=PUBLIC_SYM;
		sym->used=0;
		sym->type = LABEL;
		return 0;
	}
	return 1;
}

void place_segments(void)
{
    struct symbol *base, *sym, *next;
    int i;
	unsigned long j;
	char buff[0x200];

	// Reserve all absolute symbols.  The CODE absolute symbols have been reserved already
    for (i=0; i<HASHTABSIZE; i++)
	{
		sym = symtab[i];
        while (sym != NULL)
		{
			if(sym->segment!=NULL)
			{
				if( (EQ(sym->segment->name, "DSEG")) || (EQ(sym->segment->name, "ISEG")) )
				{
					//printf("Found absolute DSEG symbol '%s' at address %02x with size %d\n", sym->name, sym->value, sym->size);
					for(j=sym->value; j<(sym->value+sym->size); j++) datamask[j]='A';
					if( (sym->value>=0x20) && (sym->value<0x30) )
					{
						for(j=(sym->value-0x20)*8; (j<(((sym->size+sym->value)-0x20)*8)) && (j<0x80) ; j++) bitmask[j]='A';
					}
				}
				if(EQ(sym->segment->name, "XSEG"))
				{
					for(j=sym->value; j<(sym->value+sym->size); j++) memmask[j]|=XDATAMASK;
				}
				if(EQ(sym->segment->name, "BSEG"))
				{
					for(j=sym->value; j<(sym->value+sym->size); j++) bitmask[j]='A';
				}
			}
			next = sym->next;
			sym = next;
		}
	}

	// Start with the BIT_BANK hack.  Must be in bit addressable memory.
    for (i=0; i<HASHTABSIZE; i++)
	{
        sym = symtab[i];
        while (sym != NULL)
		{
			if( (sym->flags&BASE_SEG) && (sym->flags&OVERLAYABLE) && (sym->type==DSEG))
			{
				if(strcmp(sym->name, "BIT_BANK")==0)
				{
					char saved_chr=chr;
					int saved_data_start=data_start;
					int saved_data_end=data_end;
					
					if(sym->size>0)
					{
						chr='K';
						data_start=0x20; // The begining of the bit addressable space
						data_end=0x30;

						sym->value=find_data_space(sym->size, sym->name); 

						if(sym->value==-1)
						{
							print_error("unable to allocate %d consecutive bytes(s) in DATA memory for segment %s", sym->size, sym->name);
						}

						for(j=(sym->value-0x20)*8; j<(sym->size*8); j++) bitmask[j]='U';

						chr=saved_chr;
						data_start=saved_data_start;
						data_end=saved_data_end;
					}
				}
			}
            next = sym->next;
            sym = next;
        }
    }

	// Allocate XDATA variables in R_PSEG first.  They must be in the first 256 bytes
	// of expanded memory.
    for (i=0; i<HASHTABSIZE; i++)
	{
        sym = symtab[i];
        while (sym != NULL)
		{
			if(sym->flags&BASE_SEG)
			{
				if (sym->type==XSEG)
				{
					if(EQ(sym->name,"R_PSEG"))
					{
						if(sym->size>256)
						{
							print_error("unable to allocate %d consecutive byte(s) in XDATA memory for segment %s.  Max is 256.", sym->size, sym->name);
						}
						else if(sym->size>0)
						{
							sym->value=find_xdata_space(sym->size);
							if(sym->value==-1)
							{
								print_error("unable to allocate %d consecutive byte(s) in XDATA memory for segment %s", sym->size, sym->name);
							}
						}
					}
				}
			}
            next = sym->next;
            sym = next;
		}
	}

	// For base segments, find a chunk of memory big enough and assign it.
	// Start with segments in CODE, XDATA, and BIT:
    for (i=0; i<HASHTABSIZE; i++)
	{
        sym = symtab[i];
        while (sym != NULL)
		{
			if(sym->flags&BASE_SEG)
			{
				sym->counter=0;
				if (sym->type==CSEG)
				{
					if(EQ(sym->name,"R_DINIT")) sym->size++; // A little hack needed to initialize C51 data variables

					if(sym->size>0)
					{
						sym->value=find_code_space(sym->size);
						if(sym->value==-1)
						{
							print_error("unable to allocate %d consecutive byte(s) in CODE memory for segment %s", sym->size, sym->name);
						}
					}

					if(EQ(sym->name,"R_DINIT"))
					{
						// Place a return at the end of the R_DINIT segment.  That way we can just call the code
						// stored in the segment, and the data initialization code for all modules will be executed
						// in one shot!
						sym->size--;
						codeimage[sym->value+sym->size]=0x22; // The opcode for the return instruction
						//Account for the extra byte as absolute code
						abs_cseg->size++;
					}
				}
				else if (sym->type==XSEG)
				{
					if(!EQ(sym->name,"R_PSEG"))
					{
						if(sym->size>0)
						{
							sym->value=find_xdata_space(sym->size);
							if(sym->value==-1)
							{
								print_error("unable to allocate %d consecutive byte(s) in XDATA memory for segment %s", sym->size, sym->name);
							}
						}
					}
				}
				else if (sym->type==BSEG)
				{
					if(sym->size>0)
					{
						sym->value=find_bit_space(sym->size);
						if(sym->value==-1)
						{
							print_error("unable to allocate %d consecutive bit(s) in BIT memory for segment %s", sym->size, sym->name);
						}
					}
				}
				else if (sym->type==DSEG) // Check for register bank reservation hack
				{
					if((strncmp(sym->name, "rbank", 5)==0) && (strlen(sym->name)==6) && (sym->flags&OVERLAYABLE))
					{
						if((sym->name[5]>='0') && (sym->name[5]<='3'))
						{
							sym->value=(sym->name[5]-'0')*8;
							sym->size=8;
							for(j=sym->value; j<(sym->value+8); j++) datamask[j]=sym->name[5];
						}
					}
				}
				
				if (sym->type!=DSEG) // For base segments in Data memory the segment symbols are created below
				{
					//Create two public symbols to programatically access the location and size of the segment:
					sprintf(buff, "_%s_start", sym->name);
					NewLabelSymbol(buff, NULL, 0, sym->value, 2);
					sprintf(buff,  "_%s_size", sym->name);
					NewLabelSymbol(buff, NULL, 0, sym->size, 2);
				}
			}
            next = sym->next;
            sym = next;
        }
    }

	// DATA segments need to be treated a bit differently.  First, only use the base segment for overlayable
	// segments.  For all other branch segments allocate space anywhere it can find it.  That will produce
	// a tightly packed data space.

	// First, place branch non-overlayable DATA segments
    for (i=0; i<HASHTABSIZE; i++)
	{
        sym = symtab[i];
        while (sym != NULL)
		{
			if( (sym->flags&RELOCATABLE) && ((sym->flags&BASE_SEG)==0) && ((sym->flags&OVERLAYABLE)==0) )
			{
				if (sym->type==DSEG)
				{
					sym->counter=0;
					if(sym->size>0)
					{
						int k;
						sym->value=find_data_space(sym->size, sym->name);
						if(sym->value==-1)
						{
							print_error("unable to allocate %d consecutive byte(s) in DATA memory for segment %s", sym->size, sym->name);
						}
						//Create two public symbols to programatically access the location and size of the segment:
						sprintf(buff, "_%s_start", sym->name);
						//Since this is not a base segment, we need to remove the ':' from the name
						for(k=0; buff[k]!=0; k++) if (buff[k]==':') buff[k]='_';
						NewLabelSymbol(buff, NULL, 0, sym->value, 2);
						sprintf(buff,  "_%s_size", sym->name);
						//Since this is not a base segment, we need to remove the ':' from the name
						for(k=0; buff[k]!=0; k++) if (buff[k]==':') buff[k]='_';
						NewLabelSymbol(buff, NULL, 0, sym->size, 2);
					}
				}
			}
            next = sym->next;
            sym = next;
        }
    }

	// Next, place base overlayable DATA segments
    for (i=0; i<HASHTABSIZE; i++)
	{
        sym = symtab[i];
        while (sym != NULL)
		{
			if( (sym->flags&BASE_SEG) && (sym->flags&OVERLAYABLE) )
			{
				
				if (sym->type==DSEG)
				{
					if( ( (strncmp(sym->name, "rbank", 5)==0) && (strlen(sym->name)==6) ) ||
						(strcmp(sym->name, "BIT_BANK")==0) )
					{
						// Do nothing for overlayable register bank reservation hacks.
					}
					else
					{
						sym->counter=0;
						if(sym->size>0)
						{
							sym->value=find_data_space(sym->size, sym->name);
							if(sym->value==-1)
							{
								print_error("unable to allocate %d consecutive byte(s) in DATA memory for segment %s", sym->size, sym->name);
							}
						}
						//Create two public symbols to programatically access the location and size of the segment:
						sprintf(buff, "_%s_start", sym->name);
						NewLabelSymbol(buff, NULL, 0, sym->value, 2);
						sprintf(buff,  "_%s_size", sym->name);
						NewLabelSymbol(buff, NULL, 0, sym->size, 2);
					}
				}
			}
            next = sym->next;
            sym = next;
        }
    }

	// Find space for base IDATA segments
    for (i=0; i<HASHTABSIZE; i++)
	{
        sym = symtab[i];
        while (sym != NULL)
		{
			if(sym->flags&BASE_SEG)
			{
				if (sym->type==ISEG)
				{
					sym->counter=0;
					if(sym->size>0)
					{
						sym->value=find_idata_space(sym->size, sym->name);
						if(sym->value==-1)
						{
							print_error("unable to allocate %d consecutive byte(s) in IDATA memory for segment %s", sym->size, sym->name);
						}
					}
					//Create two public symbols to programatically access the location and size of the segment:
					sprintf(buff, "_%s_start", sym->name);
					NewLabelSymbol(buff, NULL, 0, sym->value, 2);
					sprintf(buff,  "_%s_size", sym->name);
					NewLabelSymbol(buff, NULL, 0, sym->size, 2);
				}
			}
            next = sym->next;
            sym = next;
        }
    }

	// Finally find the remaining space in internal memory and save it as symbol _stack_start.
	for(j=0xff; j>0x07; j--)
	{
		if(datamask[j]!=0) break;
	}
	NewLabelSymbol("_stack_start", NULL, 0, j+1, 2);
	
	// Having found space for all the base segments, now assign part of that
	// space (as needed) to all its branch segments.
	for (i=0; i<HASHTABSIZE; i++)
	{
        base = symtab[i];
        while (base != NULL)
		{
			if( (base->flags&RELOCATABLE) && (base->flags&BASE_SEG) )
			{
				sym=base->segment; // Point to the last branch of this base segment
				while (sym != NULL)
				{
					// The base segment of this branch segment is stored in sym->segment
					if(sym->flags&OVERLAYABLE)
					{
						// Overlayable segments share the same space
						sym->value = base->value;
					}
					else if (base->type!=DSEG)
					{
						// Non-overlayable segments use adjacent space.
						// This doesn't apply for DSEG segments, where the assigments was done above.
						// Notice that space is asigned in reverse to preserve the order of apperance of
						// each branch segment.
						base->counter += sym->size;
						sym->value = base->value + ( base->size - base->counter );
						//printf("%20s 0x%04X 0x%04X\n", sym->name, sym->value, sym->size); // Test
					}
					// Get the previous branch in the linked list of this base
					next = sym->segment;
					sym = next;
				}
			}
            next = base->next;
            base = next;
        }
    }
}

// This function takes a string like "C:\mydir\myfile.lib>322", opens file "C:\mydir\myfile.lib" and
// sets the file pointer to 322.

FILE * OpenSeek (char * fname)
{
	int k, off;
	char str[0x1000];
	FILE * f;

	for(k=0; (fname[k]!=0) && (fname[k]!='>'); k++)
	{
		str[k]=fname[k];
	}
	str[k]=0;
	if (fname[k]=='>')
	{
		off=atoi(&fname[k+1]);
	}
	else
	{
		off=0;
	}

	if ( (f=fopen(str, "r")) == NULL )
	{
		print_error("can not open file `%s`", str);
		exit(2);
	}

	fseek(f, off, SEEK_SET);    // seek from the beginning of the file to given offset

	return f;
}

void Get_Modname_From_File (char * fname, char * s)
{
	FILE * f;
	char buffer[0x100];

	f=OpenSeek(fname);
	strcpy(s, "NOT_FOUND");

	while(fgets(buffer, sizeof(buffer), f)!=NULL)
	{
		clean(buffer);
		if(EQ(buffer, "<MODULE>"))
		{
			fgets(buffer, sizeof(buffer), f);
			s[0]=0;
			sscanf(buffer, "%255s", s);
			fclose(f);
			return;
		}
		else if(EQ(buffer, "</MODULE>"))
		{
			fclose(f);
			return;
		}
	}
	fclose(f);
}

// The first task is to load all the object modules and required library modules
// so that all the external symbols are resolved.
void resolve_externals (void)
{
	int i, j, k;
	char buffer[0x1000];
	char new_module_name[_MAX_FNAME+0x20];
	char tmpname1[_MAX_FNAME+0x20];
	char tmpname2[_MAX_FNAME+0x20];
	FILE * f1;
	int inpublic=0, inexternal=0, insegment=0;
	char str[5][0x100];
	int val1, val2;
	struct symbol *sym;
	unsigned int module_offset, index_offset;

	NewLabelSymbol("_stack_start", NULL, 0, 7, 1); // Value will be determined after pass 1

	// First load the public symbols from the object files 
	for(j=0; j<NumObjFiles; j++)
	{
		f1=OpenSeek(ObjName[j]);
		inpublic=0;
    
		while(fgets(buffer, sizeof(buffer), f1)!=NULL)
		{
			clean(buffer);
    		if(EQ(buffer, "<PUBLICS>")) inpublic=1;
			else if (EQ(buffer, "</PUBLICS>"))
			{
				inpublic=0;
				break; // We don't need to read the rest of the file
			}
    		else if (EQ(buffer, "<SEGMENTS>"))  insegment=1;
			else if (EQ(buffer, "</SEGMENTS>")) insegment=0;
    		else if (EQ(buffer, "<PRINTF_FLOAT>"))  printf_float=1;
			else
			{
				if(inpublic==1)
				{
					str[0][0]=0; str[1][0]=0;
					sscanf(buffer, "%255s%255s%X%X", str[0], str[1], &val1, &val2);
					if(NewLabelSymbol(str[0], ObjName[j], 0, val1, val2))
					{
						sym=looksym(str[0]);
						strcpy(tmpname1, ObjName[j]);
						for(i=0; tmpname1[i]!=0; i++)
						{
							if (tmpname1[i]=='>')
							{
								tmpname1[i]=0;
								break;
							}
						}
						strcpy(tmpname2, sym->filename);
						for(i=0; tmpname2[i]!=0; i++)
						{
							if (tmpname2[i]=='>')
							{
								tmpname2[i]=0;
								break;
							}
						}
						print_error("duplicated public symbol '%s' in object files '%s' and '%s'\n",
							         str[0],tmpname1, tmpname2);
					}
				}
				else if (insegment==1)
				{
					//Create a couple of public symbols to store the location and size of the segment
					str[0][0]=0; str[1][0]=0;
					sscanf(buffer, "%255s%255s%X%255s", str[0], str[1], &val1, str[2]); // name, type, size, overlayable?
					sprintf(str[3], "_%s_start", str[0]);
					NewLabelSymbol(str[3], NULL, 0, 0, 1);
					sprintf(str[4], "_%s_size" , str[0]);
					NewLabelSymbol(str[4], NULL, 0, 0, 1);
				}
			}
		}
		fclose(f1);
	}

	// Second, load all the public symbols from the lib files
	for(j=0; j<NumLibFiles; j++)
	{
		//printf("Scanning library %s\n", LibName[j]);
		if(printf_float) // Want to print floats with printf()?
		{
			_splitpath(LibName[j], ldrive, ldir, lfname, lext);
			if(strcmp(lfname, "libc51")==0)
			{
				strcat(lfname, "f");
				_makepath( NewLibName, ldrive, ldir, lfname, lext );
				realloc (LibName[j], strlen(NewLibName)+1 );
				strcpy(LibName[j], NewLibName);
				//printf("Linking libc51f.lib instead of libc51.lib\n");
			}
		}

		if ( (f1=fopen(LibName[j], "r")) == NULL )
		{
			print_error("can not open file `%s`", LibName[j]);
			exit(2);
		}

		inpublic=0;
    
		while(fgets(buffer, sizeof(buffer), f1)!=NULL)
		{
			clean(buffer);
    		if(EQ(buffer, "<MODULE>"))
			{
				inpublic=1;
				fgets(buffer, sizeof(buffer), f1);
				str[0][0]=0;
				sscanf(buffer, "%255s%d", str[0], &module_offset);
			}
			else if (EQ(buffer, "</MODULE>"))
			{
				inpublic=0;
			}
			else if (EQ(buffer, "<INDEX>"))
			{
				fgets(buffer, sizeof(buffer), f1);
				sscanf(buffer, "%d", &index_offset);
			}
			else if (EQ(buffer, "</INDEX>"))
			{
				break; // No more public symbols in this library
			}
			else if (EQ(buffer, "<SEGMENTS>")) insegment=1;
			else if (EQ(buffer, "</SEGMENTS>")) insegment=0;
			else
			{
				if(inpublic==1)
				{
					str[0][0]=0; str[1][0]=0;
					sscanf(buffer, "%255s%255s%X%X", str[0], str[1], &val1, &val2);
					if(NewLabelSymbol(str[0], LibName[j], module_offset+index_offset, val1, val2))
					{
						sym=looksym(str[0]);
						if(sym->liboffset!=0)
						{
							print_error("duplicated public symbol '%s' in libraries '%s' and '%s'\n",
										 str[0], LibName[j], sym->filename);
						}
					}
				}
				else if (insegment==1)
				{
					//Create a couple of public symbols to store the location and size of the segment
					str[0][0]=0; str[1][0]=0;
					sscanf(buffer, "%255s%255s%X%255s", str[0], str[1], &val1, str[2]); // name, type, size, overlayable?
					sprintf(str[3], "_%s_start", str[0]);
					NewLabelSymbol(str[3], NULL, 0, 0, 1);
					sprintf(str[4], "_%s_size" , str[0]);
					NewLabelSymbol(str[4], NULL, 0, 0, 1);
				}
			}
		}
		fclose(f1);
	}

	// Third, Check the external symbols of each object file, both the ones provided by the user and those
	// in the library files.  The library modules are also added here to the end of the list.

	for(j=0; j<NumObjFiles; j++)
	{
		f1=OpenSeek(ObjName[j]);
		inexternal=0;
    
		while(fgets(buffer, sizeof(buffer), f1)!=NULL)
		{
			clean(buffer);
    		if(EQ(buffer, "<EXTERNALS>")) inexternal=1;
			else if (EQ(buffer, "</EXTERNALS>"))
			{
				inexternal=0;
				break; // We don't need to read the rest of the file
			}
			else
			{
				if(inexternal==1)
				{
					str[0][0]=0; str[1][0]=0;
					sscanf(buffer, "%255s%255s%X%X", str[0], str[1], &val1, &val2);
					sym=looksym(str[0]);
					if (sym->flags != PUBLIC_SYM)
					{
						char modname[0x200];
						char fname[_MAX_PATH];
						int k;
						Get_Modname_From_File (ObjName[j], modname);
						strcpy(fname, ObjName[j]);
						for(k=0; fname[k]!=0; k++)
						{
							if(fname[k]=='>')
							{
								fname[k]=0;
								break;
							}
						}
						print_error("unresolved external symbol '%s' in module '%s' of file '%s'\n", str[0], modname, fname);
					}
					else // The symbol is public in at least one module!
					{
						// Check if the symbol is public in a library
						if((sym->liboffset!=0) && (sym->filename!=NULL))
						{
							//Create the new module name
							sprintf(new_module_name, "%s>%d", sym->filename, sym->liboffset);
							// Check if the library object name is a duplicate...
							{
								Get_Modname_From_File(new_module_name, tmpname1);

								for(k=0; k<NumObjFiles; k++)
								{
									if(strstr(ObjName[k], ">0")!=NULL) // Only object files have this
									{
										Get_Modname_From_File(ObjName[k], tmpname2);
										if(EQ(tmpname1, tmpname2))
										{
											print_error("duplicated module name '%s'.", tmpname1);
										}
									}
								}
							}
							//Check if the new library module name is already in the list of object files
							for(k=0; k<NumObjFiles; k++)
							{
								if(EQ(ObjName[k], new_module_name)) break;
							}
							if(k==NumObjFiles) // Add library "name>offset" to the end of the list
							{
								add_string(&ObjName, &NumObjFiles, new_module_name);
							}
						}
					}
				}
			}
		}
		fclose(f1);
	}

	// Get rid of all the symbols.  They will be properly reloaded in pass 1.
	freesym();
	clearsym();

	if(error_count!=0)
	{
		unlink(map_filename);
		unlink(hex_filename);
		exit(3); // If errors are found at this stage we must stop.
	}
}

int do_obj_pass1 (char * fname)
{
	int k, n;
	char modname[0x100];
	FILE * f1;
	char buffer[0x4000];
	char str[5][0x100];
	int val1, val2;
	int state=0;
	struct symbol *seg;
	struct symbol *base_seg;
	struct symbol *sym;

	//printf("Linking %s\n", fname);
	f1=OpenSeek(fname);
    
    while(fgets(buffer, sizeof(buffer), f1)!=NULL)
    {
    	clean(buffer);
    	     if(EQ(buffer, "<MODULE>"))       state=MODULE;
    	else if(EQ(buffer, "<OPTC51>"))       state=OPTC51;
    	else if(EQ(buffer, "<PRINTF_FLOAT>")) state=PRINTF_FLOAT;
    	else if(EQ(buffer, "<SEGMENTS>"))     state=SEGMENTS;
    	else if(EQ(buffer, "<LOCALS>"))       state=LOCALS;
    	else if(EQ(buffer, "<PUBLICS>"))      state=PUBLICS;
    	else if(EQ(buffer, "<EXTERNALS>"))    state=EXTERNALS;
    	else if(strncmp(buffer, "<CODE", 5)==0)
		{
			for(k=0; buffer[k]!=0; k++)
			{
				if(buffer[k]=='<') buffer[k]=' ';
				if(buffer[k]=='>') buffer[k]=' ';
			}
 			n=sscanf(buffer, "%255s%255s%X", str[0], str[1], &val1);
			if((EQ(str[1], "AT")) && (n==3))
			{
				//print_test("Absolute code at %04X\n", val1);
				current_cseg=abs_cseg;
				abs_cseg->value=val1;
				abs_cseg->counter=0; //Start over!
			}
			else
			{
				//print_test("Relocatable code segment '%s'\n", str[1]);
				seg=looksym(str[1]);
				
				sprintf(str[3], "%s:%s", modname, str[1]);
				seg=looksym(str[3]);

				if( (seg->flags&SEGMENT) != SEGMENT)
				{
					print_error("segment '%s' is undefined", str[3]);
				}
				else
				{
					current_cseg=seg;
				}
			}
			state=CODE;
		}
    	else if(EQ(buffer, "</MODULE>"))       state=0;
    	else if(EQ(buffer, "</OPTC51>"))       state=0;
    	else if(EQ(buffer, "</PRINTF_FLOAT>")) state=0;
    	else if(EQ(buffer, "</SEGMENTS>"))     state=0;
    	else if(EQ(buffer, "</LOCALS>"))       state=0;
    	else if(EQ(buffer, "</PUBLICS>"))      state=0;
    	else if(EQ(buffer, "</EXTERNALS>"))    state=0;
    	else if(EQ(buffer, "</CODE>"))	       state=0;
    	else if(EQ(buffer, "</FILE>"))
		{
			state=0;
			break; // Done reading file from library.  Get out.
		}
    	
    	else switch(state)
    	{
    		case MODULE:
 				strcpy(modname, buffer);
				//print_test("Module name: %s\n", modname);    			
    		break;

			case OPTC51:
				if(strlen(optc51)==0)
				{
					strncpy(optc51, buffer, sizeof(optc51)-1);
				}
				else
				{
					if(strcmp(optc51, buffer))
					{
						//Incompatible c51 options for the files to be linked
						print_error("link options are '%s' but module '%s' has '%s'", optc51, modname, buffer);
					}
				}
			break;

			case PRINTF_FLOAT:
				printf_float=1; // proccesed in resolve_externals(), but here for completness
			break;
    		
			case SEGMENTS:
				str[0][0]=0; str[1][0]=0; str[2][0]=0;
 				sscanf(buffer, "%255s%255s%X%255s", str[0], str[1], &val1, str[2]); // name, type, size, overlayable?
				//name-mangle the segment name so it belongs to this module
				sprintf(str[3], "%s:%s", modname, str[0]);
				seg=looksym(str[3]);
				if (seg->type == UNDEF)
				{
					seg->type=symtype(str[1]);
					seg->value=0;
					seg->flags=SEGMENT | RELOCATABLE;
					seg->size=val1;
					seg->used=0;
					seg->segment=NULL;
					seg->counter=0;
					if(EQ(str[2], "OV")) seg->flags|=OVERLAYABLE;
				}
				else
				{
					if(seg->type!=symtype(str[1]))
					{
						print_error("redefinition of segment '%s' with different data type '%s'", str[0], str[1]);
					}
					else if ( (seg->flags!=(SEGMENT | RELOCATABLE)) || (seg->flags!=(SEGMENT | OVERLAYABLE)) )
					{
						print_error("segment name '%s' is already defined.", str[3]);
					}
				}

				//Check the base segment
				base_seg=looksym(str[0]);
				if (base_seg->type == UNDEF)
				{
					base_seg->type=seg->type;
					base_seg->value=seg->value;
					base_seg->flags=seg->flags | BASE_SEG;
					base_seg->size=seg->size;
					base_seg->used=0;
					base_seg->segment=NULL;
					base_seg->counter=0;
				}
				else
				{
					if(seg->flags&OVERLAYABLE)
					{
						// For overlayable segments, the base segment size will be the
						// branch with the biggest size.
						if(seg->size > base_seg->size) base_seg->size=seg->size;
					}
					else
					{
						// For non-overlayable segments, the base segment size is the sum of
						// all the branch segments.
						base_seg->size+=seg->size;
					}
				}
				// Link list of segments that belong to the same base.
				seg->segment=base_seg->segment;
				base_seg->segment=seg;

				//print_test("%s,%s\n", str[0], str[1]);    			
    		break;
    		
			case LOCALS:
				str[0][0]=0; str[1][0]=0;
				sscanf(buffer, "%255s%255s%X%X", str[0], str[1], &val1, &val2);
				sprintf(str[2], "%s:%s", modname, str[0]);

				if( EQ(str[1], "CSEG") || EQ(str[1], "DSEG") || EQ(str[1], "XSEG") || EQ(str[1], "ISEG") || EQ(str[1], "BSEG"))
				{
					sprintf(str[3], "%s", str[1]);  // Symbol belongs to abasolute segment
				}
				else
				{
					sprintf(str[3], "%s:%s", modname, str[1]);
				}

				seg=looksym(str[3]);
				if( (seg->flags&SEGMENT) != SEGMENT)
				{
					print_error("segment '%s' is undefined", str[3]);
				}
				sym=looksym(str[2]);
				if(sym->type != UNDEF)
				{
					print_error("local symbol '%s' is already defined", str[2]);
				}
				else
				{
					sym->type=seg->type;
					sym->value=val1;
					sym->flags=PLAIN_SYM;
					sym->size=val2;
					sym->used=0;
					sym->segment=seg;
					
					if((seg->flags&RELOCATABLE)==0) //Absolute segment?
					{
						//For absolute segments, other than CODE, reserve the space
						set_usage_mask(modname, seg->type, val1, val2);
					}
				}
				//print_test("%s,%s,%04X,%04X\n", str[2], str[1], val1, val2);    			
    		break;
    		
			case PUBLICS:
				str[0][0]=0; str[1][0]=0;
				sscanf(buffer, "%255s%255s%X%X", str[0], str[1], &val1, &val2);
				if( EQ(str[1], "CSEG") || EQ(str[1], "DSEG") || EQ(str[1], "XSEG") || EQ(str[1], "ISEG") || EQ(str[1], "BSEG"))
				{
					sprintf(str[3], "%s", str[1]);  // Symbol belongs to abasolute segment
				}
				else
				{
					sprintf(str[3], "%s:%s", modname, str[1]);
				}
				seg=looksym(str[3]);
				if( (seg->flags&SEGMENT) != SEGMENT)
				{
					print_error("segment '%s' is undefined", str[3]);
				}
				sym=looksym(str[0]);
				if ( (sym->type == UNDEF) )
				{
					sym->type=seg->type;
					sym->value=val1;
					sym->flags=PUBLIC_SYM;
					sym->size=val2;
					sym->used=0;
					sym->segment=seg;

					if((seg->flags&RELOCATABLE)==0) //Absolute segment?
					{
						//For absolute segments, other than CODE, reserve the space
						set_usage_mask(modname, seg->type, val1, val2);
					}
				}
				else
				{
					print_error("public symbol '%s' is already defined", str[0]);
				}
				//print_test("%s,%s,%04X,%04X\n", str[0], str[1], val1, val2);    			
    		break;
    		
			case EXTERNALS: //Ignore externals in first pass
    		break;
    		
			case CODE:
				{
					char lstr[0x200];
					char fstr[0x20];
					char * s;
					int pos, n;

					s=buffer;
					sprintf(fstr,"%%%ds%%n", sizeof(lstr)-1); // fstr="%511s%n" if lstr[0x200]
	   				while(1)
    				{
						lstr[0]=0;
						n=sscanf(s, fstr, lstr, &pos);
						if(n<1) break; // Note that sscanf returns EOF (likely -1) if end-of-string is encountered in the first attempt to read a character
						s+=pos;

						if(strlen(lstr)>2)
						{
							int i;
							char accesstype[0x100], rpnexp[0x100];
				
							for(i=0; lstr[i]!=0; i++)
							{
								if( (lstr[i]=='(') || (lstr[i]==')') ) lstr[i]=' ';
							}
							accesstype[0]=0; rpnexp[0]=0;
							sscanf(lstr, "%255s%255s", accesstype, rpnexp);
							//print_test("%04x: %s(%s)\n", current_cseg->value+current_cseg->size, accesstype, rpnexp);
							
							if(strstr(accesstype, "16"))
							{
								if((current_cseg->flags&RELOCATABLE)==0) //Absolute code segment?
								{
									assign_code_space(current_cseg->value+current_cseg->counter, 2); //Reserve space
									//Also, find the total size of the absolute code segment
									current_cseg->size+=2;
								}
								current_cseg->counter+=2;
							}
							else
							{
								if((current_cseg->flags&RELOCATABLE)==0) //Absolute code segment?
								{
									assign_code_space(current_cseg->value+current_cseg->counter, 1); //Reserve space
									current_cseg->size++;
								}
								current_cseg->counter++;
							}
						}
						else
						{
							sscanf(lstr, "%X", &val1);
    						//print_test("%04x: %02X\n", current_cseg->value+current_cseg->counter, val1);
							if((current_cseg->flags&RELOCATABLE)==0) //Absolute code segment?
							{
								assign_code_space(current_cseg->value+current_cseg->counter, 1); //Reserve space
								current_cseg->size++;
							}
							current_cseg->counter++;
						}
    				}
				}
    		break;
    		default:
    			state=0;
    		break;
    	}
    }
    fclose(f1);
	return 0;
}

int Solve_RPN(char * rpnexp, char * modname)
{
	char token[0x100], varnamelocal[0x200];
	int i, j, k;
	#define STAKSIZE 0x10
	int rpnstack [STAKSIZE];
	//For these two macros, memmove() can be used instead
	#define PUSH(VAL) { for(i=STAKSIZE-1; i>0; i--) rpnstack[i]=rpnstack[i-1]; rpnstack[0]=VAL; }
	#define POP(VAL)  { VAL=rpnstack[0]; for(i=0; i<STAKSIZE-1; i++) rpnstack[i]=rpnstack[i+1]; }
	int op1, op2 ;
	struct symbol *sym;

	for(j=0, k=0; rpnexp[j]!=0; j++, k++)
	{
		if(rpnexp[j]==';')
		{
			token[k]=0;	k=-1;
			//print_test("TOKEN: %s\n", token);
			if(isdigit(token[0])) {	sscanf(token, "%X", &op1);	PUSH(op1);	}
			else if(EQ(token, "+"))  { POP(op1); POP(op2); PUSH(op2+op1); }
			else if(EQ(token, "-"))  { POP(op1); POP(op2); PUSH(op2-op1); }
			else if(EQ(token, "*"))  { POP(op1); POP(op2); PUSH(op2*op1); }
			else if(EQ(token, "&"))  { POP(op1); POP(op2); PUSH(op2&op1); }
			else if(EQ(token, "|"))  { POP(op1); POP(op2); PUSH(op2|op1); }
			else if(EQ(token, "^"))  { POP(op1); POP(op2); PUSH(op2^op1); }
			else if(EQ(token, ">>")) { POP(op1); POP(op2); PUSH(op2>>op1); }
			else if(EQ(token, "<<")) { POP(op1); POP(op2); PUSH(op2<<op1); }
			else if(EQ(token, "="))  { POP(op1); POP(op2); PUSH(op2==op1?1:0); }
			else if(EQ(token, "!=")) { POP(op1); POP(op2); PUSH(op2!=op1?1:0); }
			else if(EQ(token, "<"))  { POP(op1); POP(op2); PUSH(op2<op1?1:0); }
			else if(EQ(token, ">"))  { POP(op1); POP(op2); PUSH(op2>op1?1:0); }
			else if(EQ(token, "<=")) { POP(op1); POP(op2); PUSH(op2<=op1?1:0); }
			else if(EQ(token, ">=")) { POP(op1); POP(op2); PUSH(op2>=op1?1:0); }
			else if(EQ(token, "/"))
			{
				POP(op1);
				POP(op2);
				if(op1!=0)
				{
					PUSH(op2/op1);
				}
				else
				{
					PUSH(INT_MAX);
					print_error("relocatable operation divide by zero in module %s", modname);
				}

			}
			else if(EQ(token, "%"))
			{
				POP(op1);
				POP(op2);
				if(op1!=0)
				{
					PUSH(op2%op1);
				}
				else
				{
					PUSH(INT_MAX);
					print_error("relocatable operation remainder by zero in module %s", modname);
				}

			}
			else if(EQ(token, "$"))
			{
				// WARNING: it doesn't behave as the '$' operator in assembly.  Does it need a -1?
				// Put the current location counter in to the stack
				PUSH(current_cseg->counter-1); // -1 added.  Does it fix it?
			}
			else if(EQ(token, ".")) // Adding pointers to bits
			{
				unsigned char result;
				POP(op1); // Bit number
				POP(op2); // Register or SFR address
				if(op2>0x7f) // SFR
				{
					result=op2+(op1&0x07);
					PUSH(result);
				}
				else if( (op2>=0x20) && (op2<=0x2f) )
				{
					result=((op2-0x20)*8)+(op1&0x07);
					//printf("result=%02x\n", result);
					PUSH(result);
				}
				else
				{
					print_error("Bit operation is out of range in module %s. op1=%d, op2=%d", modname, op1, op2);
				}
			}
			else // Must be a symbol
			{
				// Get the symbol value.  Try first the local symbol...
				sprintf(varnamelocal, "%s:%s", modname, token);
				sym=looksym(varnamelocal);
				if(sym->type==UNDEF) // Local symbol to this module not found?
				{
					sym=looksym(token);  // Maybe is a public/external symbol...
				}

				if( (sym->type==UNDEF) || (sym->flags==EXTERN_SYM) )
				{
					op1=0;
					print_error("Unresolved external '%s' in module '%s'", sym->name, modname);
				}
				else
				{
					if(sym->segment!=NULL)
						op1=sym->value+sym->segment->value;
					else
						op1=sym->value;
				}
				PUSH(op1);
			}
		}
		else
		{
			token[k]=rpnexp[j];
		}
	}
	//print_test("%s=0x%04X\n", rpnexp, rpnstack[0]);
	return rpnstack[0];
}

int do_obj_pass2 (char * fname)
{
	int k, n;
	char modname[0x100];
	FILE * f1;
	char buffer[0x4000];
	char str[5][0x100];
	int val1;
	int state=0;
	struct symbol *seg;
	int offset;
	int value;

	f1=OpenSeek(fname);
    
    while(fgets(buffer, sizeof(buffer), f1)!=NULL)
    {
    	clean(buffer);
    	     if(EQ(buffer, "<MODULE>"))    state=MODULE;
    	else if(EQ(buffer, "<SEGMENTS>"))  state=SEGMENTS;
    	else if(EQ(buffer, "<LOCALS>"))    state=LOCALS;
    	else if(EQ(buffer, "<PUBLICS>"))   state=PUBLICS;
    	else if(EQ(buffer, "<EXTERNALS>")) state=EXTERNALS;
    	else if(strncmp(buffer, "<CODE", 5)==0)
		{
			for(k=0; buffer[k]!=0; k++)
			{
				if(buffer[k]=='<') buffer[k]=' ';
				if(buffer[k]=='>') buffer[k]=' ';
			}
			str[0][0]=0; str[1][0]=0;
 			n=sscanf(buffer, "%255s%255s%X", str[0], str[1], &val1);
			if((EQ(str[1], "AT")) && (n==3))
			{
				current_cseg=abs_cseg;
				abs_cseg->value=val1;
				abs_cseg->counter=0;
			}
			else
			{
				sprintf(str[3], "%s:%s", modname, str[1]);
				seg=looksym(str[3]);

				seg=looksym(str[3]);
				if( (seg->flags&SEGMENT) != SEGMENT)
				{
					print_error("segment '%s' is undefined", str[3]);
				}
				else
				{
					current_cseg=seg;
				}
			}
			state=CODE;
		}
    	else if(EQ(buffer, "</MODULE>"))    state=0;
    	else if(EQ(buffer, "</SEGMENTS>"))  state=0;
    	else if(EQ(buffer, "</LOCALS>"))    state=0;
    	else if(EQ(buffer, "</PUBLICS>"))   state=0;
    	else if(EQ(buffer, "</EXTERNALS>")) state=0;
		else if(EQ(buffer, "</CODE>"))		state=0;
		else if(EQ(buffer, "</FILE>")) // Only libraries have this
		{
			state=0;
			break; //Nothing else to read from this library module, get out.
		}
    	
    	else switch(state)
    	{
    		case MODULE:
 				strcpy(modname, buffer); //Need the module name to resolve local symbols
    		break;
    		
			case SEGMENTS:	break;
			case LOCALS:	break;
			case PUBLICS:	break;
			case EXTERNALS:	break;
    		
			case CODE:
				{
					char lstr[0x200];
					char fstr[0x20];
					char * s;
					int pos, n;

					s=buffer;
					sprintf(fstr,"%%%ds%%n", sizeof(lstr)-1); // fstr="%511s%n" if lstr[0x200]
	   				while(1)
    				{
						n=sscanf(s, fstr, lstr, &pos);
						if(n<1) break;
						s+=pos;
    			
						if(strlen(lstr)>2)
						{
							int i;
							char accesstype[0x100], rpnexp[0x100];
				
							for(i=0; lstr[i]!=0; i++)
							{
								if( (lstr[i]=='(') || (lstr[i]==')') ) lstr[i]=' ';
							}
							accesstype[0]=0; rpnexp[0]=0;
							sscanf(lstr, "%255s%255s", accesstype, rpnexp);
							value=Solve_RPN(rpnexp, modname);
							
							//Perform the access type
							if(EQ(accesstype, "data8"))
							{
								codeimage[(current_cseg->value+current_cseg->counter)&0xffff]=value&0xff;
								current_cseg->counter++;
							}
							else if(EQ(accesstype, "rel3"))
							{
								offset = value - (current_cseg->value+current_cseg->counter+1);
								if( (offset > 127) || offset < -128 )
								{
									print_error("Relative (rel3) offset exceeds -128 / +127in module %s", modname);
									printf("   %s\n", rpnexp);
								}
								codeimage[(current_cseg->value+current_cseg->counter)&0xffff]=offset&0xff;
								current_cseg->counter++;
							}
							else if(EQ(accesstype, "rel2"))
							{
								offset = value - (current_cseg->value+current_cseg->counter+1);
								if( (offset > 127) || offset < -128 )
								{
									print_error("Relative (rel2) offset exceeds -128 / +127 in module %s", modname);
									printf("   %s\n", rpnexp);
								}
								codeimage[(current_cseg->value+current_cseg->counter)&0xffff]=offset&0xff;
								current_cseg->counter++;
							}
							else if(EQ(accesstype, "bit")) //There maybe some problems with this case...
							{
								//printf("value=%04x\n", value);
								codeimage[(current_cseg->value+current_cseg->counter)&0xffff]=value&0xff;
								current_cseg->counter++;
							}
							else if( (EQ(accesstype, "data16")) || (EQ(accesstype, "addr16")) )
							{
								codeimage[(current_cseg->value+current_cseg->counter)&0xffff]=(value/0x100)&0xff;
								current_cseg->counter++;
								codeimage[(current_cseg->value+current_cseg->counter)&0xffff]=(value%0x100)&0xff;
								current_cseg->counter++;
							}
							else if(EQ(accesstype, "addr11"))
							{
								if(((current_cseg->value+current_cseg->counter)&0xf800)!=(unsigned int)(value&0xf800))
								{
									print_error("attempted 'ajmp' or 'acall' to an off-page address in module '%s'", modname);
								}
								codeimage[(current_cseg->value+current_cseg->counter-1)&0xffff]&=0x1f;
								codeimage[(current_cseg->value+current_cseg->counter-1)&0xffff]|=((value&0x0700)>>3);
								codeimage[(current_cseg->value+current_cseg->counter)&0xffff]=value&0xff;
								current_cseg->counter++;
							}
							else if ( (strlen(accesstype)==4) && // Maybe the lower 8-bit of a 16-bit value?
									  isxdigit(accesstype[0]) &&
									  isxdigit(accesstype[1]) &&
									  isxdigit(accesstype[2]) &&
									  isxdigit(accesstype[3]) )
							{
								sscanf(accesstype, "%x", &val1);
								codeimage[(current_cseg->value+current_cseg->counter)&0xffff]=val1&0xff;
								current_cseg->counter++;
							}
							else
							{
								print_error("Unknown access '%s' type in module '%s'", accesstype, modname);
							}
						}
						else // An 8-bit hex value.
						{
							sscanf(lstr, "%X", &val1);
							codeimage[(current_cseg->value+current_cseg->counter)&0xffff]=val1&0xff;
							current_cseg->counter++;
						}
    				}
				}
    		break;
    		default:
    			state=0;
    		break;
    	}
    }
    fclose(f1);
	return 0;
}

void check_for_overlaps(void)
{
	int i, j;

	//Check for code overlaps

	for(i=0; i<0x10000; i++)
	{
		if(memmask[i]&CODEOVERLAP)
		{
			j=i;
			for(; i<0x10000; i++)
			{
				if((memmask[i]&CODEOVERLAP)==0) break;
			}
			print_error("CODE overlap from %04XH to %04XH", j, i);

		}
	}

	//Check for xdata overlaps
	for(i=0; i<0x10000; i++)
	{
		if(memmask[i]&XDATAOVERLAP)
		{
			j=i;
			for(; i<0x10000; i++)
			{
				if((memmask[i]&XDATAOVERLAP)==0) break;
			}
			print_error("XDATA overlap from %04XH to %04XH", j, i);

		}
	}

	// Check for data overlaps
	for(i=0; i<0x100; i++)
	{
		if(datamaskoverlap[i]==0xff)
		{
			j=i;
			for(; i<0x100; i++)
			{
				if(datamaskoverlap[i]!=0xff) break;
			}
			print_error("DATA overlap from %02XH to %02XH", j, i);

		}
	}

}

int create_map_file (void)
{
	int j, k, count, total;
	FILE * fp;
    struct symbol *sym, *next;
    int i;
	char buffer[PATH_MAX+0x100];
	char fname[PATH_MAX];
	int cseg_cnt, iseg_cnt, dseg_cnt, bseg_cnt, xseg_cnt;
	int cseg_tot, iseg_tot, dseg_tot, bseg_tot, xseg_tot;

	char **LineStr=NULL;
	int NumLineStr=0;


	if ( (fp=fopen(map_filename, "w")) == NULL )
    {
		print_error("can not create file `%s`", map_filename);
		return -1;
    }
	
	fprintf(fp, "Modules linked:\n");
	for(j=0; j<NumObjFiles; j++)
	{
		Get_Modname_From_File(ObjName[j], buffer);
		strcpy(fname, ObjName[j]);
		for(k=0; fname[k]!=0; k++)
		{
			if(fname[k]=='>')
			{
				fname[k]=0;
				break;
			}
		}
		fprintf(fp,"   '%s' from '%s'\n", buffer, fname);
	}
	fprintf(fp,"\n");

	cseg_tot=0;
	iseg_tot=0;
	dseg_tot=0;
	bseg_tot=0;
	xseg_tot=0;

	fprintf(fp, "Memory use per module linked:\n");
	for(j=0; j<NumObjFiles; j++)
	{
		Get_Modname_From_File(ObjName[j], buffer);
		
		cseg_cnt=0;
		iseg_cnt=0;
		dseg_cnt=0;
		bseg_cnt=0;
		xseg_cnt=0;

		for (i=0; i<HASHTABSIZE; i++)
		{
			sym = symtab[i];
			while (sym != NULL)
			{
				if( ((sym->flags&BASE_SEG)==0) && (sym->flags&SEGMENT) )
				{
					if(strncmp(buffer, sym->name, strlen(buffer))==0)
					{
						switch(sym->type)
						{
							case CSEG: cseg_cnt+=sym->size; break;
							case DSEG: dseg_cnt+=sym->size; break;
							case ISEG: iseg_cnt+=sym->size; break;
							case BSEG: bseg_cnt+=sym->size; break;
							case XSEG: xseg_cnt+=sym->size; break;
							default: break;
						}
					}
				}
				next = sym->next;
				sym = next;
			}
		}

		fprintf(fp,"C:%05d D:%03d I:%03d B:%03d X:%05d - %s\n",
			cseg_cnt, dseg_cnt, iseg_cnt, bseg_cnt, xseg_cnt, buffer);
		
		cseg_tot+=cseg_cnt;
		dseg_tot+=dseg_cnt;
		iseg_tot+=iseg_cnt;
		bseg_tot+=bseg_cnt;
		xseg_tot+=xseg_cnt;
	}
	
	fprintf(fp,"C:%05d D:%03d I:%03d B:%03d X:%05d - ABSOLUTE\n",
			abs_cseg->size, abs_dseg->size, abs_iseg->size, abs_bseg->size, abs_xseg->size);
		
	cseg_tot+=abs_cseg->size;
	dseg_tot+=abs_dseg->size;
	iseg_tot+=abs_iseg->size;
	bseg_tot+=abs_bseg->size;
	xseg_tot+=abs_xseg->size;

	fprintf(fp,"------------------------------------------------------\n");
	fprintf(fp,"C:%05d D:%03d I:%03d B:%03d X:%05d - Totals\n\n",
		    cseg_tot, dseg_tot, iseg_tot, bseg_tot, xseg_tot);

	fprintf(fp, "INTERMAL RAM map (see legend below):");
	for(j=0; j<0x100; j++)
	{
		if((j%16)==0)
		{
			fprintf(fp, "\n%02X: ", j);
		}
		fprintf(fp, "%c ", datamask[j]!=0?datamask[j]:'.');
	}
	fprintf(fp,"\n");

	fprintf(fp, data_legend);

	fprintf(fp, "\nBIT map:");
	for(j=0; j<0x80; j++)
	{
		if((j%16)==0)
		{
			fprintf(fp, "\n%02X: ", j);
		}
		fprintf(fp, "%c ", bitmask[j]!=0?bitmask[j]:'.');
	}
	fprintf(fp,"\n");

	fprintf(fp, "\nCODE usage map:");
	total=0;
	for(j=0; j<0x100; j++)
	{
		for(k=0, count=0; k<0x100; k++)
		{
			if(memmask[j*0x100+k]&CODEMASK)
			{
				count++;
				total++;
			}
		}
		if((j%16)==0)
		{
			fprintf(fp, "\n%04X: ", j*0x100);
		}
		fprintf(fp, "%03d ", count);
	}
	fprintf(fp, "\nTotal: %d bytes\n", total);

	fprintf(fp, "\nXDATA usage map:");
	total=0;
	for(j=0; j<0x100; j++)
	{
		for(k=0, count=0; k<0x100; k++)
		{
			if(memmask[j*0x100+k]&XDATAMASK)
			{
				count++;
				total++;
			}
		}
		if((j%16)==0)
		{
			fprintf(fp, "\n%04X: ", j*0x100);
		}
		fprintf(fp, "%03d ", count);
	}
	fprintf(fp, "\nTotal: %d bytes\n", total);

	fprintf(fp, "\nBase Segments:\n");
    for (i=0; i<HASHTABSIZE; i++)
	{
        sym = symtab[i];
        while (sym != NULL)
		{
			if(sym->flags&BASE_SEG)
			{
				sprintf(buffer,"%s=%c:%04X, size=%04X", sym->name, Symbol_type_initial[sym->type], sym->value, sym->size);
				add_string(&LineStr, &NumLineStr, buffer);
			}
            next = sym->next;
            sym = next;
        }
    }

	sort_strings(&LineStr, &NumLineStr);
	for(i=0; i<NumLineStr; i++)	fprintf(fp, "   %s\n", LineStr[i]);
	free_strings(&LineStr, &NumLineStr);

	fprintf(fp, "\nModule Segments:\n");
    for (i=0; i<HASHTABSIZE; i++)
	{
        sym = symtab[i];
        while (sym != NULL)
		{
			if( ((sym->flags&BASE_SEG)==0) && (sym->flags&SEGMENT) )
			{
				if((sym->size)>0)
				{
					sprintf(buffer,"%s=%c:%04X, size=%04X", sym->name, Symbol_type_initial[sym->type], sym->value, sym->size);
					add_string(&LineStr, &NumLineStr, buffer);
				}
			}
            next = sym->next;
            sym = next;
        }
    }

	sort_strings(&LineStr, &NumLineStr);
	for(i=0; i<NumLineStr; i++)	fprintf(fp, "   %s\n", LineStr[i]);
	free_strings(&LineStr, &NumLineStr);

	fprintf(fp, "\nPublic symbols:\n");

    for (i=0; i<HASHTABSIZE; i++)
	{
        sym = symtab[i];
        while (sym != NULL)
		{
			if( (sym->flags&PUBLIC_SYM) && ((sym->flags&EXTERN_SYM)==0) )
			{
				if(sym->segment!=NULL)
					sprintf(buffer, "%s=%c:%04X", sym->name, Symbol_type_initial[sym->type],sym->value+sym->segment->value);
				else
					sprintf(buffer, "%s=%c:%04X", sym->name, Symbol_type_initial[sym->type], sym->value);
				
				add_string(&LineStr, &NumLineStr, buffer);
			}
            next = sym->next;
            sym = next;
        }
    }
	sort_strings(&LineStr, &NumLineStr);
	for(i=0; i<NumLineStr; i++)	fprintf(fp, "   %s\n", LineStr[i]);
	free_strings(&LineStr, &NumLineStr);

	fprintf(fp, "\nLocal symbols:\n");

    for (i=0; i<HASHTABSIZE; i++)
	{
        sym = symtab[i];
        while (sym != NULL)
		{
			if( sym->flags==0 )
			{
				if(sym->segment!=NULL)
				{
					sprintf(buffer, "%s=%c:%04X", sym->name, Symbol_type_initial[sym->type], sym->value+sym->segment->value);
					add_string(&LineStr, &NumLineStr, buffer);
				}
			}
            next = sym->next;
            sym = next;
        }
    }
	sort_strings(&LineStr, &NumLineStr);
	for(i=0; i<NumLineStr; i++)	fprintf(fp, "   %s\n", LineStr[i]);
	free_strings(&LineStr, &NumLineStr);

	fclose(fp);
	return 0;
}

void create_hex_file (void)
{
	int j, doline, address;
	unsigned char chk_sum;
	char hexline[0x200];
	char buff[0x20];
	int len;
	FILE * fp;
	
	if ( (fp=fopen(hex_filename, "w")) == NULL )
    {
		print_error("can not create file `%s`", hex_filename);
		exit(5);
    }

	len=16;

	for(address=0; address<0x10000; address+=len)
	{
		doline=0;
		for(j=0; j<len; j++)
		{
			if(memmask[j+address]&CODEMASK) 
			{
				doline=1;
				break;
			}
		}
		if(doline==1)
		{
			sprintf(hexline, ":%02X%04X00", len, address);
			chk_sum= (unsigned char) (len + (address%0x100) + (address/0x100));

			for (j=0; j<len; j++)
			{
				sprintf(buff, "%02X", codeimage[address+j]);
				chk_sum += (unsigned char) codeimage[address+j];
				strcat(hexline, buff);
			}
			sprintf(buff,"%02X\n", (unsigned char)(0x100-chk_sum));
			strcat(hexline, buff);
			fprintf(fp, hexline);
		}
	}
	fprintf(fp,":00000001FF\n");
	fclose(fp);
}

int main(int argc, char **argv)
{
	int j;

	ProcLineOptions(argc, argv);

	if(NumObjFiles==0)
	{
		print_error("%s needs at least one object file to proceed.", argv[0]);
		return -1;
	}

	_splitpath(ObjName[0], drive, dir, fname, ext);
	if(map_filename[0]==0)
		_makepath( map_filename, drive, dir, fname, "map" );
	if(hex_filename[0]==0)
		_makepath( hex_filename, drive, dir, fname, "hex" );

	clearsym();
	resolve_externals();
	
	seginit();
	memset(memmask, 0, 0x10000);
	memset(codeimage, 0, 0x10000);
	memset(datamask, 0, 0x100);
	memset(bitmask, 0, 0x80);
	memset(datamask, 0xff, 0x8); // Reserve register bank 0
	memset(datamaskoverlap, 0, 0x100);

	for(j=0; j<NumObjFiles; j++)
	{
		do_obj_pass1(ObjName[j]);
		reset_segment_counter();
	}

	if(error_count)
	{
		freesym();
		free_strings(&ObjName,  &NumObjFiles);
		free_strings(&LibName,  &NumLibFiles);
		free_strings(&PathName, &NumPathNames);
		return 2;
	}

	place_segments(); //Find space for the segments

	//Assign values to the symbols and produce the final located code
	for(j=0; j<NumObjFiles; j++)
	{
		do_obj_pass2(ObjName[j]); 
	}

	check_for_overlaps();

	create_map_file();
	if(error_count==0)
	{
		create_hex_file();
	}
	else
	{
		unlink(hex_filename);
	}

	freesym();
	free_strings(&ObjName,  &NumObjFiles);
	free_strings(&LibName,  &NumLibFiles);
	free_strings(&PathName, &NumPathNames);

    return 0;
}
