#include <cstdio>
#include <cstdlib>
#include <iostream>
/*
	2019/5/10 15:10
	画图能更好的理解二叉树的增、删、改、查。
	画一下图，事倍功半。。 Tree.jpg 
	删是我自己写的，其他，是拷的。
	就删那块，也把我能得头疼。 
*/
 
using namespace std;

typedef struct _Node{
	int key;
	struct _Node *parent,*left, *right;
}Node; 
Node *root = NULL, *NIL = NULL;

void insert(int);
void inorder(Node *u);//中序排序
void preorder(Node *u);
void find(int key);
void deleteNode(int key);
int main()
{
	
	int m;//命令数
	int x;//数据 
	string com;
	
	scanf("%d",&m);
	for(int i = 0; i < m; ++i)
	{
		cin >> com;
		if(com == "insert")
		{
			scanf("%d", &x);
			insert(x);
		}else if(com == "print")
		{
			inorder(root);
			printf("\n");
			preorder(root);
			printf("\n");
		}else if(com == "find")
		{
			scanf("%d",&x);
			find(x);
			printf("\n");
		}else if(com == "delete")
		{
			scanf("%d",&x);
			deleteNode(x);
		}
	}
	
	return 0;
}
void deleteNode(int key)
{
	Node *x = root;
	while(x != NIL && key != x->key)
	{
		if(x->key > key)//在左子树 
		{
			x = x->left; 
		}else{//在右子树 
			x = x->right;
		} 
	}
	if(x != NIL)//表示找到了
	{
		if(x->left == NIL && x->right == NIL)//这个是叶子 
		{//如果x的父节点的键值大于x的键值，那就把x父节点的左子节点置为NIL，不大于，就把右子节点置为NIL 
			if(x->parent == NIL)//有可能删除的是根节点，而根节点没有父节点 
			{
				//root = (Node*)malloc(sizeof(Node));
				root = NIL;//指针置为NIL 
				//x->parent = root;
				//x->parent = (Node*)malloc(sizeof(Node));
				//root = x->parent;	//因为删除了根节点，所以，要更新root指针的指向。而x->parent会是成为树的根节点。
			}else
			{
				x->parent->key > x->key ? x->parent->left = NIL : x->parent->right = NIL;
			}
			delete x; //x指向的那块地址 
		}else if(x->left != NIL && x->right == NIL)//表示只有左子节点
		{
			if(x->parent == NIL)
			{	//执行这段代码： 
				//x是根节点，而根节点只有左子节点 ，直接将root指针指向它的左子节点。 
				root = x->left;	
				//更新左子节点的父节点 
				x->left->parent = NIL;//根节点没有父节点 
			}else 
			{
				x->parent->key > x->key ? x->parent->left = x->left : x->parent->right = x->left;
				x->left->parent = x->parent;
			}
			delete x; 
		}else if(x->right != NIL && x->left == NIL)//表示只有右子节点
		{
			if(x->parent == NIL)//有可能删除的是根节点，而根节点没有父节点 
			{
				root = x->right;
				x->right->parent = NIL;
			}else
			{
				x->parent->key > x->key ? x->parent->left = x->right : x->parent->right = x->right;
				x->right->parent = x->parent;
			}
			delete x;
		}else{//度为2的节点 
			if(x->parent == NIL)//有可能删除的是根节点，而根节点没有父节点 
			{
				root = x->right;//根指针指向 x的右节点 
				x->right->parent = NIL;//x的右节点的父指针 置为NIL 
				x->left->parent = x->right;//x的左节点的父指针 指向x的右节点 
				x->right->left = x->left;//x的右节点的左指针 指向x的左节点 
			}else
			{
				x->left->parent = x->right;//x的左子节点的父节点指针 指向 x的右节点 
				x->right->left = x->left;	//x的右子节点的左节点指针指向 x的左节点 
				x->parent->key > x->key ? x->parent->left = x->right : x->parent->right = x->right;
				x->right->parent = x->parent;//x的右节点的父节点指针指向x的父节点 
			}
			delete x;
		}  
	}else{//没有这个节点 
		printf("没有这个节点"); 
	}
	 
}
void find(int key)
{
	Node *x = root;
	while(x != NIL)
	{
		if(x->key > key)//在左子树 
		{
			x = x->left;
		}else if(x->key < key)//在右子树 
		{
			x = x->right;
		 }else{
		 	printf("yes");
		 	break;
		 } 
	}
	if(x == NIL)
		printf("no");
} 

void preorder(Node *u)
{
	if(u == NIL)return;
	printf(" %d", u->key);
	preorder(u->left);
	preorder(u->right);
}
void inorder(Node *u)
{
	if(u == NIL)return;
	inorder(u->left);
	printf(" %d", u->key);
	inorder(u->right);
}

void insert(int k)
{
	Node *y = NIL;	 //前一个节点 
	Node *x = root;	//当前节点 
	Node *z = NULL;	//插入节点 
	
	z = (Node*)malloc(sizeof(Node));//分配内存 
	
	z->key = k;	 
	z->left = NIL;
	z->right = NIL;
	
	while(x != NIL)//查找树中合适的插入位置，退出循环表明找到了。 
	{
		/*	x!=NIL,那么执行了下面的代码后就会更新到下一个节点，
			那么 y 就成了x节点的父节点。 
		*/ 
		y = x;	
		//插入节点的key小于当前比较的节点的key，那么插入节点就会成为 
		//当前节点的左子树中的一个节点 
		if(z->key < x->key)	 
		{
			x = x->left;//将当前节点x更新，指向左子树。 
		}else// 插入节点的key大于当前比较的节点的key，那么插入节点就会成为 
		//当前节点的右子树中的一个节点 
		{
			x = x->right;//将当前节点x更新，指向右子树。 
		}
	}
	//找到了位置后，将插入节点的父节点指针指向 y;y就是z的父节点 
	z->parent = y;
	//y == NIL表明树中没有节点，也就是空树 
	if(y == NIL) 
	{
		root = z;	//有根节点了 
	}else //树中有节点了 
	{//接下来就是把插入节点插在那边。 
		if(z->key < y->key)// 左节点 
		{
			y->left = z;
		}else{	//右节点 
			y->right = z;	
		}
	}
	//cout << "root:" << root->key << endl;
//	if(k < x.key)
//	{
//		
//	}else if(k > x->key)
//	{
//		
//	}
	
}
