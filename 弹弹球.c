#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void qiu(void);

int main()
{
	
	int bottom = 10;
	int i,j;
	
	while ( 1 )
	  {
	  	system("cls");
  		printf("_________________________________\n");
  		qiu();
		for ( j=1; j<bottom; j++ )
			
			printf("                                 |\n");
			if ( j==10 )	
			printf("_________________________________|\n");
			
			
	}
		
//		for ( i=1; i<x; i++ )
//			printf("\n");
//		for ( j=1; j<y; j++ )
//			
//			printf(" ");
//			printf("________________________________\n");	
	  
	

	
	return 0;
}
void qiu( void)
{
	int x=0,y=5;
	int i,j;
	int velocity_x=1;
	int velocity_y=1; 
	int left=0;
	int right=20;
	int top=0;
	int bottom = 10;
		x = x+velocity_x;
	  	y = y+velocity_y;
	  		
	  		for ( i=1; i<x; i++ )
			
			 printf("\n"); 
			for ( j=1; j<y-1; j++ )	
			printf(" "); 
			printf("O");
			printf("\n");
			Sleep(100);	 
		if (( x==top)|| (x==bottom))
		velocity_x= -velocity_x;
		if (( y==left)|| ( y== right ))
		velocity_y = -velocity_y;
}
