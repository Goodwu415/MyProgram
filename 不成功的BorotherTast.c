#include <stdio.h>

void Add(char b[],int a, int e)
{
	char h[3];
	int i,j,k;
	for ( i=a-1; i>=1; i--)
	{
		for ( j=e; j>a; j--)
		{
			for(k=0; k<9; k++)
			{
				if(b[j] == '0')break;
				b[j] = b[j]-1;
				b[i] = b[i]+1;
//				h[2] = b[i];
//				h[1] = b[i-1];
//				
				if(b[i] > '9')
				{
					b[i] = '0';
					b[i-1] += 1;
					h[2] = b[i-1];
					if(b[i-1] > '9')
					{
						b[i-1] = '0';
						b[i-2] += 1;
						h[0] = b[i-2];
					 } 
				}
			}
		}
	}
	for ( i=0;i<3; i++)
	{
		printf("%c",b[i]);
	}
	
}
int aa(char z, char y)
{
	
	z = z+1;
	y = y-1;
}
void openfile(char c[9])
{
	FILE *fp;
	if ((fp=fopen("E:\\代码管理\\Clanguage\\有趣的code\\brotherataskData.txt","rt"))==NULL)
	{
		printf("error\n");
		getch();
		
	}
	fgets(c,9,fp);
	printf("%s\n",c);
	fclose(fp);
}
int main()
{
	char a[100][10]={{'0','1','+','2','=','3'},{'0','1','9','+','8','8','=','1','0','7'},\
				{'0','1','2','-','2','=','1','0'},{'0','3','-','2','=','3'},\
				{'0','9','1','+','9','9','=','1','9','0'}};
	int i,j;
	int len;
	char *q;
	
	int add=-1,sub=-1,equal=-1;
	
	for ( i=0; i<1; i++)
	{
		
		len = sizeof(a[i])/sizeof(char);
		for ( j=1; j < len; j++)
		{
			if( a[i][j] == '+')
			{
				add = j;
			}else if( a[i][j] == '-')
			{
				sub = j;
			}else if( a[i][j] == '='){
				equal = j;
				break;
			}
		}
		if(add != '0')
		{
			Add(a[i],add,equal);		
		 }else{
		 	Add(a[i],sub,equal);
		 } 
		
	}
	
	printf("\n%d\n%d\n%d\n",add,sub,equal);
	
	
	return 0;
}
