#include <iostream>
#include <vector>
 
//管理一个互质动态集合。 

//unite(x, y ): 合并包含x的集合S_x与包含y的集合 S_y
//same(x, y ): 判断 x 与y 是否包含于同一集合

using namespace std;

class DisjointSet
{
public:
	std::vector<int> rank, p;	//rank:存储各节点x为根的树的高度 
	
	DisjointSet() {}
	DisjointSet(int size)
	{
		rank.resize(size, 0);
		p.resize(size, 0);
		for(int i = 0; i < size; ++i)makeSet(i);
	}
	void makeSet(int x)//创建仅包含元素x的新集合 
	{
		p[x] = x;
		rank[x] = 0;
	}
	bool same(int x, int y)	//x与y是否包含于同一集合中，是：1 否： 0 
	{
		return findSet(x) == findSet(y);
	}
	void unite(int x, int y)//合并包含x的集合S_x与包含y的集合S_y 
	{
		link(findSet(x), findSet(y));
	}
	void link(int x, int y)
	{
		if(rank[x] > rank[y])
		{
			p[y] = x;
		}else
		{
			p[x] = y;
			if(rank[x] == rank[y])
			{
				rank[y]++;
			}
		}
	}
	int findSet(int x)	//求包含元素x的集合的“代表”元素。 
	{
		if(x != p[x])
		{
			p[x] = findSet(p[x]);
		}
		return p[x];
	}
};

int main()
{
	int n, a, b, q;
	int t;
	
	cin >> n >>q;
	DisjointSet ds = DisjointSet(n) ;
	
	for(int i = 0; i < q; ++i)
	{
		cin >> t >> a >> b;
		if(t == 0) ds.unite(a, b);
		else if( t == 1)
		{
			if(ds.same(a, b)) 
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
	}
	return 0;
}

