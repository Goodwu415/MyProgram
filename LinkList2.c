#include <stdio.h>
#include <malloc.h>

struct node
{
	int data;
	struct node* next;	
};

struct node* createNode(int data)
{
	struct node*  n1 = (struct node*)malloc(sizeof(struct node));
	n1->data = data;
	n1->next = NULL;
	return n1;
}
void addatend(struct node** root, struct node* n)
{
	struct node* temp = *root;	//�����ָ�����ã��õ�������ָ����ָ����ڴ��ַ
 
	if(temp == NULL)
	{
		*root = n;
	}
	else
	{
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = n;	
	}
}
void freeNode(struct node** linklist)
{
	struct node* temp = *linklist;	 //�����ָ�����ã��õ�������ָ����ָ����ڴ��ַ
	struct node* temp2 = temp;	// tempָ��ĵ�ַ ,Ҳ����linklist�����ú�ĵ�ַ�� 
	while(temp != NULL)
	{
		printf("temp->next Address = %p \ttemp->data = %d\n", temp->next,temp->data);;
		temp = temp->next;	//��һ���ڵ� 
		
		free(temp2);
		temp2 = temp;	//tempָ��ĵ�ַ 
	//	printf("temp2 Address = %p \ttemp2->data = %d\n", temp2,temp2->data);
	}
	*linklist = NULL;
}
int main()
{
	struct node* root = NULL;
	printf("\nroot = %p\n", root);
	int i;
	for(i = 0; i < 10; ++i)
	{
		addatend(&root, createNode(i+10));
	}
	printf("\ninit root = %p\n", root);
	struct node* iter = root;
	while(iter != NULL)
	{
		printf("%d ",iter->data);
		iter = iter->next;
	}
	printf("\n");
	freeNode(&root);
	printf("\nroot = %p\n", root);
	return 0;
}
