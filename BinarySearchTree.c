#include <stdio.h>
#include <malloc.h>

//二叉搜索树

struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* createnode(int data)
{
	struct node* n1 = (struct node*)malloc(sizeof(struct node));
	n1->data = data;
	n1->left = NULL;
	n1->right = NULL;
	
	return n1;
}
void insertnode(struct node** root, struct node* n)
{
	struct node* temp = *root;
	if(temp == NULL)
	{
		*root = n;	//根节点为空时。根节点赋值为传过来的节点 
	}
	else
	{
		if(n->data < temp->data) 
		{
			//temp->left = n;不可以直接赋值，因为left也可能有自己的节点。
			//所以，需要 递归的找到NULL节点。 
			insertnode(&(temp->left), n);//传left的地址。 
		}
		else if(n->data > temp->data)
		{
			insertnode(&(temp->right), n); 
		}
	 } 
}
int main()
{
	struct node* root = NULL;
	int i;
	for(i = 0; i < 10; ++i)
	{
		insertnode(&root, createnode(i+10));
	}
	
	return 0;
 } 
