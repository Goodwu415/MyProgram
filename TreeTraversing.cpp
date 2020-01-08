#include <iostream>
#define MAX 10000
#define NIL -1

struct Node{int parent, left,right;};

struct Node T[MAX];


int n; //n 节点数 
int count = 0; //递归深度 
void preParse(int u);//前序遍历 
void inParse(int u);//中序遍历 
void postParse(int u);//后序遍历 

int main()
{
	int v, l,r,root = 0;
	scanf("%d",&n);
	
	for(int i = 0; i < n; ++i) T[i].parent = NIL;
	
	for(int i = 0; i < n; ++i)
	{
		scanf("%d %d %d", &v, &l, &r);
		T[v].left = l;// v节点的左子树 1  
		T[v].right = r;// v节点的左子树 r 
		if(l != NIL) T[l].parent = v;// l 不等于 -1，就让左子树的父节点为 v 
		 
		if(r != NIL) T[r].parent = v;// r 不等于 -1，就让右子树的父节点为 v 
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
	
	inParse(T[u].left);//递归到left = -1，再执行下一条代码，再执行inParse(T[u].right); 
	printf(" %d", u);
	inParse(T[u].right);//第一次执行的时间：在T[u].left = -1的递归返回的基础上，递归T[u].right,u是T[u].left = -1的上一次的值，自己理解 
 } 
void postParse(int u)
{
	if(u == NIL) return;
	postParse(T[u].left);//递归左子树，直到左子树是叶子，也就是T[u].left = -1; 
	//每次 u 都和 执行 postParse(T[u].left);这个u 一样。自己理解，我说不清了。 
	postParse(T[u].right);//第一次执行的时间：在T[u].left = -1的上一次递归地基础上接着递归右子树，直到右子树是叶子。
	printf(" %d",u);//调试，3个节点，输出 2 1 3，调试会明白的 
}


