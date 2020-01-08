#include <iostream>
#define MAX 10000
#define NIL -1

struct Node{int parent, left,right;};

struct Node T[MAX];


int n; //n �ڵ��� 
int count = 0; //�ݹ���� 
void preParse(int u);//ǰ����� 
void inParse(int u);//������� 
void postParse(int u);//������� 

int main()
{
	int v, l,r,root = 0;
	scanf("%d",&n);
	
	for(int i = 0; i < n; ++i) T[i].parent = NIL;
	
	for(int i = 0; i < n; ++i)
	{
		scanf("%d %d %d", &v, &l, &r);
		T[v].left = l;// v�ڵ�������� 1  
		T[v].right = r;// v�ڵ�������� r 
		if(l != NIL) T[l].parent = v;// l ������ -1�������������ĸ��ڵ�Ϊ v 
		 
		if(r != NIL) T[r].parent = v;// r ������ -1�������������ĸ��ڵ�Ϊ v 
	}
	for(int i = 0; i < n; ++i)
		if(T[i].parent == NIL) root = i;
	printf("Preorder\n");
	preParse(root);
	printf("\n");
	printf("Inorder\n");
	inParse(root);
	printf("\n");
	printf("Postorder\n");
	postParse(root);
	printf("\n");
	
	return 0;
} 
void preParse(int u)
{
	count += 1; 
	if(u == NIL)
		return;
	printf(" %d",u);
	preParse(T[u].left);
	preParse(T[u].right);
}
void inParse(int u)
{
	if(u == NIL) return;
	
	inParse(T[u].left);//�ݹ鵽left = -1����ִ����һ�����룬��ִ��inParse(T[u].right); 
	printf(" %d", u);
	inParse(T[u].right);//��һ��ִ�е�ʱ�䣺��T[u].left = -1�ĵݹ鷵�صĻ����ϣ��ݹ�T[u].right,u��T[u].left = -1����һ�ε�ֵ���Լ���� 
 } 
void postParse(int u)
{
	if(u == NIL) return;
	postParse(T[u].left);//�ݹ���������ֱ����������Ҷ�ӣ�Ҳ����T[u].left = -1; 
	//ÿ�� u ���� ִ�� postParse(T[u].left);���u һ�����Լ���⣬��˵�����ˡ� 
	postParse(T[u].right);//��һ��ִ�е�ʱ�䣺��T[u].left = -1����һ�εݹ�ػ����Ͻ��ŵݹ���������ֱ����������Ҷ�ӡ�
	printf(" %d",u);//���ԣ�3���ڵ㣬��� 2 1 3�����Ի����׵� 
}


