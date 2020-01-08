#include <iostream>
using namespace std;

static const int MAX = 100;
static const int INFTY = (1<<21);
static const int WHITE = 1;
static const int GRAY = 2;
static const int BLACK = 3;

//M[MAX][MAX] :用于u到v的边的权值 
int n, M[MAX][MAX];

void dijkstra()
{
	int minv;
	//d[MAX]:用于记录起点s到v的最短路径成本
	//color[MAX]：用于记录v的访问状态 
	int d[MAX], color[MAX];
	
	for(int i = 0; i < n; ++i)//初始化权值、状态 
	{ 
		d[i] = INFTY;
		color[i] = WHITE;
	}
	
	d[0] = 0;
	color[0] = GRAY;
	
	while(1)
	{
		minv = INFTY;
		int u = -1;
		for(int i = 0; i < n; ++i)
		{
			if(minv > d[i] && color[i] != BLACK)
			{
				u = i; 
				minv = d[i];
			}
		}
		
		if(u == -1) break;
		color[u] = BLACK;		//最短路径边 
		//看代码，先从这里看起。 
		for(int v = 0; v < n; ++v)
		{
			if(color[v] != BLACK && M[u][v] != INFTY)
			{//d[v]的权值如果大于d[u] + M[u][v]，就要更新d[v]的权值 
				if(d[v] > d[u] + M[u][v])
				{
					d[v] = d[u] + M[u][v];	// 更新权值 
					color[v] = GRAY;		// 更新状态 
				}
			}
		}
	}
	for(int i = 0; i < n; ++i)
	{
		cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
	}
}

int main()
{
	cin >> n;
	for(int i =0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)//初始化权值 
		{
			M[i][j] = INFTY;
		}
	}
	//u:顶点 k: 顶点的出度 v：u-v边， c: u-v边的权值 
	int k, c, u,v;
	for(int i = 0; i < n; ++i)
	{
		cin >> u >> k;
		for(int j = 0; j < k; ++j)
		{
			cin >> v >> c;
			M[u][v] = c;
		}
	}
	
	dijkstra();
	
	return 0;
}
