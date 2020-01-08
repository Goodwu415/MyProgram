#include <stdio.h>
#include <string.h> 
int main()
{
	
	char material[100][10];
	FILE *fp;
	if ((fp=fopen("E:\\代码管理\\Clanguage\\有趣的code\\brotherataskData.txt","rt"))==NULL)
	{
		printf("error\n");
		getch();
		
	}
	
	
	int i=0,j=0;
	char ch;
	ch = fgetc(fp);
	while(	ch != EOF)
	{
		if(	ch != '\n')
		{
			material[i][j] = ch;
			j++;
		}else{
			i++;
			j = 0;
		}
		ch = fgetc(fp);
	}
	
//	for(i=0; i<4;i++)
//	{
//		printf("%s\n",material[i]);
//	}
	
	fclose(fp);
	int len = strlen(material);
	printf("%d\n",len);
	return 0;
}
