#include <stdio.h>
#include <malloc.h>

//����������

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
		*root = n;	//���ڵ�Ϊ��ʱ�����ڵ㸳ֵΪ�������Ľڵ� 
	}
	else
	{
		if(n->data < temp->data) 
		{
			//temp->left = n;������ֱ�Ӹ�ֵ����ΪleftҲ�������Լ��Ľڵ㡣
			//���ԣ���Ҫ �ݹ���ҵ�NULL�ڵ㡣 
			insertnode(&(temp->left), n);//��left�ĵ�ַ�� 
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
