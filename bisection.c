#include <stdio.h>
#include <Math.h>
//0.1
//2^x + 3x =7
//2^x + 3x -7 = 0
//f(x) = 2^x + 3x -7
static double my1;
double func(double x);
void bisection(double accuracy,double x1,double x2)
{

	double x = x1 + x2 /2;
	double y = func(x);
	int D = abs(x-x1);
	
	if(y==0){
		printf("%ld\n",x);
		return ;
	}
	if(D<accuracy)
	{
		printf("%ld\n",x);
		return ;
	}
	if(my1 * y<0)
	{
		x2 = x;
		bisection(0.1,x1,x2);
	}else{
		
		x1=x;
		my1=y;
		bisection(0.1,x1,x2);
	}
}
double func(double x)
{
	double value = pow(2,x) + 3*x -7;
	return value;
}
int main()
{
	double x1,x2,accuracy=0.1;
	x1 = 1.0;
	x2 = 2.0;
	my1 = func(x1);
	bisection(accuracy,x1,x2);
	
	return 0;
}
