#include <stdio.h>

int seach(int a[], int);
int main()
{
	int a[10] = {43,23,1,2,32,443,555,66,2,4};
	int tar;
	printf("������Ҫ���ҵ�����:");
	scanf("%d",&tar);
	int index = seach(a,tar);
	if(index < 10) printf("�ҵ��ˣ��������±�Ϊ>%d<�ĵط���\n�����%d\n",index,a[index]);
	else{
		printf("����û���������!\n");
	}
	return 0;
}
int seach(int a[],int tar)
{
	int i;
	while(a[i] != tar && a[i] != '\0')i++;

	return i;
}
