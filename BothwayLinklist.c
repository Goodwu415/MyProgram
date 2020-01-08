#include <stdio.h>
#include <malloc.h>
//ʵ��˫������

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
	PNODE temp = *last;		//ָ�����һ���ڵ� 
	
	if(temp == NULL)
	 	*last = createNode(data); 
	else
	{
	
		PNODE n2= (PNODE)malloc(sizeof(NODE));
		n2->data = data;
		//n2->next = NULL;
		n2->prev = temp;
		temp->next = n2;
		*last = n2;	//ʼ�ձ���lastָ�����һ���ڵ� 
	}
}
//�ͷ��ڴ� 
void freeMemory(NODE** head)
{
	//����ͷָ�룬�ṩһ���ж���������Ϊ���һ���ڵ��nextָ��ָ��ͷ�ڵ㣬 
	//	Ҳ��Ϊ˫�����������ָ�붼ָ��ΪNULL���ڴ��ַ
	PNODE pH = *head;	 //�����ָ�����ã��õ�������ָ����ָ����ڴ��ַ
	PNODE temp = pH->next;	// pHָ��ĵ�ַ ,Ҳ����linklist�����ú�ĵ�ַ�� 
	PNODE temp2 = temp;
	while(temp->next != pH)
	{
		temp = temp->next;	//��һ���ڵ� 
		
		free(temp2);	//tempָ��temp 
		
		temp2 = temp;	//tempָ��ĵ�ַ 
	}
	//�˳�ѭ����ʾ�ѵ����һ���ڵ�
	temp2 = NULL;	//temp2Ҳָ�����һ���ڵ㣬��NULL 
	//pH->prev = NULL;	//Ҳ�����Ȱ�pH��ָ����NULL�� �����ͷ��ڴ���ٰѽṹ��ָ����NULL. 
	//pH->next = NULL;	//���ѽṹ����NULL�Ļ�����Щָ�뻹�ǿ��Է�����ָ����ڴ��ַ�� 
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
	Last = Head;		//Lastָ��Headָ��ָ����ڴ��ַ 
	
	for(i = 0; i < 10; ++i)
		appendNode(&Last,i + (i+1) / 2);
	//ʵ�� ѭ��˫������ 
	Head->prev = Last;	//ͷ�ڵ����һ���ڵ�ָ�����һ���ڵ� 
	Last->next = Head; 	//β�ڵ����һ���ڵ�ָ��ͷ��� 
	//��֤ 
//	printf("Head = %p\n",Head);
//	printf("Head->prev = %p\n",Head->prev);
//	printf("Last Address of = %p\n", Last);
//	printf("Last->next Address of = %p\n", Last->next);
	PNODE iter = Head;
	while(iter->next != NULL)
	{
		printf("iter Address = %p iten value = %d\n",iter, iter->data);
		iter = iter->next;		//������һ���ڵ� 
		if(iter->next == Head)	//�Ƚ��ڴ��ַ�Ƿ����
			break; 
	}
	freeMemory(&Head);
	return 0;
}

