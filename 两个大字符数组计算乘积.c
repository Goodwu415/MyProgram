#include <stdio.h>
#include <malloc.h>
//两个字符数组计算乘积。 
char * multiply(char * num1, char * num2){
	char* result = NULL;
	if(num1 == NULL || num2 == NULL)	
	{
		return result;
	}
	if(*num1 == '0')
		return num1;
	else if(*num2 == '0')
		return num2;
	
	
	int i,j;
	int k;
	int size=0; 
	int sum[220];
	for(i = 0; i<220;i++)	//初始化 
		sum[i] = 0;
	
	for(j = 0; num2[j] != '\0'; j++ )
	{
		k = j+1;
		size++;	//记录数组的大小 
		for(i = 0; num1[i] != '\0'; i++)
		{
			sum[k] += (num1[i]-'0') * (num2[j] - '0');
			k++; 
		}
	}
	size += i;//两个数组的大小的和 
	//分配内存 
	result = (char*)malloc(sizeof(char)*size+1);
	
	for(i = size-1; i > 0; i--)//处理每位相乘的结果， 
	{
		sum[i-1] += sum[i]/10; //进位 
		sum[i] %= 10; // 进位余下的数 
	}
	i = sum[0] > 0 ? 0:1;	//判断第一个元素是否使用 
	j = 0;//初始化索引 
	for(; i < size; i++,j++) 
	{
		result[j] = sum[i] + 48;//int +48 得到字符数字的ASCLL值 
	}
	result[j] = '\0';//结束符 
	return result;
}


int main()
{
	int i;
	char a[] = {'2','\0'};//第一位暂时不用 
	char b[] = {'3','\0'};
	
	char* c = multiply(a,b);
	for(i = 0; c[i] != '\0'; i++) 
	{
		printf("%c ",c[i]);
	}
	return 0;
}
