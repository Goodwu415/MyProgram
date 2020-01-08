#include <stdio.h>

int seach(int a[], int);
int main()
{
	int a[10] = {43,23,1,2,32,443,555,66,2,4};
	int tar;
	printf("请输入要查找的数字:");
	scanf("%d",&tar);
	int index = seach(a,tar);
	if(index < 10) printf("找到了，在数组下标为>%d<的地方！\n输出：%d\n",index,a[index]);
	else{
		printf("数组没有这个数字!\n");
	}
	return 0;
}
int seach(int a[],int tar)
{
	int i;
	while(a[i] != tar && a[i] != '\0')i++;

	return i;
}
