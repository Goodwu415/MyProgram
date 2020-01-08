#include <iostream>

using namespace std;

//��С��������MST)
//�������Ȩͼ����С�������ĸ���Ȩֵ֮��

//ʹ������ķ�㷨��Prim's Algorithm)

static const int MAX = 100;
static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n;
int M[MAX][MAX];//��¼u��v�ıߵ�Ȩֵ

int prim()
{
	int u, minv;
	//color[n]//���ڼ�¼v�ķ���״̬WHTIE��GRAY��BLACK
	//d[n]���ڼ�¼����T�ڶ�����V-T�ڶ���ı��У�Ȩֵ��С�ıߵ�Ȩֵ
	//p[n]���ڼ�¼MST�ж���v�ĸ��ڵ�
	int d[MAX], p[MAX], color[MAX];
	//	color�����d����ÿ��ѭ���������ֵ��
	//	ֻ�ᱣ���뵱ǰu����Ϊ�ߵĶ����Ȩֵ��״̬ 
	 
	for(int i = 0; i < n; ++i)//��ʼ�� 
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
		//����״̬ΪGRAY�Ķ��� 
		for(int i = 0; i < n; ++i)
		{//�ҳ�Ȩֵ��С�Ķ��㣬���Դ˶��������·�� 
			if(minv > d[i] && color[i] != BLACK)
			{
				u = i;		//Ȩֵ��С�ıߵĶ��� 
				minv = d[i];	//�����ҳ���СȨֵ���ж��� 
			}
		}
		if(u == -1)break;	//�ҵ����·����������color�������ֵȫ��BLACK. 
		
		color[u] = BLACK;	//MST�ı� ����Ϊ���·����һ���ߡ�	 
		
		for(int v = 0; v < n; ++v)//�����ҳ���u���������ı� 
		{//color[v] != BLACK ��û����Ϊ���·���ıߡ� 
			if(color[v] != BLACK && M[u][v] != INFTY)	//M[u][v] != INFTY:���� 
			{
				if(d[v] > M[u][v])//Ȩֵ 
				{
					d[v] = M[u][v];	// ����u����ıߵ�Ȩֵ 
					p[v] = u;			//��¼����v�ĸ��ڵ㡣 
					color[v] = GRAY;	//����v�����״̬ 
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


 
