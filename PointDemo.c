#include <stdio.h>

//指针函数声明 
int * GetValue();
int * SetValue(int i);//指针函数难道不可以传引用参数？ 
//函数指针
float Plus(float f1, float f2);
float Minus(float f1, float f2);
float Multiply(float f1, float f2);
float Divide(float f1, float f2);
float MathFunc(float (*p)(float,float), float para1, float para2);
int main()
{
	char a = 'a', b = 'b',c = 'c';
	char *p[] = {&a,&b,&c};
	char *pa = &a;
	char ** pd = &pa;//二级指针， &取地址 
	char ** pp = p;	//数组名就是一个数组地址 
	
	int i;
	for(i = 0; i < 3; ++i)
		printf("%c ",*p[i]);
	printf("\n *p = %c ",*pa);// 变量a 
	printf("\n *pp = %c ",*pp);// 二级指针所指的指针变量 
	printf("**pp = %c ",**pp);//一级指针变量指向的变量 
	
	printf("一些关于指针函数和函数指针的示例\n");
	
	printf("指针函数：%d\n",*GetValue()); 
	printf("指针函数No.2: %d \n",*SetValue(12));
	printf("接下来是，函数指针的一些应用方式\n");
	
	float af = 0.0,bf = 2.5;
	printf("\na+b=%f",MathFunc(Plus,af,bf));
	printf("\na-b=%f",MathFunc(Minus,af,bf));
	printf("\na*b=%f",MathFunc(Multiply,af,bf));
	printf("\na/b=%f",MathFunc(Divide,af,bf));
	
	return 0;
}
float Plus(float f1, float f2)
{
	return f1 + f2;
}
float Minus(float f1, float f2)
{
	return f1 - f2;
}
float Multiply(float f1, float f2)
{
	if(f1 != 0 && f2 != 0)
		return f1 * f2;
	else{
		return 0;
	}
}
float Divide(float f1, float f2)
{
	if(f1 != 0 && f2 != 0)
		return f1 / f2;
	else
	{
		return 0;
	}
}
float MathFunc(float (*p)(float,float), float para1, float para2)
{
	return (*p)(para1,para2);
}
int * SetValue(int i) 
{
	//static int b = i;//在指针函数里，不可以创建一个需要参数来初始化的变量。 
	static int b = 0;
	b = i;
	return &b; 
}
int * GetValue()
{
	static int a = 110;
	return &a;//返回临时变量的地址，看看有没有错。需要使用static修饰为静态的。 
}
