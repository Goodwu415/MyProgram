#include <stdio.h>

int main()
{
	int n,m;
	int i,j,k,v;	// v  
	int a[n];
	scanf("%d",&m);
	if(m < 1)
		n = 1;
	else if( m > 100)
		n = 100;
	else
		n = m;
	for(i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
		if(a[i] < 0)
			a[i] = 0;
		else if(a[i] > 1000)
			a[i] = 1000;
	}
	for(k = 0; k < n-1; k++)
	{
		printf("%d ", a[k]);//�������Ԫ�أ���<n-1 
	}
	printf("%d\n",a[k]);	//��� n-1 Ԫ�أ�Ҳ�������һ�� 
	
	for(i = 1; i < n; i++)
	{
		v = a[i];	// ȡ���±�Ϊi��Ԫ�� 
		j = i - 1;	 
		while(j >= 0 && a[j] > v) //�±�jҪ����0������a[j]��Ԫ�ر������a[i]��Ԫ�ء� 
		{
			a[j+1] = a[j];	 
			j--;		// ���������������鿴����ǰ������Ƿ���� v. 
		}
		a[j+1] = v;		//��������ǵ��������(j >= 0 && a[j] > v)�е�ĳһ��������ʱ��
						// �����Ա� 
		for(k = 0; k < n-1; k++)
		{
			printf("%d ", a[k]);
		}
		printf("%d\n",a[k]);
	}
	return 0;
}
