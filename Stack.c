#include <stdio.h>
#include <malloc.h>

typedef struct _node
{
	int data; 
	struct _node* next;
}Node;

Node* top;

void push(int data)
{
	if(top == NULL)	
	{
		top = (Node*)malloc(sizeof(Node));
		top->data = data;
		top->next = NULL;
		return;
	}
	Node* no = (Node*)malloc(sizeof(Node));
	no->data = data;
	no->next = top;
	
	top = no;
}
int top2()
{
	if(top == NULL)
		return 0;//ջΪ��
	return top->data; 
}
int pop()
{
	if(top == NULL)
		return 0;	//ջΪ��
	Node* temp = top->next;
	
	free(top);//�ͷ�ջ��ָ���ڴ� 
	top = temp;//��ջ��ָ������ 
	return 1;
}
int main()
{
	int i,succes = 0;
	int data;
	for(i = 0; i < 100; ++i)
	{
		push(i+1);
	}
	for(i = 0; i < 101; ++i)
	{
		data = top2();
		if(data)
		{
			printf("%d ", data);
		}else
		{
			printf("ջΪ��\n");
		}
		if(pop())
		{
			succes++;
		}else
		{
			printf("ջΪ��\n"); 
		}
		if(succes % 10 == 0)
		{
			printf("\n");
		}
	}
	
	return 0;
} 

