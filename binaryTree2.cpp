#include <iostream> 
#define MAX 10000
#define NIL -1

struct Node{int parent, left,right;};

Node T[MAX];


int n, D[MAX],H[MAX]; //n 节点数 D 记录深度的数组 H 记录高度的数组 
int count = 0; //递归深度 
void setDepth(int u, int d);
int setHeight(int u);
int getSibling(int u);
void print(int u);
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
	
	for(int i = 0; i < n; ++i)	//节点的编号，可能是随机输入的，所以，需要执行这段代码 
		if(T[i].parent == NIL) root = i;//找到根节点，根节点没有父节点
	
	setDepth(root, 0);
	count = 0;
	setHeight(root);
	count = 0;
	for(int i = 0; i < n; ++i)
	{
		print(i);
		count = 0;	//调试 
	}
	 
	return 0;
}
void setDepth(int u, int d)
{
	count += 1; 
	if(u == NIL) return;//结束递归地条件, 节点可能没有左右子树 
	D[u] = d; 	//D[u]的深度为d， u 会随着递归地深入，而改变 
	setDepth(T[u].left, d + 1);//先递归左子树，深度d + 1，左子树递归完成后
								//再接着便在T[u]节点的右子树上接着递归右子树
							//如果右子树为空，程序退出，d 便是节点的深度。
							//每次递归，都会保存当前的d值，也就是说，当前递归不会影响上一次递归d的值 
	setDepth(T[u].right, d + 1); //当执行到这条代码时，如果递归到终止条件
							//程序退出，节点深度便是 d。
							//也就是到达终止条件地上一次 递归时的 d 
}
//从根节点遍历 
int setHeight(int u)
{
	//我被这些递归给弄懵逼了。因为，当left为NIL时，就接着判断right是否为空
	//不为空，就接着递归，直到所有条件都不满足时，我搞不懂的是递归返回的值
	//谁接收，因为，递归right时，有可能left条件又满足了，接着，又开始递归
	//left,这样下去，这递归得多乱啊，我是真乱了。 
	 //如果，left条件不满足时，right也不满足，或许我还是看得有点明白的。
	count += 1;
	int h1 = 0, h2 = 0;
	if(T[u].left != NIL)	//节点的左子树 不为空 
		h1 = setHeight(T[u].left) + 1;	//最开始是 0 + 1 调试点 
	if(T[u].right != NIL) 
		h2 = setHeight(T[u].right) + 1; 	//最开始是 0 + 1 调试点
	//当上面的代码执行完后，就可得到左子树的高+1，和右子树的高+1 
	return H[u] = (h1 > h2 ? h1 : h2);//返回二者之中最大的那个数。 
	//我猜想，最开始return的是 0， 	//最开始是 1 ： 1 ，所以，返回 1  
	
}
//返回节点u的兄弟节点 
int getSibling(int u)
{
	count += 1;
	if(T[u].parent == NIL) return NIL;//父节点为NIL，就是根
	//贼绕，意思是：u节点的父节点的左子树 != 当前节点 u &&
	// u节点的父节点的左子树 != NIL 		NIL 没有节点 
	//这段代码应该是给右子树写的 
	if(T[T[u].parent].left != u && T[T[u].parent].left != NIL)  
		return T[T[u].parent].left;
	//这段代码，跟上面代码的意思相反 
	if(T[T[u].parent].right != u && T[T[u].parent].right != NIL) 
		return T[T[u].parent].right;
	return NIL;//以上条件都不满足，u节点便是叶子节点，叶子节点没child; 
}

void print(int u)
{
	printf("node %d: ", u);
	printf("parent = %d, ", T[u].parent);
	printf("sibling = %d, ", getSibling(u));
	int deg = 0;//节点的度 ，也就是节点的child节点个数 
	if(T[u].left != NIL)deg++;
	if(T[u].right != NIL)deg++;
	printf("degree = %d, ", deg);
	printf("depth = %d, ", D[u]);//节点的深度，就是在几层
	//节点的高，就是当前节点的child节点，child节点的child节点，以此类推，直到child节点没有child节点 
	printf("height = %d, ", H[u]);
	
	if(T[u].parent == NIL)
	{
		printf("root\n");
	}else if(T[u].left == NIL && T[u].right == NIL) 
	{
		printf("leaf\n");
	}else{
		printf("internal node\n");
	}
}

