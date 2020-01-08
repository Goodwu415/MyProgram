#include <stdio.h>
#include <math.h>
#define PI acos(-1)

#define MaxValue 1.79769313486232E+308

int random(int m);//随机整数
double RandDouble(int min, int max);
double MyNum();
double (*Fun)(double x);	//函数指针
double Integral(double (*f)(double x), double a, double b, double eps); //积分计算 
double Linear(double a);
int main()
{
	Fun = sin; //函数指针 指向一个函数地址
	double d = Integral(Fun, 0,PI / 2, 1e-4);
	printf("%.2lf\n", d);
	
	Fun = Linear;
	double d2 = Integral(Fun, 0, 2, 1e-3);
	printf("%.2lf\n", d2);
	
	double d3 = Integral(MyNum, 0, 1, 0.01);
	printf("%.2lf\n", d3);
	int i, j;
	for(i = 0; i < 10; i++)
		printf("%d ", i);
	printf("%d\n",i);
	for(j = 0; j < 10; ++j)
		printf("%d ",j);
	printf("%d\n",j);
	return 0;
}
double MyNum()
{
	return RandDouble(0.0,1.0);
}
double RandDouble(int min, int max)//随机浮点数 
{
	double m1 = (double)(rand() % 101) / 101;// 计算 0，1之间的随机小数,得到的值域近似为(0,1)
	min ++;
	double m2 = (double)((rand() % (max - min + 1)) + min);//计算 min+1,max 之间的随机整数，得到的值域为[min+1, max]
	m2 = m2 -1;
	return m1 + m2;
}
int random(int m)
{
	return rand() % m;	//将随机数控制在0 ~ m-1之间 
}
double Linear(double a)
{
	return a * 2 + 1;
}
double Integral(double (*f)(double x), double a, double b, double eps)
{
	int n, k;
	double fa, fb, h, t1, p, s, x, t = 0;
	
	fa = (*f)(a);
	fb = (*f)(b);
	
	//迭代初值
	n = 1;
	h = b - a;
	t1 = h *(fa + fb)/2.0;
	p = MaxValue;
	
	//迭代计算
	while(p >= eps)
	{
		s = 0.0;
		for(k = 0; k <= n-1; ++k)
		{
			x = a +(k + 0.5) * h;
			s = s + (*f)(x);
		}
		t = (t1 + h * s)/ 2.0;
		p = abs(t1 - t);
		t1 = t;
		n = n + n;
		h = h / 2.0;
	}
	return t;	
}
