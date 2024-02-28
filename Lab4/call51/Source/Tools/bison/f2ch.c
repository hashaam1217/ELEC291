#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	FILE * infile;
	int x, j;
	
	if(argc<2)
	{
		printf("Need the variable and filename!\n");
		return 1;
	}
	infile=fopen(argv[2], "rb");
	if(infile==NULL)
	{
		printf("Couldn't open file '%s'\n", infile);
	}
	printf("char %s[]={\n   ", argv[1]);
	while(1)
	{
		x=fgetc(infile);
		if(x==EOF) break;
		printf("0x%02x, ", x);
		j++;
		if(j==8)
		{
			j=0;
			printf("\n   ");
		}
	}
	printf("\n   0};\n");
	fclose(infile);
	return 0;
}