#include <stdio.h>

typedef struct
{
	char e[10];
	int lenth;
}SS;

int EQ(char a, char b);
int LQ(char a, char b);
int search(SS st, char key);

int main()
{
	SS st;
	
	int i,n;
	char key, c;
	c = 'a';
	st.lenth = 10;
	for(i = 0; i < 10; i++)
	{
		st.e[i] = c++;	//���������ַ��� 
	}
	printf("�ָ��������ַ������£�\n");
	for(i = 0; i < 10; i++)
		printf("%c ", st.e[i]);
	printf("\n��������Ҫ��ѯ��Ӣ����ĸ��");
	scanf("%c",&key);
	n = search(st, key);
	if(n)
		printf("��Ҫ���ҵ���ĸ%c���ַ���ĵ�%d��λ����!\n",key, n);
	else
		printf("��Ҫ���ҵ���ĸ%c�����ַ�����\n");
	
	return 0;
}
int EQ(char a, char b)
{
	if(a == b)
		return 1;
	else 
		return 0;
}
int LQ(char a, char b)
{
	if(a > b)
		return 1;
	else
		return 0;
}
int search(SS st, char key)
{
	int low = 0;
	int high = st.lenth - 1;
	int mid;
	while(low <= high)
	{
		mid = (low + high)/2;
		if(EQ(st.e[mid], key))
			return mid+1;
		else if(LQ(st.e[mid], key))
			high = mid - 1;
		else 
			low = mid + 1;
	}
	return 0;
} 
