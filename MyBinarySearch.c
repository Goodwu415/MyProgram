#include <stdio.h>
// 搜索两个数组中相同的元素，并计数。二分搜索 
int main()
{
	int n,q,m;
	int a[n],b[q];
	int i;
	int mid,left,right;
	int mid2,left2,right2;
	int count = 0;
	scanf("%d",&m);
	if(m > 100000)
		n = 100000;
	else if( m < 0)
		n = 1;
	else n = m;
	for(i = 0; i < n; i++)
	{
		scanf("%d ",&a[i]);
	}
	scanf("%d",&m);
	if(m > 50000)
		q = 50000;
	else if( m < 0)
		q = 1;
	else q = m;
	for(i = 0; i < q; i++)	
	{
		scanf("%d",&b[i]);
	}

	
	for(i = 0; i < q; i++)
	{
		mid = n / 2;
		left = 0;
		right = n;
		while(left < right)
		{
			if(b[i] == a[mid])
			{
				count++;
				break;
			}else if(b[i] > a[mid])
			{
				left = mid + 1;
				//mid = (left + right) / 2;
			 }else
			 	right = mid -1;
			 	//mid = 
			mid = (left + right) / 2;
		}
	}
	printf("%d", count);
	
	return 0;
} 
