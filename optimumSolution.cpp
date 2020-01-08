#include <iostream>

using namespace std;

#define MAX 100000
typedef long long llong;

int n, k;//k 卡车数量 

llong T[MAX];

//k辆最大运载量为p的卡车能装多少货物
int check(llong p);
int solve();

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)cin >> T[i];
	llong ans = solve();
	cout << ans << endl;
	return 0;
}
int solve()
{
	llong left = 0;
	llong right = 100000 * 10000;	//货物数 *1件货物的最大重量 
	llong mid;
	while(right - left > 1) 
	{
		mid = (left+right) / 2;
		int v = check(mid);//mid == 检查mid == p时能装多少货物
		if(v >= n) right = mid;
		else left = mid;
	}
	return right;
}
int check(llong p)//最大运载量p 
{
	int i = 0;
	for(int j = 0; j < k; j++)
	{
		llong s = 0;
		while(s + T[i] <= p)
		{
			s += T[i];
			i++;
			if(i == n)return n;
		}
	}
	return i;
}

