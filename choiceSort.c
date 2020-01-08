#include <stdio.h> 

int main()
{
	int n,m;
	int i,j,minj,count = 0,tmp = 0;	//tmp需要初始化，不然会出错，可能是因为count初始化了。 
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

	for(i = 0; i < n; i++)
	{
		minj = i;
		for(j = i+1;j < n; j++)
		{
			if(a[j] < a[minj])
				minj = j;
		}
		if(minj != i)
		{
			tmp = a[i];
			a[i] = a[minj];
			a[minj] = tmp;
			count++;
		} 
	}
	for(i = 0; i < n; i++)
	{
		if(i > 0)printf(" ");
		printf("%d",a[i]);
	}
	printf("\n%d",count);
	return 0;
}
