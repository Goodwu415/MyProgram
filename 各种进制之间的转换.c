#include <stdio.h>
#include <string.h>
//������ 
int int_pow(int x, int y)
{
	int i, result =1;
	for(i = 1; i <= y; ++i)
	{
		result *= x;
	}
	return result;
}

//��ʮ����ת��Ϊ�������
void dtox(int dnum, int jz) 
{
	char xnum[100];//����Ŀ����Ƶĸ�λ�� 
	int i= 0, j =0;
	while(dnum >= jz) //�ó�ģȡ�෨�����Ӧ���Ƶĸ�λ
	{
		if(dnum % jz <= 9)	
		{
			xnum[j++] = dnum % jz + 48;//0~9֮����� ��48��0��Ӧ��ASCLLֵ 
		}else	//16���� 
			{//dnum% jz - 10:��0~5�ķ�Χ�ڣ�����'A' ��ASCLLֵ���õ�A~F��Χ�ڵĴ�д��ĸ�� 
			xnum[j++] = dnum% jz - 10 + 'A';
		} 
		dnum = dnum / jz; 
	}
	//����С�ڽ����������� 
	if(dnum <= 9)
		xnum[j] = dnum + '0';//0 ~ 9֮�����
	else
		xnum[j] = dnum - 10 + 'A';//����9�������д��ĸ��ʾ 
	for(i = j; i >= 0; i--)
	{
		printf("%c", xnum[i]);
	}
	printf("\n");
	
}
//���������ת��Ϊʮ���� 
int xtod(char num[], int jz) 
{
	int dnum = 0, i, n =0, b;//n���������������λ�� 
	for(i = 0; ; i++)//��ȡ���������λ�� 
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
	
	jz1 = 10;//�涨�������ʮ������ 
	jz2 = 8;// �涨ת�����ǰ˽����� 
	
	while(scanf("%s", num) != EOF)
	{
		dtox(xtod(num, jz1), jz2);
	}
	return 0;
}
