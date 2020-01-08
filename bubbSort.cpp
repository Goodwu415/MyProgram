#include <stdio.h>

int main()
{
	int n,m;
	int i,j,tmp,count = 0,flag = 1;	// v  
	int a[n];
	scanf("%d",&m);
	if(m < 1)
		n = 1;
	else if( m > 100)
		n = 100;
	else
		n = m;
	for(i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
		if(a[i] < 0)
			a[i] = 0;
		else if(a[i] > 100)
			a[i] = 100;
	}
	i = 0;//未排序部分的起始下标 
	while(flag)
	{
		flag = 0;
		for(j = n - 1; j > i; j--)
		{
			if(a[j] < a[j - 1])
			{
				tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
				flag = 1;
				count++;
			}
		}
		i++;
	}
	for(i = 0; i < n; i++)
	{
		if(i > 0) printf(" ");
		printf("%d",a[i]);
	}
	printf("\n%d",count);
	
	return 0;
}
