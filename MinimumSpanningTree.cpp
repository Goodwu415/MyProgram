#include <iostream>

using namespace std;

//最小生成树（MST)
//求给定加权图的最小生成树的各边权值之和

//使用普里姆算法（Prim's Algorithm)

static const int MAX = 100;
static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n;
int M[MAX][MAX];//记录u到v的边的权值

int prim()
{
	int u, minv;
	//color[n]//用于记录v的访问状态WHTIE、GRAY、BLACK
	//d[n]用于记录连接T内顶点与V-T内顶点的边中，权值最小的边的权值
	//p[n]用于记录MST中顶点v的父节点
	int d[MAX], p[MAX], color[MAX];
	//	color数组和d数组每次循环都会更新值，
	//	只会保存与当前u顶点为边的顶点的权值和状态 
	 
	for(int i = 0; i < n; ++i)//初始化 
	{
		d[i] = INFTY;
		p[i] = -1;
		color[i] = WHITE;
	}
	d[0] = 0;	//start 
	
	while(1)
	{
		minv = INFTY;
		u = -1;
		//遍历状态为GRAY的顶点 
		for(int i = 0; i < n; ++i)
		{//找出权值最小的顶点，并以此顶点找最短路径 
			if(minv > d[i] && color[i] != BLACK)
			{
				u = i;		//权值最小的边的顶点 
				minv = d[i];	//这是找出最小权值的判断量 
			}
		}
		if(u == -1)break;	//找到最短路径，条件是color数组里的值全是BLACK. 
		
		color[u] = BLACK;	//MST的边 ，作为最短路径的一条边。	 
		
		for(int v = 0; v < n; ++v)//遍历找出与u顶点相连的边 
		{//color[v] != BLACK ：没有作为最短路径的边。 
			if(color[v] != BLACK && M[u][v] != INFTY)	//M[u][v] != INFTY:相连 
			{
				if(d[v] > M[u][v])//权值 
				{
					d[v] = M[u][v];	// 更新u顶点的边的权值 
					p[v] = u;			//记录顶点v的父节点。 
					color[v] = GRAY;	//更新v顶点的状态 
				}
			}
		}
	}
	int sum = 0;
	for(int i = 0; i < n; ++i)
	{
		if(p[i] != -1)sum += M[i][p[i]];
	}
	return sum;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			int e;
			cin >> e;
			M[i][j] = (e == -1)? INFTY : e;
		}
	}
	cout << prim() << endl;
	return 0;
}


 
