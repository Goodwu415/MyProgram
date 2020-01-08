#include <stdio.h>

int main()
{
	int a[] = {5,4,6};
	int s = 559;
	int length = sizeof(a)/sizeof(int);
	int i;
	for(i = 0; i<length; i++)
	{
		a[i] = a[i] * s;//大数字的每一位数乘上要乘的数。 
	}
	for(i = length-1; i > 0; i--)
	{
		//a[i]/10:得到该位可以向上进位的值，
		//a[i-1]+=a[i]/10: a[i-1]：高位加上可以向上进位的值。
		//例：当前计算个位，除10，得到向上进位的值，
		// 十位加上这些值。 
		a[i-1] += a[i]/10; 
		a[i] %= 10;// 得到该位上的余数 
	}
	
	for(i = 0; i < length; i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
