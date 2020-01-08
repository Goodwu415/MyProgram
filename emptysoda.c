#include <stdio.h>

int sodaBottle(int n)
{
	int sum=0;
	int a=0,b=0;
	a= n/3;
	b = n%3;
	
	int v = 0;
	v=a+b;
	
	if(v == 0 )return a;
	if(v == 2) v+=1;
	if(v >=3 ) sum = sodaBottle(v);
	sum += a;
	
	return sum;
	
}

int main()
{
	int test[10],sum;
	int i;
	for ( i=0; i<10; i++)
	{
		scanf("%d",&test[i]);
		if (test[i] == 0)break;
		while( test[i]>100)
		{
			scanf("%d",&test[i]);
		}
		
	}
	int len = sizeof(test)/sizeof(int);
	for ( i=0; i<len; i++)
	{
		if( test[i] == 0)break;
		if( test[i] >= 1 && test[i] <=100)
		{
			sum = sodaBottle(test[i]);
			printf("%d\n",sum);
		}
	}
	//int soda=1;empty=3;
	
	
	
	
	return 0;
}
