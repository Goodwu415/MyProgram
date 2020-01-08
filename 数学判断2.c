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
	
	int len,len2=i;//题量，i+1;从0开始计数，所以+1； 
	char temp;
	int temp1; //数字 1 
	int sum=0; //答对题量 
	int a,b,c; //a+b=c
//	printf("%d\n",len2);
//	
//	for ( i=0; i<len2; i++)
//	{
//		printf("%s\n",material[i]);
//	}
	for ( i=0; i<len2; i++)
	{
		int z = 1; //位数 。个位，十位，百位 
		int x = 0; //判断现在应该给谁赋值 
		int state = 0;
		a=b=c=0;
		
		len = strlen(material[i]);	 //求题目长度 
		
		for ( j=len-1; j>=0; j--)
		{
			temp1 = 0;	//初始化 
			temp = material[i][j]; //赋一次值 
			if( temp == '?' ||temp == '\n') break;  
			if ( temp == '-') state=1; //判断加减号 ,改变state状态 
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
 		if(a-b==c)//减法 
 		{
 			return 1;	//正确 
		}else{
			return 0; //错误 
		}
	}else{
		if(a+b == c)//加法 
		{
			return 1;//正确
		}else
		{
			return 0;//错误
		}
		
	}
 }
 
