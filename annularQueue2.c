#include <stdio.h>
//ʵ�ֻ��ζ���   ,û��� 
//�ر�˵���� -1 Ϊ��Ч���� 
const int N = 10;

int cleanEchoSize = 5;//ÿ���������Ĵ�С 


void insert(int da);//��������
int hIndex,tIndex;
int* pA = NULL;
int* ph = NULL;
int* pl = NULL; //ͷָ�룬βָ��
int count = 0; //��¼����Ԫ�ش�С 
int main()
{

	int A[N];
	int da;
	pA = A;
	ph = A;
	pl = A;
	hIndex = 0;
	tIndex = 0;
	while(scanf("%d",&da) != EOF)
	{
		insert(da);
	}
	 
	return 0;
}
void insert(int da)
{

	*(pl+tIndex) = da;
	tIndex = (tIndex + 1) % N; 
	if((tIndex + 1) == hIndex)
	{
		printf("������������ʼ����\n");
		if(hIndex + cleanEchoSize < N)
		{
			hIndex += cleanEchoSize;
		}else
		{
			hIndex = (hIndex + cleanEchoSize) - N;
		}
		ph = (pA+hIndex);
	}
}

