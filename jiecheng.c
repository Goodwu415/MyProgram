#include <stdio.h>

int main()
{
	int i,j,n;
	j = 1;
	i = 2;
	printf("����Ҫ���н׳˵�����\n");
	
	scanf("%d",&n);
	while(i <= n)
	{
		j = j * i;
		i++;
	}
	printf("��� = %d\n", j);3
	return 0;
}
