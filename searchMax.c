#include <stdio.h>

//在指定范围内查找最大值 

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
		u = findMax(a,indx,m);//递归求解前半部分的局部问题 
		v = findMax(a,m,indx2);//递归求解后半部分的局部问题 
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
