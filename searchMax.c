#include <stdio.h>

//��ָ����Χ�ڲ������ֵ 

int max(int a, int b)
{
	return a > b ?a:b;
}

int findMax(int a[], int indx,int indx2)
{
	int m = (indx+indx2) / 2;
	int u,v,x;
	if(indx == indx2 - 1)
		return a[indx];
	else{
		u = findMax(a,indx,m);//�ݹ����ǰ�벿�ֵľֲ����� 
		v = findMax(a,m,indx2);//�ݹ�����벿�ֵľֲ����� 
		x = max(u, v);
	}
	return x;
}
int main()
{
	int a[] = {1,4,32,52,234,234,234,234,232,523,5235,235634,6};
	
	int b = findMax(a,0,5);
	printf("%d\n",b);
	return 0;
}
