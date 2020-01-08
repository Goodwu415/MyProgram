#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define BITS 12
#define HASHSHIFT BITS-8
#define MAXVALUE (1<<BITS)-1
#define MAXCODE MAXVALUE-1
#define TABLESIZE 4099

struct{
	int *code;
	int *prefix;
	char *suffix;
}lzw,*lp;

void outcode(FILE*output, int code);
int hashsearch(int prefix, int suffix);	//哈希表 
void Compress(FILE* input, FILE *output);//压缩函数 
int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	
	if(argc != 3)
	{
		printf("usage:lzw sourcefilename target filename\n");
		exit(1);
	}
	if((fp1 = fopen(argv[1],"rb")) == NULL)
	{
		printf("cannot open the file %s!\n", argv[1]);
		exit(1);
	}
	if((fp2 = fopen(argv[2],"wb")) == NULL)
	{
		printf("cannot establish the file %s!\n",argv[2]);
		exit(1);
	}
	Compress(fp1, fp2);
	fclose(fp1);
	fclose(fp2);
	return 0;
}

void outcode(FILE*output, int code)
{
	static int ob = 0;
	static unsigned long obb = 0L;
	obb |= (unsigned long)code << (32-BITS-ob);
	ob += BITS;
	
	while(ob >= 8)
	{
		putc(obb >> 24, output);//向右移24位使低8位为要输出的数据
		obb <<= 8; 
		ob -= 8;
	}
}
int hashsearch(int prefix, int suffix)
{
	int index;
	int offset;
	index = (suffix << HASHSHIFT)^prefix;
	
	if(index == 0)
		offset = 1;
	else
		offset = TABLESIZE - index;
	while(1)
	{
		if(lp->code[index] == -1)
			return (index);
		if(lp->prefix[index] == prefix && lp->suffix[index] == suffix)
			return (index);
		index -= offset;
		if(index < 0)
			index += TABLESIZE;
		
	}
}
void Compress(FILE* input, FILE *output)
{
	int suffix, prefix, index, ccode, i;
	lzw.code = malloc(TABLESIZE * sizeof(int));//标号值
	lzw.prefix = malloc(TABLESIZE * sizeof(int));//前缀数据
	lzw.suffix = malloc(TABLESIZE * sizeof(char));	//后缀数据
	if(lzw.code == NULL || lzw.prefix == NULL || lzw.suffix == NULL)
	{
		printf("the EMS memory spill over!\n");
		getch();
		exit(1);
	 } 
	 lp = &lzw;
	 ccode = 258;
	 for(i = 0; i < TABLESIZE; i++)
	 {
	 	lp->code[i] = -1;
	 }
	 printf("\nCompressing...");
	 prefix = getc(input);
	 while((suffix = getc(input)) != EOF)
	 {
	 	index = hashsearch(prefix, suffix);
	 	if(lp->code[index] != -1)
	 		prefix = lp->code[index];
	 	else{
		 
	 		if(ccode <= MAXCODE)
	 		{
	 			lp->code[index] = ccode++;
	 			lp->prefix[index] = prefix;
	 			lp->suffix[index] = suffix;
			 }
			 outcode(output, prefix);
			 prefix = suffix;
		}
	 }
	 outcode(output, prefix);
	 outcode(output, (MAXVALUE));
	 outcode(output, 0);
	 free(lp->code);
	 free(lp->prefix);
	 free(lp->suffix);
}
