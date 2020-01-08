#include <iostream>
#include <queue>

using namespace std;

static const int N = 100;
static const int INFTY = (1<<21);

int n, M[N][N];

int d[N];	//通过距离管理访问状态

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
	{	//所以，u v都不能输入0. 
		cin >> u >> k;
		u--; //u--,是有bug的，输入0的话，--之后是-1，访问数组，就会越界。 
		for(int j = 0; j < k; ++j)
		{//读入u顶点的邻接表 
			cin >> v;
			v--;	//这里也是 
			M[u][v] = 1; 	// 非法写入。 
		}
	}
	bfs(0);
	return 0;
}
