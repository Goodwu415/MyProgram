#include <stdio.h> 

int dp[50];

int fib(int n)
{
	if(n == 0 || n == 1) return dp[n] = 1;
	if(dp[n] != -1) return dp[n];
	return dp[n] = fib(n - 1)+fib(n - 2);
}

int main()
{
	int n, i;
	for(i = 0; i < 50; ++i) dp[i] = -1;
	
	scanf("%d", &n);
	printf("递归实现：%d\n", fib(n));
	
	int F[50];
	F[0] = F[1] = 1;
	for(int i = 2; i <= n; ++i)
		F[i] = F[i - 1] + F[i - 2];
	
	printf("迭代实现：%d\n", F[n]);
	return 0;
}
