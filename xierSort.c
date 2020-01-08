#include <stdio.h> 
//#include <vector>
int insertSort(int a[],int n,int g);
void shellSort(int a[],int n);

int main()
{
	int n;
	int i;
	int a[n];
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	shellSort(a, n);
	for(i = 0; i < n; i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
void shellSort(int a[],int n)
{
	int i,j;
	int cnt = 0;
	int m = 3;	//获得一个合适的值 
	int g[10];/* = {4,2,1};*///从a[],获取较大的值，和一个最小值。 
	//生成g[]数列
	j=0;
	for(i = 1; ; ) 
	{
		if(i > n)break;
		g[j] = i;
		i = 3 * i + 1;
		j++;
	}
	for(i = j-1; i >= 0; i--)//逆序指定 g[i] 
	{
		cnt += insertSort(a,n,g[i]);
	}
	printf("%d\n",m);
	for(i = 0; i < m; i++)
	{
		if(i > 0)printf(" ");
		printf("%d",g[i]);
	}
	printf("\n%d\n",cnt);
	
}
int insertSort(int a[], int n, int g)
{
	int i,j;
	int v;
	long long cnt = 0;
	for(i = g; i < n; i++)
	{
		v = a[i];
		j = i - g;
		while(j >= 0 && a[j] > v)
		{
			a[j+g] = a[j];
			j = j - g;
			cnt++;
		}
		a[j+g] = v;
	}
	return cnt;
}
