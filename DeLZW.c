#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define BITS 12
#define MAXVALUE (1<<BITS)-1
#define MAXCODE MAXVALUE-1
#define TABLESIZE 4099
struct{
	int *code;	//��� 
	int *prefix;//ǰ׺ 
	char *suffix;//��׺ 
}lzw,*lp;
char dectable[TABLESIZE];	//�����ѹ�������

int incode(FILE *input)//����������� 
{
	int ret;
	static int ib = 0;
	static unsigned long ibb = 0L;
	while(ib <= 24)
	{
		ibb |= (unsigned long) getc(input) << (24 - ib);
		ib += 8;
	}
	ret = ibb >>(32 - BITS);
	ibb <<= BITS;
	ib -= BITS;
	return ret;
}
char *decode(char *buffer, int code)//���뺯��
{
	int i = 0;
	while(code > 257)//�Ա�Ž��н���
	{
		*buffer++ = lp->suffix[code];
		code = lp->prefix[code];
		if(i++ >= TABLESIZE)
		{
			printf("the EMS memory spill over!\n");
			exit(1);
		}
	} 
	*buffer = code;
	return buffer;//���ػ�����ָ�� 
 } 
void Decompress(FILE *input, FILE *output) //��ѹ������ 
{
	int ccode, suffix, prefix, ch;
	char *ps;
	lzw.code = malloc(TABLESIZE * sizeof(int));//����ֵ���� 
	lzw.prefix = malloc(TABLESIZE * sizeof(int));//ѹ��ǰ����
	lzw.suffix = malloc(TABLESIZE * sizeof(char));//ѹ��������
	lp = &lzw;
	
	if(lzw.code == NULL || lzw.prefix == NULL || lzw.suffix == NULL) 
	{
		printf("Fatal error allocating table space!\n");
		getch();
		exit(1);
	}
	ccode = 258;	//��ǰ��Ŵ�258��ʼ
	printf("\n Decompress...");
	prefix = incode(input);
	ch = prefix;
	putc(prefix, output);
	
	while((suffix = incode(input)) != (MAXVALUE))
	{
		if(suffix >= ccode)
		{
			*dectable = ch;
			ps = decode(dectable + 1, prefix);
		}
		else
		{
			ps = decode(dectable, suffix);
			ch = *ps;
		}
		
		while( ps >= dectable)
		{
			putc(*ps--, output);
		}
		if(ccode <= MAXCODE)
		{
			lp->prefix[ccode] = prefix;
			lp->suffix[ccode] = ch;
			ccode++;
		}
		prefix = suffix;
	}
	free(lp->code);
	free(lp->suffix);
	free(lp->prefix);
}

int main(int argc, char *argv[])
{
	FILE *p1, *p2;
	if(argc != 3)
	{
		printf("usage:delzw cource filename target file name\n");
		exit(1);
	}
	if((p1 = fopen(argv[1],"rb")) == NULL)
	{
		printf("cannot open the file %s!\n", argv[1]);
		exit(1);
	}
	if((p2 = fopen(argv[2], "wb")) == NULL)
	{
		printf("cannot open the file %s!\n", argv[2]);
		exit(1);
	}
	Decompress(p1, p2);
	fclose(p1);
	fclose(p2);
	return 0;
}
