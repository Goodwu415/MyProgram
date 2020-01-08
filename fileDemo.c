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
	printf("是否真的删除文件%s(Y/N)?", pf);
	scanf("%c",&ch);
	if(ch == 'Y' || ch == 'y')
	{
		if(remove(pf) != 0)
			printf("删除文件%s失败！\n", pf);
		else
			printf("删除文件成功！\n");
	}		
	
}
void fileCopy(char *pn,char *pn2)
{
	int i,b;
	FILE *f1,*f2;
	char buf[bsize];
	if((f1 = fopen(pn, "wb")) == NULL)
	{
		printf("创建文件%s失败！\n",pn);
		return;
	}
	//for(i = 1; i < )
	if((f2 = fopen(pn2, "rb")) == NULL)
	{
		printf("打开文件%s失败!\n", f2);
		return;
	}
	while((b = fread(buf, sizeof(char), bsize,f2)) > 0)//文件复制
	{
		fwrite(buf, sizeof(char), b, f1);
		printf("复制成功！\n");
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
		printf("请输入要创建的文件名：");
		scanf("%s",filename);
		if(h = creat(filename,0) == -1)
		{
			printf("\n 文件已存在或路径错误！\n");	
		}else {
			printf("文件创建成功！\n");
			close(h);
			break;
		}
	}
}

