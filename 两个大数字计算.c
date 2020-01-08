#include <stdio.h>
//两个int数组计算乘积。 
int main()
{
	int a[] = {5,4,6};//第一位暂时不用 
	int b[] = {5,5,9};
	int sum[220];
	
	int length = sizeof(a)/sizeof(int);
	int lengthb = sizeof(b)/sizeof(int);
	//m :防止第19行代码进行加法操作，导致数组下标越界。 
	int m = 220 - lengthb;//获取合适的index 
	int i,j,z;
	int k;
	for(i = 0; i<220;i++)
		sum[i] = 0;
	// j : 乘数所在的进制位，从个位开始，一直到最高位 
	for(j = lengthb-1; j >= 0; j-- )
	{//k :k则是j对应在sum数组中的下标， 
	 //k越大对应的进制越小，相反，k越小则对应的进制越大。
	  
		k = m + j;// k :MAX = 119, MIN = m - length+1 
		for(i = length - 1; i >= 0; i--)
		{	//sum[k]:表示当前的进制位。 
			sum[k] += a[i] * b[j];//大数字的每一位数乘上要乘的数。 
			//因为是从右往左计算，所以每次计算完成，
			//下标左移，进制提高。 
			k--; 
		}
	}
	//m-length : 对应着此次计算结果的最高有效位。 
	for(i = 219; i > m-length; i--)
	{
		//a[i]/10:得到该位可以向上进位的值，
		//a[i-1]+=a[i]/10: a[i-1]：高位加上可以向上进位的值。
		//例：当前计算个位，除10，得到向上进位的值，
		// 十位加上这些值。 
		sum[i-1] += sum[i]/10; 
		sum[i] %= 10;// 得到该位上的余数 
	}
	
	for(i = m - length; i < 220; i++) 
	{
		printf("%d ",sum[i]);
	}
	
	return 0;
}
