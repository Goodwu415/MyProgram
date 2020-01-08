#include <stdio.h>

void sort(int *pa, int n);
int main()
{
	int i;
	int *pa = NULL; 
	int a[10]= {43,23,1,2,32,443,555,66,2,4};
	pa = a;
	printf("Î´ÅÅĞò£º"); 
	while(i < 10)
	{
		printf("%d ",a[i]);
		i++; 
	}
	printf("\n");
	
	sort(pa, 10);
	i = 0;			//ÖØÖÃindex 
	printf("ÒÑÅÅĞò£º");
	while(i < 10)
	{
		printf("%d ",a[i]);
		i++;
	}
	
	return 0;
}
void sort(int *pa, int n)
{
	int i,j,k;
	for(i = 0; i < n-1; i++)
		for( j = i; j < n; j++)
		{
			if(*(pa+i) > *(pa+j))// > ÉıĞò  < ½µĞò 
			{
				k = *(pa+i);
				*(pa+i) = *(pa+j);
				*(pa+j) = k;
			}
		 } 
}
