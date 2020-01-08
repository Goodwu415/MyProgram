#include <stdio.h>
//实现环形队列   ,没完成 
//特别说明： -1 为无效数据 
const int N = 10;

int cleanEchoSize = 5;//每次清除缓存的大小 


void insert(int da);//插入数据
int hIndex,tIndex;
int* pA = NULL;
int* ph = NULL;
int* pl = NULL; //头指针，尾指针
int count = 0; //记录数组元素大小 
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
		printf("缓存已满，开始清理！\n");
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

