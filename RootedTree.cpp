#include <iostream>

/*
	有根树：
	使用“左子右兄弟表示法”（left-child right-sibling representation)来表示树
	 
*/
#define MAX 100000
#define NIL -1
using namespace std;

struct Node
{
	int p,l,r;	
}; 

Node T[MAX];
int n, D[MAX];

void print(int u);

//int getDepth(Node u);//求节点深度 迭代  
int rec(int u, int p);//递归地求深度 
int main()
{	//		l 英文字母l 
	int i,j,d,v,c,l,r;	//d 节点的度， v 父节点编号 ，c子节点的编号 ，l 左节点编号 
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		T[i].p = T[i].l = T[i].r = NIL;//初始化所有节点为NIL。 
	} 
	
	for(i = 0; i < n; ++i)
	{
		cin >> v >> d;
		for(j = 0; j < d; ++j)
		{
			cin >> c;		//v 的子节点 
			if(j == 0)T[v].l = c;//T[v]节点的左子节点指向 c这个节点 
			else T[l].r = c;	//这个l下标最开始便指向左子节点。
								//以后，所有节点便是这个节点的右兄弟 
								//让T[l]的右子节点指向 c，。 
			//更新 l的指向 
			l = c; // l 指向c 这个节点，配合 T[l].r = c；这段代码， 
			T[c].p = v;//将当前节点的父节点 指向v这个父节点。 
		}
	}
	for(i = 0; i < n; ++i) 
	{
		if(T[i].p == NIL) r = i;
	}
	rec(r, 0);
	for(i = 0; i < n; ++i) print(i);
	return 0;
}
int rec(int u, int p)
{
	D[u] = p;
	//下面这条代码，一直递归节点的右子节点，直到右子节点为NIL。 
	if(T[u].r != NIL)rec(T[u].r, p);	//右侧兄弟设置为相同深度
	if(T[u].l != NIL)rec(T[u].l, p + 1);	//最左侧子节点的深度设置为自己的深度+1 
}
void print(int u)
{
	int i, c;
	cout << "node" << u << ": ";
	cout << "parent = " << T[u].p << ", ";
	cout << "depth = " << D[u] << ", ";
	
	if(T[u].p == NIL) cout << "root, ";
	else if(T[u].l == NIL) cout << "leaf, ";
	else cout << "internal node; ";
	
	cout << "[";
	
	for(i = 0, c = T[u].l; c != NIL; ++i, c = T[c].r)
	{
		if(i)cout << ", ";
		cout << c;
	}
	cout << "]" << endl;
}
