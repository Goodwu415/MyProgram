#include <iostream>
using namespace std;

static const int MAX = 100;
static const int INFTY = (1<<21);
static const int WHITE = 1;
static const int GRAY = 2;
static const int BLACK = 3;

//M[MAX][MAX] :����u��v�ıߵ�Ȩֵ 
int n, M[MAX][MAX];

void dijkstra()
{
	int minv;
	//d[MAX]:���ڼ�¼���s��v�����·���ɱ�
	//color[MAX]�����ڼ�¼v�ķ���״̬ 
	int d[MAX], color[MAX];
	
	for(int i = 0; i < n; ++i)//��ʼ��Ȩֵ��״̬ 
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
		color[u] = BLACK;		//���·���� 
		//�����룬�ȴ����￴�� 
		for(int v = 0; v < n; ++v)
		{
			if(color[v] != BLACK && M[u][v] != INFTY)
			{//d[v]��Ȩֵ�������d[u] + M[u][v]����Ҫ����d[v]��Ȩֵ 
				if(d[v] > d[u] + M[u][v])
				{
					d[v] = d[u] + M[u][v];	// ����Ȩֵ 
					color[v] = GRAY;		// ����״̬ 
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
		for(int j = 0; j < n; ++j)//��ʼ��Ȩֵ 
		{
			M[i][j] = INFTY;
		}
	}
	//u:���� k: ����ĳ��� v��u-v�ߣ� c: u-v�ߵ�Ȩֵ 
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
