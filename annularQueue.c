#include <stdio.h>
//实现环形队列
//特别说明： -1 为无效数据 
const int N = 10;

int cleanEchoSize = 5;//每次清除缓存的大小 
int phIndex = 0,plIndex = 0;//记录头尾指针的下标 
void cleanEcho(int size);//清除最早输入的数据,并调整指针的指向。 
void insert(int da);//插入数据
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
	while(scanf("%d",&da) != EOF)
	{
		insert(da);
	}
	 
	return 0;
}
void insert(int da)
{
	if(count == N)//pl指向的下一个地址不是ph 
	{
		printf("缓存满了，开始清除缓存！\n");
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
	printf("被清除的数据:"); 
	for(i = 0; i < size;++i) //清理缓存 
	{
		printf(" %d",*ph);
		phIndex++;
		if(phIndex < N)
		{
			*ph++ = -1;
			
		}else
		{
			*ph = -1;//处理当前元素是最后一个元素的情况 
			phIndex = 0;
			ph = pA;
		}
		
	}
	printf("\n");

}
