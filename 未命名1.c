#include <stdio.h>


double Sqrt(double a,double p)//a是被开平方根数，p是所求精度
 
{
    double x=1.0;double cheak;
    do
   {
        x = (a / x + x) / 2.0;
        cheak = x * x - a;
    } while((cheak >= 0 ? cheak : -cheak) > p);
    return x;
}
 
int main()
{
	int a;
	scanf("%d",&a);
	
    printf("%.3f\n",Sqrt(a,0.00001));
    //printf("%.3f\n",Sqrt(4,0.00001));
    return 0;
}

