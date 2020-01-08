#include <stdio.h>

void insertSort(int* nums, int size)
{
	int index;//指向子序列的第后一个元素
	int i;
	int j;
	for(i = 1; i < size; ++i)
	{
		j = i;
		for(index = i-1;index >= 0; index--)
		{
			if(nums[j] < nums[index])
			{
				int tmp = nums[index];
				nums[index] = nums[j];
				nums[j] = tmp;
				j = index;
			}else
			{
				break;
			}
		}		
	}	
}
int main()
{
	int i;
	int a[] = {3,4,62,8,6,346,8,345,345,23,1,2,3,6,7};
	insertSort(a, sizeof(a)/sizeof(int));
	for(i = 0; i < sizeof(a)/sizeof(int); ++i)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
