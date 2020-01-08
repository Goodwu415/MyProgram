#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int r=0;
	int i=0;
	srand((unsigned)time(NULL));
	while(i++<10) {
		printf("r=%d\n",rand()%10);
	}
	return 0;
}
