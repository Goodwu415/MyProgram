#include <stdio.h>
//ʵ�ֻ��ζ���
//�ر�˵���� -1 Ϊ��Ч���� 
const int N = 10;

int cleanEchoSize = 5;//ÿ���������Ĵ�С 
int phIndex = 0,plIndex = 0;//��¼ͷβָ����±� 
void cleanEcho(int size);//����������������,������ָ���ָ�� 
void insert(int da);//��������
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
	while(scanf("%d",&da) != EOF)
	{
		insert(da);
	}
	 
	return 0;
}
void insert(int da)
{
	if(count == N)//plָ�����һ����ַ����ph 
	{
		printf("�������ˣ���ʼ������棡\n");
		cleanEcho(cleanEchoSize);
	}
	*pl = da;
	++plIndex;
	if(plIndex < N)
	{
		++pl;
	
	}else
	{
		pl = pA;
		plIndex = 0;
	}
	++count;
}
void cleanEcho(int size)
{
	int i;
	count -= size;
	printf("�����������:"); 
	for(i = 0; i < size;++i) //������ 
	{
		printf(" %d",*ph);
		phIndex++;
		if(phIndex < N)
		{
			*ph++ = -1;
			
		}else
		{
			*ph = -1;//����ǰԪ�������һ��Ԫ�ص���� 
			phIndex = 0;
			ph = pA;
		}
		
	}
	printf("\n");

}
