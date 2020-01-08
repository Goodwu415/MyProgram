#include <stdio.h>
#include <string.h>
//幂运算 
int int_pow(int x, int y)
{
	int i, result =1;
	for(i = 1; i <= y; ++i)
	{
		result *= x;
	}
	return result;
}

//将十进制转换为任意进制
void dtox(int dnum, int jz) 
{
	char xnum[100];//保存目标进制的各位数 
	int i= 0, j =0;
	while(dnum >= jz) //用除模取余法计算对应进制的各位
	{
		if(dnum % jz <= 9)	
		{
			xnum[j++] = dnum % jz + 48;//0~9之间的数 ，48：0对应的ASCLL值 
		}else	//16进制 
			{//dnum% jz - 10:在0~5的范围内，加上'A' 的ASCLL值，得到A~F范围内的大写字母。 
			xnum[j++] = dnum% jz - 10 + 'A';
		} 
		dnum = dnum / jz; 
	}
	//计算小于进制数的数。 
	if(dnum <= 9)
		xnum[j] = dnum + '0';//0 ~ 9之间的数
	else
		xnum[j] = dnum - 10 + 'A';//超过9的数组大写字母表示 
	for(i = j; i >= 0; i--)
	{
		printf("%c", xnum[i]);
	}
	printf("\n");
	
}
//将输入的数转换为十进制 
int xtod(char num[], int jz) 
{
	int dnum = 0, i, n =0, b;//n：保存输入的数的位数 
	for(i = 0; ; i++)//获取输入的数的位数 
	{
		if(num[i] == '\0')break;
		else n++;
	}
	for(i = n -1; i >= 0;i--)
	{
		if(num[n-i-1] >= 'a')
			b = num[n-i-1]-'a'+10;
		else if(num[n-i-1] >= 'A')
			b = num[n-i-1] - 'A'+10;
		else
			b = num[n-i-1]-'0';
		dnum = dnum + b*int_pow(jz,i);
	}
	return dnum;
}
int main()
{
	char num[100];
	int jz1, jz2;
	
	jz1 = 10;//规定输入的是十进制数 
	jz2 = 8;// 规定转换的是八进制数 
	
	while(scanf("%s", num) != EOF)
	{
		dtox(xtod(num, jz1), jz2);
	}
	return 0;
}
