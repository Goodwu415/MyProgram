#include <cstdio>
#include <cstdlib>
#include <iostream>
/*
	2019/5/10 15:10
	��ͼ�ܸ��õ���������������ɾ���ġ��顣
	��һ��ͼ���±����롣�� Tree.jpg 
	ɾ�����Լ�д�ģ��������ǿ��ġ�
	��ɾ�ǿ飬Ҳ�����ܵ�ͷ�ۡ� 
*/
 
using namespace std;

typedef struct _Node{
	int key;
	struct _Node *parent,*left, *right;
}Node; 
Node *root = NULL, *NIL = NULL;

void insert(int);
void inorder(Node *u);//��������
void preorder(Node *u);
void find(int key);
void deleteNode(int key);
int main()
{
	
	int m;//������
	int x;//���� 
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
		if(x->key > key)//�������� 
		{
			x = x->left; 
		}else{//�������� 
			x = x->right;
		} 
	}
	if(x != NIL)//��ʾ�ҵ���
	{
		if(x->left == NIL && x->right == NIL)//�����Ҷ�� 
		{//���x�ĸ��ڵ�ļ�ֵ����x�ļ�ֵ���ǾͰ�x���ڵ�����ӽڵ���ΪNIL�������ڣ��Ͱ����ӽڵ���ΪNIL 
			if(x->parent == NIL)//�п���ɾ�����Ǹ��ڵ㣬�����ڵ�û�и��ڵ� 
			{
				//root = (Node*)malloc(sizeof(Node));
				root = NIL;//ָ����ΪNIL 
				//x->parent = root;
				//x->parent = (Node*)malloc(sizeof(Node));
				//root = x->parent;	//��Ϊɾ���˸��ڵ㣬���ԣ�Ҫ����rootָ���ָ�򡣶�x->parent���ǳ�Ϊ���ĸ��ڵ㡣
			}else
			{
				x->parent->key > x->key ? x->parent->left = NIL : x->parent->right = NIL;
			}
			delete x; //xָ����ǿ��ַ 
		}else if(x->left != NIL && x->right == NIL)//��ʾֻ�����ӽڵ�
		{
			if(x->parent == NIL)
			{	//ִ����δ��룺 
				//x�Ǹ��ڵ㣬�����ڵ�ֻ�����ӽڵ� ��ֱ�ӽ�rootָ��ָ���������ӽڵ㡣 
				root = x->left;	
				//�������ӽڵ�ĸ��ڵ� 
				x->left->parent = NIL;//���ڵ�û�и��ڵ� 
			}else 
			{
				x->parent->key > x->key ? x->parent->left = x->left : x->parent->right = x->left;
				x->left->parent = x->parent;
			}
			delete x; 
		}else if(x->right != NIL && x->left == NIL)//��ʾֻ�����ӽڵ�
		{
			if(x->parent == NIL)//�п���ɾ�����Ǹ��ڵ㣬�����ڵ�û�и��ڵ� 
			{
				root = x->right;
				x->right->parent = NIL;
			}else
			{
				x->parent->key > x->key ? x->parent->left = x->right : x->parent->right = x->right;
				x->right->parent = x->parent;
			}
			delete x;
		}else{//��Ϊ2�Ľڵ� 
			if(x->parent == NIL)//�п���ɾ�����Ǹ��ڵ㣬�����ڵ�û�и��ڵ� 
			{
				root = x->right;//��ָ��ָ�� x���ҽڵ� 
				x->right->parent = NIL;//x���ҽڵ�ĸ�ָ�� ��ΪNIL 
				x->left->parent = x->right;//x����ڵ�ĸ�ָ�� ָ��x���ҽڵ� 
				x->right->left = x->left;//x���ҽڵ����ָ�� ָ��x����ڵ� 
			}else
			{
				x->left->parent = x->right;//x�����ӽڵ�ĸ��ڵ�ָ�� ָ�� x���ҽڵ� 
				x->right->left = x->left;	//x�����ӽڵ����ڵ�ָ��ָ�� x����ڵ� 
				x->parent->key > x->key ? x->parent->left = x->right : x->parent->right = x->right;
				x->right->parent = x->parent;//x���ҽڵ�ĸ��ڵ�ָ��ָ��x�ĸ��ڵ� 
			}
			delete x;
		}  
	}else{//û������ڵ� 
		printf("û������ڵ�"); 
	}
	 
}
void find(int key)
{
	Node *x = root;
	while(x != NIL)
	{
		if(x->key > key)//�������� 
		{
			x = x->left;
		}else if(x->key < key)//�������� 
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
	Node *y = NIL;	 //ǰһ���ڵ� 
	Node *x = root;	//��ǰ�ڵ� 
	Node *z = NULL;	//����ڵ� 
	
	z = (Node*)malloc(sizeof(Node));//�����ڴ� 
	
	z->key = k;	 
	z->left = NIL;
	z->right = NIL;
	
	while(x != NIL)//�������к��ʵĲ���λ�ã��˳�ѭ�������ҵ��ˡ� 
	{
		/*	x!=NIL,��ôִ��������Ĵ����ͻ���µ���һ���ڵ㣬
			��ô y �ͳ���x�ڵ�ĸ��ڵ㡣 
		*/ 
		y = x;	
		//����ڵ��keyС�ڵ�ǰ�ȽϵĽڵ��key����ô����ڵ�ͻ��Ϊ 
		//��ǰ�ڵ���������е�һ���ڵ� 
		if(z->key < x->key)	 
		{
			x = x->left;//����ǰ�ڵ�x���£�ָ���������� 
		}else// ����ڵ��key���ڵ�ǰ�ȽϵĽڵ��key����ô����ڵ�ͻ��Ϊ 
		//��ǰ�ڵ���������е�һ���ڵ� 
		{
			x = x->right;//����ǰ�ڵ�x���£�ָ���������� 
		}
	}
	//�ҵ���λ�ú󣬽�����ڵ�ĸ��ڵ�ָ��ָ�� y;y����z�ĸ��ڵ� 
	z->parent = y;
	//y == NIL��������û�нڵ㣬Ҳ���ǿ��� 
	if(y == NIL) 
	{
		root = z;	//�и��ڵ��� 
	}else //�����нڵ��� 
	{//���������ǰѲ���ڵ�����Ǳߡ� 
		if(z->key < y->key)// ��ڵ� 
		{
			y->left = z;
		}else{	//�ҽڵ� 
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
