#include <stdio.h>
#include <string.h>

#define N 103
int judge(int a,int b,int c,int st);
int main()
{
	char material[N][12];

	int i=0,j=0;
	char c2;
	while( (c2=getchar()) != EOF)
	{
		if ( c2 >= '0' && c2 <= '9' || c2 == '=' || c2 == '+' || c2 == '-' || c2 == '?')
		{
			material[i][j] = c2;
			j++;
		}else{
			material[i][j] = '\0';
			i++,j=0;
		}
	}	
	
	int len,len2=i;//������i+1;��0��ʼ����������+1�� 
	char temp;
	int temp1; //���� 1 
	int sum=0; //������� 
	int a,b,c; //a+b=c
//	printf("%d\n",len2);
//	
//	for ( i=0; i<len2; i++)
//	{
//		printf("%s\n",material[i]);
//	}
	for ( i=0; i<len2; i++)
	{
		int z = 1; //λ�� ����λ��ʮλ����λ 
		int x = 0; //�ж�����Ӧ�ø�˭��ֵ 
		int state = 0;
		a=b=c=0;
		
		len = strlen(material[i]);	 //����Ŀ���� 
		
		for ( j=len-1; j>=0; j--)
		{
			temp1 = 0;	//��ʼ�� 
			temp = material[i][j]; //��һ��ֵ 
			if( temp == '?' ||temp == '\n') break;  
			if ( temp == '-') state=1; //�жϼӼ��� ,�ı�state״̬ 
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
			if(judge(a,b, c, state))
			{
				sum++; 
			}
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
 
