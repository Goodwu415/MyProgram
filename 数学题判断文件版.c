#include <stdio.h>
#include <string.h>

#define N 100
int judge(int a,int b,int c,int st);
int main()
{
	char material[N][10];

	int i,j;
	FILE *fp;
	if ((fp=fopen("E:\\�������\\Clanguage\\��Ȥ��code\\brotherataskData.txt","rt"))==NULL)
	{
		printf("error\n");
		return;
		
	}
	i=0,j=0;
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
	fclose(fp);
	
	int len,len2;
	char temp;
	int temp1; //���� 1 
	int sum=0; //������� 
	int a,b,c; //a+b=c
	len2 = i+1; //������i+1;��0��ʼ����������+1�� 
	//int len1 = strlen(material[2]);
	//printf("%d\n",len1);
	for ( i=0; i<len2; i++)
	{
		int z = 1; //λ�� 
		int x = 0;
		int state = 0;
		a=b=c=0;
		
		len = strlen(material[i]);	 //����Ŀ���� 
		
		for ( j=len-1; j>=0; j--)
		{
			temp1 = 0;	
			temp = material[i][j]; //��һ��ֵ 
			if( temp == '?' ) break;
			if ( temp == '-') state=1; //�жϼӼ��� 
			switch(temp)
			{
				case '1':
					temp1 = 1*z;
					
					
					break;
				case '2':
					temp1 = 2*z;
					break;
				case '3':
					temp1 = 3*z;
					break;
				case '4':
					temp1 = 4*z;
					break;
				case '5':
					temp1 = 5*z;
					break;
				case '6':
					temp1 = 6*z;
					break;
				case '7':
					temp1 = 7*z;
					break;
				case '8':
					temp1 = 8*z;
					break;
				case '9':
					temp1 = 9*z;
					break;
				case '0':
					temp1 = 0;
					z = z*10;
					break;
				default:
					z = 1;
					x++;
			}
			if(x == 0)
			{
				c += temp1; 
			}else if(x == 1)
			{
				b += temp1;
			 }else{
			 	a += temp1;
			 } 		
			if(temp1 > 0) z = z*10;
			
		}
		if(judge(a,b, c, state))
		{
			sum++; 
		}
	}
	printf("%d\n",sum);
	
	return 0;
 } 
 int judge(int a,int b,int c,int st)
 {
 	if(st)
 	{
 		if(a-b==c)//���� 
 		{
 			return 1;	//��ȷ 
		}else{
			return 0; //���� 
		}
	}else{
		if(a+b == c)//�ӷ� 
		{
			return 1;//��ȷ
		}else
		{
			return 0;//����
		}
		
	}
 }
 // = {
//						{'1','+','1','3','=','1','4'},{'1','2','+','3','3','=','?'},	//�� 
//						{'1','+','9','9','=','1','0','0'},
//						{'9','-','9','=','0'},//�� 
//						{'9','9','+','9','9','=','1','9','8'}, //�� 
//						{'9','+','9','=','1','8'}, //�� 
//						{'1','2','-','1','2','=','0'},//�� 
//						{'9','-','3','=','6'},//�� 
//						{'1','2','+','3','1','=','4','5'},//�� 
//						{'1','2','-','9','3','=','4','5'},	//�� 
//						{'1','2','+','3','5','=','4','5'},{'1','2','+','3','3','=','4','5'},
//						{'1','2','+','3','1','=','4','5'},{'1','2','+','3','3','=','4','5'},
//						{'1','3','+','3','3','=','4','5'},{'1','2','+','3','3','=','4','5'},
//						{'1','4','+','3','3','=','4','5'},{'3','2','-','1','3','=','1','9'},
//						{'1','5','+','3','3','=','4','5'},{'2','2','-','1','3','=','9'}
//							}; 
