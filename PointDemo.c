#include <stdio.h>

//ָ�뺯������ 
int * GetValue();
int * SetValue(int i);//ָ�뺯���ѵ������Դ����ò����� 
//����ָ��
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
	char ** pd = &pa;//����ָ�룬 &ȡ��ַ 
	char ** pp = p;	//����������һ�������ַ 
	
	int i;
	for(i = 0; i < 3; ++i)
		printf("%c ",*p[i]);
	printf("\n *p = %c ",*pa);// ����a 
	printf("\n *pp = %c ",*pp);// ����ָ����ָ��ָ����� 
	printf("**pp = %c ",**pp);//һ��ָ�����ָ��ı��� 
	
	printf("һЩ����ָ�뺯���ͺ���ָ���ʾ��\n");
	
	printf("ָ�뺯����%d\n",*GetValue()); 
	printf("ָ�뺯��No.2: %d \n",*SetValue(12));
	printf("�������ǣ�����ָ���һЩӦ�÷�ʽ\n");
	
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
	//static int b = i;//��ָ�뺯��������Դ���һ����Ҫ��������ʼ���ı����� 
	static int b = 0;
	b = i;
	return &b; 
}
int * GetValue()
{
	static int a = 110;
	return &a;//������ʱ�����ĵ�ַ��������û�д���Ҫʹ��static����Ϊ��̬�ġ� 
}
