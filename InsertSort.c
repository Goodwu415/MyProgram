#include <stdio.h>

int main()
{
	int n,m;
	int i,j,k,v;	// v  
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
		else if(a[i] > 1000)
			a[i] = 1000;
	}
	for(k = 0; k < n-1; k++)
	{
		printf("%d ", a[k]);//输出数组元素，到<n-1 
	}
	printf("%d\n",a[k]);	//输出 n-1 元素，也就是最后一个 
	
	for(i = 1; i < n; i++)
	{
		v = a[i];	// 取出下标为i的元素 
		j = i - 1;	 
		while(j >= 0 && a[j] > v) //下标j要大于0，并且a[j]的元素必须大于a[i]的元素。 
		{
			a[j+1] = a[j];	 
			j--;		// 条件成立，继续查看数组前面的数是否大于 v. 
		}
		a[j+1] = v;		//这条语句是当这个条件(j >= 0 && a[j] > v)中的某一个不成立时，
						// 无以言表 
		for(k = 0; k < n-1; k++)
		{
			printf("%d ", a[k]);
		}
		printf("%d\n",a[k]);
	}
	return 0;
}
