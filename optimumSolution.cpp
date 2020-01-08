#include <iostream>

using namespace std;

#define MAX 100000
typedef long long llong;

int n, k;//k �������� 

llong T[MAX];

//k�����������Ϊp�Ŀ�����װ���ٻ���
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
	llong right = 100000 * 10000;	//������ *1�������������� 
	llong mid;
	while(right - left > 1) 
	{
		mid = (left+right) / 2;
		int v = check(mid);//mid == ���mid == pʱ��װ���ٻ���
		if(v >= n) right = mid;
		else left = mid;
	}
	return right;
}
int check(llong p)//���������p 
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

