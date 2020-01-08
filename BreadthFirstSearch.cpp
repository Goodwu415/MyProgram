#include <iostream>
#include <queue>

using namespace std;

static const int N = 100;
static const int INFTY = (1<<21);

int n, M[N][N];

int d[N];	//ͨ������������״̬

void bfs(int s) 
{
	std::queue<int> q;
	q.push(s);
	
	for(int i = 0; i < n; ++i)
		d[i] = INFTY;
	
	d[s] = 0;
	int u;
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		for(int v = 0; v < n; ++v)
		{
			if(M[u][v] == 0) continue;
			if(d[v] != INFTY) continue;
			d[v] = d[u] + 1;
			q.push(v);
		}
	}
	for(int i = 0; i < n; ++i)
		cout << i + 1 << " " << ( (d[i] == INFTY) ? (-1) : d[i]) << endl;
	
}

int main()
{
	int u, k, v;
	
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j) M[i][j] = 0;
	}
	for(int i = 0; i < n; ++i)
	{	//���ԣ�u v����������0. 
		cin >> u >> k;
		u--; //u--,����bug�ģ�����0�Ļ���--֮����-1���������飬�ͻ�Խ�硣 
		for(int j = 0; j < k; ++j)
		{//����u������ڽӱ� 
			cin >> v;
			v--;	//����Ҳ�� 
			M[u][v] = 1; 	// �Ƿ�д�롣 
		}
	}
	bfs(0);
	return 0;
}
