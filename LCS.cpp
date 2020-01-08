#include <iostream>
#include <string>
#include <algorithm>

//����������� 
using namespace std;

static const int N = 100;
//ʹ�ö�̬�滮��������������е����Ž� 
int lcs(string X, string Y) //�㷨���Ӷ�O(nm) 
{
	int c[N + 1][N + 1];
	int m = X.size();
	int n = Y.size();
	
	int maxl = 0;
	X = ' ' + X;	//��X[0]�в���ո�
	Y = ' ' + Y;	//��Y[0]�в���ո�
	for(int i = 1; i <= m; ++i) c[i][0] = 0;	//���0 
	for(int j = 1; j <= n; ++j) c[0][j] = 0;//���0
	
	for(int i = 1; i <= m; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(X[i] == Y[j])
			{
				c[i][j] = c[i - 1][j - 1] + 1;//��¼�ҵ���������У�Ȼ����µ�ǰ�±��������� 
			}else
			{//����ȣ� 
				c[i][j] = max(c[i - 1][j], c[i][j - 1]); 
			}
			maxl = max(maxl, c[i][j]);//��ǰ�±��������к��Ѿ��õ���������бȽϡ����¡� 
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
