#include <stdio.h>

int main()
{
	int a[] = {5,4,6};
	int s = 559;
	int length = sizeof(a)/sizeof(int);
	int i;
	for(i = 0; i<length; i++)
	{
		a[i] = a[i] * s;//�����ֵ�ÿһλ������Ҫ�˵����� 
	}
	for(i = length-1; i > 0; i--)
	{
		//a[i]/10:�õ���λ�������Ͻ�λ��ֵ��
		//a[i-1]+=a[i]/10: a[i-1]����λ���Ͽ������Ͻ�λ��ֵ��
		//������ǰ�����λ����10���õ����Ͻ�λ��ֵ��
		// ʮλ������Щֵ�� 
		a[i-1] += a[i]/10; 
		a[i] %= 10;// �õ���λ�ϵ����� 
	}
	
	for(i = 0; i < length; i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
