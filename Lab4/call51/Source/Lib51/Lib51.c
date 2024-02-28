/*  Lib51.c: Call51 librarian

    Copyright (C) 2011  Jesus Calvino-Fraga, jesusc (at) ece.ubc.ca
    
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

#define _POSIX_
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#if !defined(__BORLANDC__) && !defined(_MSC_VER)
#include <unistd.h>
#endif

#if defined(_MSC_VER)
#pragma warning (disable : 4996)
#endif

#if defined(_WIN64)
#pragma warning (disable : 4244)
#pragma warning (disable : 4267)
#endif

#if !defined(PATH_MAX) || (PATH_MAX < 2048)
#  undef  PATH_MAX
#  define PATH_MAX 2048         /* define a reasonable value */
#endif

char ProgName[PATH_MAX];
char LibName[PATH_MAX];
char LibNameTmp[PATH_MAX];
char IndexName[PATH_MAX];
char ListName[PATH_MAX];

char **ObjName;
int NumObjFiles=0;

#define version "1.0"

#define OPT_NONE     0
#define OPT_ADD_OBJ  1
#define OPT_EXT_OBJ  2
#define OPT_DEL_OBJ  3
#define OPT_ADD_LIST 4
#define OPT_DUMP_SYM 5
#define OPT_DUMP_MOD 6

#define MAXLINE 254
#define EQ(A,B) !strcmp((A),(B))
#define NEQ(A,B) strcmp((A),(B))

int action=OPT_NONE;
FILE *lib, *newlib, *OBJ, *libindex;
char FLine[MAXLINE+1];
char ModName[MAXLINE+1];

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
	        printf("ERROR: Filename '%s' must have an extension\n", path);
	        exit(1);
	    }
    }
    else
    {
        printf("ERROR: Empty filename\n");
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
    "Usage: %s [option|-options] library obj1 obj2 obj3 ...\n\n"
    "available options:\n"
    "a,r - Adds OBJfile(s) to library.  If OBJfile exists, replaces it.\n"
    "  l - Adds OBJfile list to library.\n"
    "  d - Deletes OBJfile(s) from library.\n"
    "e,x - Extracts OBJfile(s) from library.\n"
    "  s - Dumps symbols of library.\n"
    "  m - Dumps modules of library.\n"
    "  v - Displays program version.\n"
    "h,? - This help.\n";

    switch (opt[0])
    {
        default:
            unknown=1;
        case 'h':
        case '?':
        case 'v':
            printf("%s: CALL51 librarian, version %s\n", ProgName, version);
            printf("by Jesus Calvino-Fraga\n\n");
            if (unknown) printf("Unknown option: %c\n", opt[0]);
            if (opt[0]=='v') exit(0);
            printf(Help, ProgName);
            exit(1);
        break;
        case 'a':
        case 'r':
            action=OPT_ADD_OBJ;
        break;
        case 'l':
            action=OPT_ADD_LIST;
        break;
        case 'e':
        case 'x':
            action=OPT_EXT_OBJ;
        break;
        case 'd':
            action=OPT_DEL_OBJ;
        break;
        case 's':
            action=OPT_DUMP_SYM;
        break;
        case 'm':
            action=OPT_DUMP_MOD;
        break;
    }
    return (rvalue);
}

void ProcLineOptions (int argc, char **argv)
{
    int cont_par=0;
    int i, j;

    /*Get the program name*/
    GetNameFromPath(argv[0], ProgName);

    for (j=1; j<argc; j++)
    {
        if(argv[j][0]=='-')
        {
            for(i=1; argv[j][i]!=0 ; i++)
                if (set_options(&argv[j][i])) break;
        }
        else
        {
            switch(cont_par)
            {
                case 0:
                    if ((strlen(argv[j])==1) && (action==OPT_NONE))
                        set_options(argv[j]);
                    else
                    {
                        cont_par++;
                        strcpy(LibName, argv[j]);
                    }
                break;

                case 1:
                    cont_par++;
                    if(action==OPT_ADD_LIST)
                        strcpy(ListName, argv[j]);
                    else
                    {
                        NumObjFiles=1;
                        ObjName = (char **) calloc (1, sizeof (char *));
                        if(ObjName==NULL)
                        {
                            printf("ERROR: Insufficient memory.\n");
                            exit(2);
                        }
                        ObjName[0]=(char *)malloc(PATH_MAX);
                        if(ObjName[0]==NULL)
                        {
                            printf("ERROR: Insufficient memory.\n");
                            exit(2);
                        }
                        strcpy(ObjName[0], argv[j]);
                    }
                break;

                default:
                    cont_par++;
                    NumObjFiles++;
                    ObjName = (char **) realloc (ObjName, NumObjFiles * sizeof (char *));
                    if(ObjName==NULL)
                    {
                        printf("ERROR: Insufficient memory.\n");
                        exit(2);
                    }
                    ObjName[NumObjFiles-1]=(char *)malloc(PATH_MAX);
                    if(ObjName[NumObjFiles-1]==NULL)
                    {
                        printf("ERROR: Insufficient memory.\n");
                        exit(2);
                    }
                    strcpy(ObjName[NumObjFiles-1], argv[j]);
                break;
            }
        }
    }

    if ( (cont_par<2) && (action<OPT_DUMP_SYM) )
    {
        printf("ERROR: Too few arguments.\n");
        set_options("h"); /*Show help and exit*/
    }
    else if ( (cont_par!=1) && (action>=OPT_DUMP_SYM) )
    {
        printf("ERROR: Too %s arguments.\n", cont_par<1?"few":"many");
        set_options("h"); /*Show help and exit*/
    }
}

void AddObj(char * ObjName)
{
    int inPUB=0;
    int state=0;
    long newlibpos, indexsize;
    int IsDOSStyle=0;

    strcpy(LibNameTmp, LibName);
    ChangeExtension(LibNameTmp, "__L");

    strcpy(IndexName, LibName);
    ChangeExtension(IndexName, "__I");

    lib=fopen(LibName, "r");

    if(action==OPT_ADD_OBJ)
    {
        OBJ=fopen(ObjName, "r");
        if(OBJ==NULL)
        {
            printf("ERROR: Couldn't open file '%s'\n", ObjName);
            if(lib!=NULL) fclose(lib);
            return;
        }
    }
    GetNameFromPath(ObjName, ModName);

    newlib=fopen(LibNameTmp, "w");
    if(newlib==NULL)
    {
        printf("ERROR: Couldn't create temporary file '%s'\n", LibNameTmp);
        if(lib!=NULL) fclose(lib);
        fclose(OBJ);
        return;
    }
    fprintf(newlib, "<FILES>\n\n");

    libindex=fopen(IndexName, "w");
    if(libindex==NULL)
    {
        printf("ERROR: Couldn't create temporary file '%s'\n", IndexName);
        if(lib!=NULL) fclose(lib);
        fclose(newlib);
        fclose(OBJ);
        return;
    }

	//First step is to remove the file from the library
    if(lib!=NULL) while(!feof(lib))
    {
        FLine[0]=0;
        fgets(FLine, MAXLINE, lib);
        CleanLine(FLine);

        switch(state)
        {
            case 0:
                if(EQ(FLine, "<FILE>"))
                {
                    FLine[0]=0;
                    fgets(FLine, MAXLINE, lib);
                    CleanLine(FLine);
                    if(NEQ(FLine, ModName))
                    {
                        newlibpos=ftell(newlib);
                        fprintf(newlib, "<FILE>\n%s\n", FLine);
                        fprintf(libindex, "<MODULE>\n%s %ld\n", FLine, newlibpos);
                        state++;
                    }
                }
            break;
            case 1:
                fprintf(newlib, "%s\n", FLine);
                if(EQ(FLine, "</FILE>"))
                {
                    fprintf(newlib, "\n");
                    fprintf(libindex, "</MODULE>\n\n");
                    state=0;
                    inPUB=0;
                }
                else if(EQ(FLine, "<PUBLICS>")) inPUB=1;
                else if(EQ(FLine, "</PUBLICS>")) inPUB=0;
                else if(inPUB) fprintf(libindex, "%s\n", FLine);
            break;
        }
    }

    if(action==OPT_ADD_OBJ)
    {
        newlibpos=ftell(newlib);
        fprintf(newlib, "<FILE>\n%s\n<OBJ>\n", ModName);
        fprintf(libindex, "<MODULE>\n%s %ld\n", ModName, newlibpos);
		inPUB=0;
        while(!feof(OBJ))
        {
            FLine[0]=0;
            fgets(FLine, MAXLINE, OBJ);
            CleanLine(FLine);
            if(strlen(FLine)>0)
            {
                fprintf(newlib, "%s\n", FLine);
            }
            if(EQ(FLine, "<PUBLICS>")) inPUB=1;
            else if(EQ(FLine, "</PUBLICS>")) inPUB=0;
            else if(inPUB) fprintf(libindex, "%s\n", FLine);
        }
        fclose(OBJ);
        fprintf(libindex, "</MODULE>\n");
        fprintf(newlib, "</OBJ>\n</FILE>\n");
    }

    /*Put the temporary files together as a new library file*/
    indexsize=ftell(libindex);
    fflush(libindex);
    fflush(newlib);
    fclose(newlib);
    if(lib!=NULL) fclose(lib);
    fclose(libindex);

    newlib=fopen(LibNameTmp, "r");
    lib=fopen(LibName, "w");
    libindex=fopen(IndexName, "r");

    fprintf(lib, "<CALL51LIB>\n\n<INDEX>\n");

    /*Find out if the \n is expanded to \r\n or not*/
    if(ftell(lib)!=(long)strlen("<CALL51LIB>\n\n<INDEX>\n"))
    {
        IsDOSStyle=1;
    }

    indexsize+=ftell(lib)+strlen("0123456789\n\n</INDEX>\n\n");
    if(IsDOSStyle) indexsize+=4;

    fprintf(lib, "%10ld\n", indexsize);

    while(!feof(libindex))
    {
        FLine[0]=0;
        fgets(FLine, MAXLINE, libindex);
        fprintf(lib, "%s", FLine);
    }
    fprintf(lib, "\n</INDEX>\n\n");

    while(!feof(newlib))
    {
        FLine[0]=0;
        fgets(FLine, MAXLINE, newlib);
        fprintf(lib, "%s", FLine);
    }
    fprintf(lib, "\n</FILES>\n\n");
    fprintf(lib, "</CALL51LIB>\n");

    fclose(newlib);
    fclose(lib);
    fclose(libindex);

    remove(LibNameTmp);
    remove(IndexName);
}

void ExtractObj(char * ObjName)
{
    int state=0;

    lib=fopen(LibName, "r");
    if(lib==NULL)
    {
        printf("ERROR: Couldn't open file '%s'\n", LibName);
        return;
    }

    OBJ=fopen(ObjName, "w");
    if(OBJ==NULL)
    {
        printf("ERROR: Couldn't create file '%s'\n", ObjName);
        fclose(lib);
        return;
    }
    GetNameFromPath(ObjName, ModName);

    while(!feof(lib))
    {
        if(state==5) break;
        FLine[0]=0;
        fgets(FLine, MAXLINE, lib);
        CleanLine(FLine);

        switch(state)
        {
            case 0:
                if(EQ(FLine, "<FILE>"))
                {
                    FLine[0]=0;
                    fgets(FLine, MAXLINE, lib);
                    CleanLine(FLine);
                    if(EQ(FLine, ModName)) state=1;
                }
            break;
            case 1:
                if(EQ(FLine, "<OBJ>")) state=2;
            break;
            case 2:
                if(EQ(FLine, "</OBJ>"))
                    state=3;
                else
                    fprintf(OBJ, "%s\n", FLine);
            break;
        }
    }

    fclose(OBJ);
    fclose(lib);
}

void DumpSymbols(void)
{
    int state=0;

    lib=fopen(LibName, "r");
    if(lib==NULL)
    {
        printf("ERROR: Couldn't open file '%s'\n", LibName);
        return;
    }

    FLine[0]=0;
    fgets(FLine, MAXLINE, lib);
    CleanLine(FLine);
    if(NEQ(FLine, "<CALL51LIB>"))
    {
        printf("ERROR: File '%s' was not created with '%s'\n", LibName, ProgName);
        return;
    }

    while(!feof(lib))
    {
        if(state==3) break;
        FLine[0]=0;
        fgets(FLine, MAXLINE, lib);
        CleanLine(FLine);

        switch(state)
        {
            case 0:
                if(EQ(FLine, "<INDEX>")) state=1;
            break;
            case 1:
                if(EQ(FLine, "<MODULE>"))
                {
                    FLine[0]=0;
                    fgets(FLine, MAXLINE, lib);
                    sscanf(FLine, "%s", ModName);
                    if(action==OPT_DUMP_SYM)
                    {
                        printf("%s.OBJ:\n", ModName);
                        state=2;
                    }
                    else
                    {
                        printf("%s.OBJ\n", ModName);
                    }
                }
                else if(EQ(FLine, "</INDEX>")) state=3;
            break;
            case 2:
                if(EQ(FLine, "</MODULE>"))
                {
                    state=1;
                    printf("\n");
                }
                else printf("   %s\n", FLine);
            break;
            default:
                state=3;
            case 3:
            break;
        }
    }

    fclose(lib);
}

int fileexist(char * fname)
{
    FILE * fp;

    fp=fopen(fname, "r");
    if(fp==NULL) return 0;
    fclose(fp);
    return 1;
}

void AddList(void)
{
    FILE * list;
    char *cc;
    char *as;
    char CmdLine[1024];
    char SrcName[PATH_MAX];
    char ObjName[PATH_MAX];

    list=fopen(ListName, "r");
    if(list==NULL)
    {
        printf("ERROR: Couldn't open list file '%s'\n", ListName);
        return;
    }

    cc = getenv("CALL51_CC");
    as = getenv("CALL51_AS");

    action=OPT_ADD_OBJ;
    while(!feof(list))
    {
        ObjName[0]=0;
        fgets(ObjName, PATH_MAX, list);
        CleanLine(ObjName);
        if(strlen(ObjName)>0) //Skip empty lines
        {
			if(ObjName[0]!=';') // If is not a comment
			{
				if((cc!=NULL)||(as!=NULL))
				{
					strcpy(SrcName, ObjName);
					if(strchr(SrcName,'.')==NULL)
						strcat(SrcName,".src");
				}

				if(cc!=NULL)
				{
					ChangeExtension(SrcName, "c");
					if(fileexist(SrcName))
					{
						sprintf(CmdLine, "%s %s", cc, SrcName);
						printf("%s\n", CmdLine);
						system(CmdLine);
					}
				}
				else if(as!=NULL)
				{
					ChangeExtension(SrcName, "asm");
					if(fileexist(SrcName))
					{
						sprintf(CmdLine, "%s %s", as, SrcName);
						printf("%s\n", CmdLine);
						system(CmdLine);
					}
				}

				if(strchr(ObjName,'.')==NULL)
				{
					//Try adding the default call51 extensions
					strcat(ObjName,".obj");
					if(!fileexist(ObjName))
						ChangeExtension(ObjName, "o");
				}

				printf("Adding: %s\n", ObjName);
				AddObj(ObjName);
			}
        }
    }
    action=OPT_ADD_LIST;
    fclose(list);
}

int main(int argc, char **argv)
{
    int j;
    ProcLineOptions (argc, argv);

    switch(action)
    {
        default:
            action=OPT_ADD_OBJ;
        case OPT_ADD_OBJ:
        case OPT_DEL_OBJ:
            for(j=0; j<NumObjFiles; j++) AddObj(ObjName[j]);
            //Clean up
            for(j=0; j<NumObjFiles; j++) free(ObjName[j]);
            free(ObjName);
        break;

        case OPT_ADD_LIST:
            AddList();
        break;

        case OPT_EXT_OBJ:
            for(j=0; j<NumObjFiles; j++) ExtractObj(ObjName[j]);
            //Clean up
            for(j=0; j<NumObjFiles; j++) free(ObjName[j]);
            free(ObjName);
        break;

        case OPT_DUMP_SYM:
        case OPT_DUMP_MOD:
            DumpSymbols();
        break;
    }
    return 0; //Success!!!
}
