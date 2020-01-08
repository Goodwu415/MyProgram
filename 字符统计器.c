#include <stdio.h>


int main()
{
	char q;
	int y=0,s=0,k=0,z=0;
	
	while ( (q=getchar())!='\n' ) {
		if( q>='A'&&q<='Z'||q>='a'&&q<='z' ) {
				y++; 
		} else if( q>='0'&&q<='9' ) {
				s++;
		} else if( q==' ') {
				k++;	
		} else {
				z++;}
	}

	printf("%d\n%d\n%d\n%d",y,k,s,z);
	
	return 0;
}

