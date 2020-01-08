#include <iostream>
#include <string>
#include <algorithm>

//最长子序列问题 
using namespace std;

static const int N = 100;
//使用动态规划法求最长公共子序列的最优解 
int lcs(string X, string Y) //算法复杂度O(nm) 
{
	int c[N + 1][N + 1];
	int m = X.size();
	int n = Y.size();
	
	int maxl = 0;
	X = ' ' + X;	//在X[0]中插入空格
	Y = ' ' + Y;	//在Y[0]中插入空格
	for(int i = 1; i <= m; ++i) c[i][0] = 0;	//填充0 
	for(int j = 1; j <= n; ++j) c[0][j] = 0;//填充0
	
	for(int i = 1; i <= m; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(X[i] == Y[j])
			{
				c[i][j] = c[i - 1][j - 1] + 1;//记录找到的最大序列，然后更新当前下标的最大序列 
			}else
			{//不相等， 
				c[i][j] = max(c[i - 1][j], c[i][j - 1]); 
			}
			maxl = max(maxl, c[i][j]);//当前下标的最大序列和已经得到的最大序列比较。更新。 
		}
	}
	return maxl;
}
int main()
{
	string s1, s2;
	int n; cin >> n;
	for(int i = 0; i < n; ++i) 
	{
		cin >> s1 >> s2;
		cout << lcs(s1, s2) << endl;
	}
	
	return 0;
}
