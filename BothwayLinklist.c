#include <stdio.h>
#include <malloc.h>
//实现双向链表

typedef struct _Node
{
	int data;
	struct _Node* prev;
	struct _Node* next;
}NODE,*PNODE;

PNODE createNode(int data)
{
	PNODE nd = (PNODE)malloc(sizeof(NODE));
	nd->data = data;
	nd->prev = NULL;
	nd->next = NULL;
	printf("nd Address of = %p\n", nd);
	return nd;
}

void appendNode(NODE** last,int data)
{
	PNODE temp = *last;		//指向最后一个节点 
	
	if(temp == NULL)
	 	*last = createNode(data); 
	else
	{
	
		PNODE n2= (PNODE)malloc(sizeof(NODE));
		n2->data = data;
		//n2->next = NULL;
		n2->prev = temp;
		temp->next = n2;
		*last = n2;	//始终保持last指向最后一个节点 
	}
}
//释放内存 
void freeMemory(NODE** head)
{
	//保留头指针，提供一个判断条件，因为最后一个节点的next指针指向头节点， 
	//	也因为双向链表的所有指针都指向不为NULL的内存地址
	PNODE pH = *head;	 //解二级指针引用，得到传过来指针所指向的内存地址
	PNODE temp = pH->next;	// pH指向的地址 ,也就是linklist解引用后的地址。 
	PNODE temp2 = temp;
	while(temp->next != pH)
	{
		temp = temp->next;	//下一个节点 
		
		free(temp2);	//temp指向temp 
		
		temp2 = temp;	//temp指向的地址 
	}
	//退出循环表示已到最后一个节点
	temp2 = NULL;	//temp2也指向最后一个节点，置NULL 
	//pH->prev = NULL;	//也可以先把pH的指针置NULL， 或者释放内存后再把结构体指针置NULL. 
	//pH->next = NULL;	//不把结构体置NULL的话，这些指针还是可以访问所指向的内存地址。 
	free(pH);
	pH = NULL;
	//temp->prev = NULL;
	//temp->next = NULL;
	free(temp);	
	temp = NULL;
	
	*head = NULL;
} 
int main()
{
	int i;
	NODE* Head = NULL;
	NODE* Last = NULL;
	
	Head = createNode(0);
	Last = Head;		//Last指向Head指针指向的内存地址 
	
	for(i = 0; i < 10; ++i)
		appendNode(&Last,i + (i+1) / 2);
	//实现 循环双向链表 
	Head->prev = Last;	//头节点的上一个节点指向最后一个节点 
	Last->next = Head; 	//尾节点的下一个节点指向头结点 
	//验证 
//	printf("Head = %p\n",Head);
//	printf("Head->prev = %p\n",Head->prev);
//	printf("Last Address of = %p\n", Last);
//	printf("Last->next Address of = %p\n", Last->next);
	PNODE iter = Head;
	while(iter->next != NULL)
	{
		printf("iter Address = %p iten value = %d\n",iter, iter->data);
		iter = iter->next;		//遍历下一个节点 
		if(iter->next == Head)	//比较内存地址是否相等
			break; 
	}
	freeMemory(&Head);
	return 0;
}

