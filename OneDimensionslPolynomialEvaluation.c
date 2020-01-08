#include <stdio.h>

/*
	n:����ʽ������
	double a[]:���n-1�ζ���ʽ��n��ϵ��
	double x��ָ�����Ա���ֵ 
	return:���ض���ʽֵp(x) 
*/

double plyv(double a[],int n,double x)
{
	int i;
	double u;
	u = a[n - 1];
	for(i = n - 2; i >= 0; i--) 
	{
		u = u * x + a[i];
	}
	return u;
}
int main()
{	
	int i;
	double a[7] = {-20.0, 7.0, -7.0, 1.0, 3.0, -5.0, 2.0};
	double x[6] = {0.9, -0.9, 1.1, -1.1, 1.3, -1.3};
	printf("\n");
	for(i = 0; i <= 5; ++i)
	{
		printf("x(%d)=%5.2lf p(%d)=%13.7e\n",\
			i, x[i], i, plyv(a, 7, x[i]));
	}
	printf("\n");
	return 0;
}
