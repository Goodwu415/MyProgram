#include <stdio.h>

// ϣ������
 
int main()
{
	int a[10];
	int i,j,k = 10,t;
	
	printf("������10����������֮���ÿո������\n");
	for(i = 0; i < 10; i++)
	{
		scanf("%d",&a[i]);
	}
	while(k > 0)	
	{
		for(i = k; i < 10; i++)
		{
			j = i - k;
			while(j >= 0)
				if(a[j] > a[j+k])
				{
					t = a[j]; a[j] = a[j+k]; a[j+k] = t;
				}else break;
		}
		k /= 2;
	}
	for(i = 0; i < 10; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
