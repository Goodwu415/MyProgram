#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *infile, *outfile;
void Decompress(char *infilename, char* outfilename);//Ω‚—π
void Common(char *filename);
int main(int argc, char *argv[]) 
{
	printf("rlejy decompress file\n");
	if(argc != 3)
	{
		printf("\n usage:rlejy sourcefilename target filename\n");
		exit(0);
	}
	printf("\n decompression...");
	Decompress(argv[1],argv[2]);
	fclose(infile);
	fclose(outfile);
	
	return 0;
}
void Common(char *filename)
{
	char tempspace[200];
	strcpy(tempspace, "\n Unable to open");
	strcat(tempspace, filename);
	puts(tempspace);
	exit(1);
}
void Decompress(char *infilename, char *outfilename)
{
	register int seq_len, i;
	char cur_char;
	if((infile = fopen(infilename,"rb")) == NULL)
		Common(infilename);
	if((outfile = fopen(outfilename,"wb"))== NULL)
		Common(outfilename);
	while(!feof(infile))
	{
		seq_len = fgetc(infile);
		cur_char = fgetc(infile);
		for(i = 0; i < seq_len; i++)
		{
			fputc(cur_char, outfile);
		}
	}
}
