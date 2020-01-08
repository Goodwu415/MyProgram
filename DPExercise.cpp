#include <stdio.h>

int n, A[50];
bool dp[10][10];
//ʹ�ö�̬�滮��ʵ�֣��� 
// ���仯�ݹ� 
bool solve(int i, int m)//�㷨��ҪO(nm)���ڴ�ռ䣬ȴ�ܽ����Ӷ�Ϊ 0(2^n) ������㷨����Ϊ O(nm) ���㷨.
{
	if(dp[i][m])
		return dp[i][m];
	if(m == 0)
		dp[i][m] = true;
	else if(i >= n)
		dp[i][m] = false;
	else if(solve(i+1, m))
		dp[i][m] = true;
	else if(solve(i+1, m - A[i]))
		dp[i][m] = true;
	else
		dp[i][m] = false;
	return dp[i][m];
}
int main()
{
	int q,M, i;
	scanf("%d", &n);
	
	for(i = 0; i < n; ++i) scanf("%d", &A[i]);
	scanf("%d", &q);
	for(i = 0; i < q; ++i)
	{
		scanf("%d", &M);
		if(solve(0, M))printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
