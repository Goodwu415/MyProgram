#inlcude <stdio.h>

int main()
{
	int a[10]={54,34,24,99,55,46,31,21,13,64};
	int x,i=1,j=9,temp;
	int *p=a;
	int *q=a;
	
	while ( )
	{
		if ( *(p+i)>*(q+j-1) )
		{
			temp=*(q+j-1);
			*(q+j-1)=*(p+i);
			*(p+i)=temp;
			}
		}
	}
	for ( i=0; i<10; i++ )
	{
		printf("%d ",*(p+i))
	}
	
	return 0;
}
