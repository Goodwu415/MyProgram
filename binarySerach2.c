#include <stdio.h>

int search(int a[], int n, int x);

int main()
{
	int i, x,z;
	int a[10] = {1, 2, 2, 4, 23, 32, 43, 66, 443, 555};
	printf("������Ҫ���ҵ����֣�");
	scanf("%d",&x);
	z = search(a, 10, x);
	if(z >= 0)
		printf("��Ҫ���ҵ���%d�������е�λ���ǵ�%d��Ԫ��\n",x,z);
	else
		printf("��Ҫ���ҵ���%d���������У�\n",x);
	return 0;
}
int search(int a[], int n, int x)
{
	int low, mid, high;
	low =0;
	high = n -1;
	while(low <= high)//���ֲ��� 
	{
		mid = (low + high)/2;
		if(a[mid] == x)
			return mid+1;
		else if(a[mid] > x)
			high = mid -1;
		else low = mid + 1;
	}
	return -1;
}
