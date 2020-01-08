#include <stdio.h>

int main()
{
	int i,n,f[55];
	while ( scanf("%d",&n) )
	{
		f[1]=1;
		f[2]=2;
		f[3]=3;
		if ( n==0 )
		{
			break;
		}
		if ( n==1 )
		{
		printf("%d\n",f[1]);
		}
		else if ( n==2 )
		{
			printf("%d\n",f[2]);
		}
		else if ( n==3 )
			{
				printf("%d\n",f[3]);
			}
			else {
				for ( i=4; i<=n; i++ )
				{
					f[i]=f[i-1]+f[i-3];
				 } 
				//f[n]=f[n-1]+f[n-3];
				
				 printf("%d\n",f[n]);
			} 
	}
	return 0;	
 }
 
  
