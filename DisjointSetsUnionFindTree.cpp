#include <iostream>
#include <vector>
 
//����һ�����ʶ�̬���ϡ� 

//unite(x, y ): �ϲ�����x�ļ���S_x�����y�ļ��� S_y
//same(x, y ): �ж� x ��y �Ƿ������ͬһ����

using namespace std;

class DisjointSet
{
public:
	std::vector<int> rank, p;	//rank:�洢���ڵ�xΪ�������ĸ߶� 
	
	DisjointSet() {}
	DisjointSet(int size)
	{
		rank.resize(size, 0);
		p.resize(size, 0);
		for(int i = 0; i < size; ++i)makeSet(i);
	}
	void makeSet(int x)//����������Ԫ��x���¼��� 
	{
		p[x] = x;
		rank[x] = 0;
	}
	bool same(int x, int y)	//x��y�Ƿ������ͬһ�����У��ǣ�1 �� 0 
	{
		return findSet(x) == findSet(y);
	}
	void unite(int x, int y)//�ϲ�����x�ļ���S_x�����y�ļ���S_y 
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
	int findSet(int x)	//�����Ԫ��x�ļ��ϵġ�����Ԫ�ء� 
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

