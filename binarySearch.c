#include <stdio.h> 

int seach(int a[], int n, int x);

int main()
{
	int a[10] = {1, 2, 2, 4, 23, 32, 43, 66, 443, 555};
	int i,x,z;
	printf("请输入要查找的数：");
	scanf("%d", &x);
//	printf("test:%d\n",0.4);
	z = seach(a,10, x);
	if(z >= 0) printf("找到了，在数组下标为>%d<的地方！\n输出：%d\n",z+1,a[z]);
	else printf("没找到"); 
	return 0;
}
int seach(int a[], int n, int x)
{
	int low = 0, mid,high = n -1;
	int index = -1;
	//mid = (low + high)/2;
	while(low <= high)
	{
		mid = (high + low)/2;
		
		if(a[mid] == x){index = mid;break;} 
		else if( a[mid] > x)
			high = mid -1;
		else
			low = mid + 1;	
	} 
	return index;
}
