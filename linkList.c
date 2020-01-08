#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int key;
	struct Node *next,*prev;
}Node;

Node *null;
Node* listSearch(int key);
void init();
void printList();
void deleteNode(Node *t);
void deleteFirst();
void deleteLast();
void deleteKey(int key);
void insert(int key);
int main()
{
	int key, n, i;
	int size = 0;
	char com[20];
	int np = 0, nd = 0;
	scanf("%d",&n);
	init();
	for(i = 0; i < n; i++)
	{
		scanf("%s%d",com, &key);
		if(com[0] == 'i')
		{
			insert(key);
			np++;
			size++;
		}else if(com[0] == 'd')
		{
			if(strlen(com) > 6)
			{
				if(com[6] == 'F' || com[6] == 'f')deleteFirst();
				else if(com[6] == 'L'|| com[6] == 'l') deleteLast();
			}else{
				deleteKey(key);
				nd++;
			}
			size--;
		}
	}
	printList();
	return 0;
}
void insert(int key)
{
	Node *x = (Node*)malloc(sizeof(Node));
	x->key = key;
	//在头结点后添加元素
	//null当前指的是头结点 
	x->next = null->next;//x的下一个结点等于null的下一个结点  
	//null->next->prev，就是把 null当前指的头结点的上一个结点指向 x 
	null->next->prev = x;
	null->next = x;	//null现在的下一个结点改为x
	x->prev = null;//头结点指向 null结点 
}
void deleteKey(int key)
{
	//删除搜索到的节点
	deleteNode(listSearch(key));
}
void deleteLast()
{
	deleteNode(null->prev);
}
void deleteFirst()
{
	deleteNode(null->next);
}
void deleteNode(Node *t)
{
	if(t == null) return;//t为头结点时不作处理 
	t->prev->next = t->next;//当前t结点的上一个结点的下一个结点等于当前t的下一个结点
	t->next->prev = t->prev;// 当前t结点的下一个结点的上一个结点等于 当前t的上一个结点
	free(t);
}
void printList()
{
	Node* cur = null->next;
	int isf = 0;
	while(1)
	{
		if(cur == null){ printf("链表为空！！\n");break;}
		if(isf++ > 0)printf(" ");
		printf("%d",cur->key);
		cur = cur->next;
	}
	printf("\n");
}
void init()
{
	null = (Node *)malloc(sizeof(Node));
	null->next = null;
	null->prev = null;
}
Node* listSearch(int key)
{
	Node *cur = null->next;	//从头结点后面的元素开始访问
	while(cur != null && cur->key != key) 
	{
		cur = cur->next;
	}
	return cur;
}
