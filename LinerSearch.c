#include <stdio.h>
// 搜索两个数组中相同的元素，并计数。 顺序搜索 
int main()
{
	int n,q,m;
	int a[n],b[q];
	int i,j;
	int count = 0;
	scanf("%d",&m);
	if(m > 10000)
		n = 10000;
	else if( m < 0)
		n = 1;
	else n = m;
	for(i = 0; i < n; i++)
	{
		scanf("%d ",&a[i]);
	}
	scanf("%d",&m);
	if(m > 500)
		q = 500;
	else if( m < 0)
		q = 1;
	else q = m;
	for(i = 0; i < q; i++)	
	{
		scanf("%d",&b[i]);
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < q; j++)
		{
			if(a[i] == b[j]) count++;
		}
	}
	printf("%d",count);
	return 0;
}
