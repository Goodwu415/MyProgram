#include <stdio.h>
#include <io.h>
#include <stdlib.h>

#define bsize 1024

void createfile();
void fileCopy(char *pn,char *pn2);
void removeflie(char *pf);
int main(int argc, char *argv[])
{
	//fileCopy(argv[1],argv[2]);
	char *p = "1.txt";
	//createfile();
	removeflie(p);
	return 0;
}
void removeflie(char *pf)
{
	int i;
	char ch;
	printf("�Ƿ����ɾ���ļ�%s(Y/N)?", pf);
	scanf("%c",&ch);
	if(ch == 'Y' || ch == 'y')
	{
		if(remove(pf) != 0)
			printf("ɾ���ļ�%sʧ�ܣ�\n", pf);
		else
			printf("ɾ���ļ��ɹ���\n");
	}		
	
}
void fileCopy(char *pn,char *pn2)
{
	int i,b;
	FILE *f1,*f2;
	char buf[bsize];
	if((f1 = fopen(pn, "wb")) == NULL)
	{
		printf("�����ļ�%sʧ�ܣ�\n",pn);
		return;
	}
	//for(i = 1; i < )
	if((f2 = fopen(pn2, "rb")) == NULL)
	{
		printf("���ļ�%sʧ��!\n", f2);
		return;
	}
	while((b = fread(buf, sizeof(char), bsize,f2)) > 0)//�ļ�����
	{
		fwrite(buf, sizeof(char), b, f1);
		printf("���Ƴɹ���\n");
	 }
	 fclose(f1);
	 fclose(f2);
	
}
void createfile()
{
	int h;
	char filename[20];
	//char *filename = "4.txt";
	while(1)
	{
		printf("������Ҫ�������ļ�����");
		scanf("%s",filename);
		if(h = creat(filename,0) == -1)
		{
			printf("\n �ļ��Ѵ��ڻ�·������\n");	
		}else {
			printf("�ļ������ɹ���\n");
			close(h);
			break;
		}
	}
}

