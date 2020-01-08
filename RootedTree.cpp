#include <iostream>

/*
	�и�����
	ʹ�á��������ֵܱ�ʾ������left-child right-sibling representation)����ʾ��
	 
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

//int getDepth(Node u);//��ڵ���� ����  
int rec(int u, int p);//�ݹ������� 
int main()
{	//		l Ӣ����ĸl 
	int i,j,d,v,c,l,r;	//d �ڵ�Ķȣ� v ���ڵ��� ��c�ӽڵ�ı�� ��l ��ڵ��� 
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		T[i].p = T[i].l = T[i].r = NIL;//��ʼ�����нڵ�ΪNIL�� 
	} 
	
	for(i = 0; i < n; ++i)
	{
		cin >> v >> d;
		for(j = 0; j < d; ++j)
		{
			cin >> c;		//v ���ӽڵ� 
			if(j == 0)T[v].l = c;//T[v]�ڵ�����ӽڵ�ָ�� c����ڵ� 
			else T[l].r = c;	//���l�±��ʼ��ָ�����ӽڵ㡣
								//�Ժ����нڵ��������ڵ�����ֵ� 
								//��T[l]�����ӽڵ�ָ�� c���� 
			//���� l��ָ�� 
			l = c; // l ָ��c ����ڵ㣬��� T[l].r = c����δ��룬 
			T[c].p = v;//����ǰ�ڵ�ĸ��ڵ� ָ��v������ڵ㡣 
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
	//�����������룬һֱ�ݹ�ڵ�����ӽڵ㣬ֱ�����ӽڵ�ΪNIL�� 
	if(T[u].r != NIL)rec(T[u].r, p);	//�Ҳ��ֵ�����Ϊ��ͬ���
	if(T[u].l != NIL)rec(T[u].l, p + 1);	//������ӽڵ���������Ϊ�Լ������+1 
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
