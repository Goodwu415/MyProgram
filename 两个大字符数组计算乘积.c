#include <stdio.h>
#include <malloc.h>
//�����ַ��������˻��� 
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
	for(i = 0; i<220;i++)	//��ʼ�� 
		sum[i] = 0;
	
	for(j = 0; num2[j] != '\0'; j++ )
	{
		k = j+1;
		size++;	//��¼����Ĵ�С 
		for(i = 0; num1[i] != '\0'; i++)
		{
			sum[k] += (num1[i]-'0') * (num2[j] - '0');
			k++; 
		}
	}
	size += i;//��������Ĵ�С�ĺ� 
	//�����ڴ� 
	result = (char*)malloc(sizeof(char)*size+1);
	
	for(i = size-1; i > 0; i--)//����ÿλ��˵Ľ���� 
	{
		sum[i-1] += sum[i]/10; //��λ 
		sum[i] %= 10; // ��λ���µ��� 
	}
	i = sum[0] > 0 ? 0:1;	//�жϵ�һ��Ԫ���Ƿ�ʹ�� 
	j = 0;//��ʼ������ 
	for(; i < size; i++,j++) 
	{
		result[j] = sum[i] + 48;//int +48 �õ��ַ����ֵ�ASCLLֵ 
	}
	result[j] = '\0';//������ 
	return result;
}


int main()
{
	int i;
	char a[] = {'2','\0'};//��һλ��ʱ���� 
	char b[] = {'3','\0'};
	
	char* c = multiply(a,b);
	for(i = 0; c[i] != '\0'; i++) 
	{
		printf("%c ",c[i]);
	}
	return 0;
}
