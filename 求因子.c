#include <stdio.h>
#include <math.h>
int y( int pn);

int main(void)
{
	int s;
	int pn;
	scanf("%d",&s);
	
	int i,j;
	for( pn=2;pn<=s;  ) {	
		if( pn%10==6||pn%10==8 ||pn%10==4 ) {
		y(pn);		
		}
		pn+=2;
	}
	return 0;
 } 
 
int  y( int pn)
{
    int a[100],k=0;
	int q;
	int sum=0;
	int i,j,s,t=1;
	for( i=1;i<=pn;i++ ) {
		for( j=1;j<=pn;j++ ) {
			t++;
			if( (i*j)==pn ) {
				if( i!=pn ) {
					a[k]=i;
					k++;
					sum+=i;
						if( pn==sum ) {	
		printf("%d its factors are ", pn);
		for( s=0;s<k;s++ ) {
			printf("%d ",a[s]);
		}
		printf("\n");
		}

			}
		}
	}

}
	return sum;
}
