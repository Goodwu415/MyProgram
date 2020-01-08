#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *infile, *outfile;
void Compress(char *infilename, char *outfilename);
void Common(char *filename);	//ʧ����ʾ


int main(int argc, char * argv[])
{
	printf("rleys compress file\n");
	if(argc != 3)//�ж�����Ĳ�����ʽ�Ƿ���ȷ 
	{
		printf("\n usage:rleys sourcefilename target filename\n");
		exit(0);
	}
	printf("\n compression...");
	Compress(argv[1], argv[2]);	//���ú���ѹ������
	fclose(infile);
	fclose(outfile);
	
	return 0;
}
void Common(char *filename) 
{
	char tempspace[200];
	strcpy(tempspace, "Unable to open");
	strcat(tempspace, filename);
	puts(tempspace);
	exit(0);// �˳����� 
}
void Compress(char *infilename, char *outfilename) 
{
	register int seq_len;
	char cur_char, cur_seq;
	if((infile = fopen(infilename,"rb"))== NULL)//�ж��ļ��Ƿ�򿪳ɹ� 
		Common(infilename);	
	if((outfile = fopen(outfilename,"wb"))== NULL)//�ж��ļ��Ƿ񴴽��ɹ�
		Common(outfilename) ;
	cur_char = fgetc(infile);
	cur_seq = cur_char;
	seq_len = 1;
	while(!feof(infile))//����ѹ�� 
	{
		cur_char = fgetc(infile);
		if(cur_char == cur_seq)
		{
			seq_len++;
		}else
		{
			fputc(seq_len, outfile);
			fputc(cur_seq, outfile);
			cur_seq = cur_char;
			seq_len = 1;
		}
	}
}
