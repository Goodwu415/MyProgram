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
	//��ͷ�������Ԫ��
	//null��ǰָ����ͷ��� 
	x->next = null->next;//x����һ��������null����һ�����  
	//null->next->prev�����ǰ� null��ǰָ��ͷ������һ�����ָ�� x 
	null->next->prev = x;
	null->next = x;	//null���ڵ���һ������Ϊx
	x->prev = null;//ͷ���ָ�� null��� 
}
void deleteKey(int key)
{
	//ɾ���������Ľڵ�
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
	if(t == null) return;//tΪͷ���ʱ�������� 
	t->prev->next = t->next;//��ǰt������һ��������һ�������ڵ�ǰt����һ�����
	t->next->prev = t->prev;// ��ǰt������һ��������һ�������� ��ǰt����һ�����
	free(t);
}
void printList()
{
	Node* cur = null->next;
	int isf = 0;
	while(1)
	{
		if(cur == null){ printf("����Ϊ�գ���\n");break;}
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
	Node *cur = null->next;	//��ͷ�������Ԫ�ؿ�ʼ����
	while(cur != null && cur->key != key) 
	{
		cur = cur->next;
	}
	return cur;
}
