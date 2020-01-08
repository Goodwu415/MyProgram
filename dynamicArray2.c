#include <stdio.h>
#include <stdlib.h>


static int Length = 10;
static int size = 0;
static int growth;
static int count = 0;
int* array = NULL;
int* create();//创建数组 
void insert(int i);
void erase(int i);// i 要删除的元素值
int* grow(int* pt); //给上一个数组的指针，返回一个指向增长了数组的指针 
int main()
{
	array = create();
	int i,j;
	for(j = 0; j < 10000; ++j)
	{
		
		for(i = 0; i < 10; ++i)
		{
			insert(i+2);
		}
	}
	for(i = 0; i < size; ++i)
	{
		printf("%d ",*(array+i));
	}
	printf("\n%d : %d : %d\n", size, Length, count);
	return 0;
}
int* create()//创建数组 
{
	int* pt = (int*)malloc(sizeof(int) * Length);
	if(pt != NULL)
		return pt;
} 
void insert(int i)
{
	if(Length - size < 3)
	{
		growth = Length + size;
		Length = growth;
		array = grow(array);
	}
	array[size++] = i;
}
void erase(int i);// i 要删除的元素值
int* grow(int* pt)
{
	int *ptt = (int*)malloc(sizeof(int) * growth);
	
	int i;
	for(i = 0; i < size; ++i)	
	{
		ptt[i] = pt[i];
	}
	free(pt);
	pt = NULL;
	++count;
	if(ptt != NULL)
		return ptt;
} 
