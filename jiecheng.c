#include <stdio.h>

int main()
{
	int i,j,n;
	j = 1;
	i = 2;
	printf("输入要进行阶乘的数！\n");
	
	scanf("%d",&n);
	while(i <= n)
	{
		j = j * i;
		i++;
	}
	printf("结果 = %d\n", j);3
	return 0;
}
