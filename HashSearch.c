#include <stdio.h>
#include <malloc.h>
#define MAX 3
typedef struct
{
	int num;
	char name[20];
 } ElemType;
 //hash table
 typedef struct
 {
 	ElemType *elem;
 	int count;
 	int sizeindex;
 }HashTable;
 //hash func
 int Hash(int num)
 {
 	int p;
 	p = num % 5;
 	return p;
 }
 //create hash tabel
 void InitHash(HashTable *H)
 {
 	int i;
 	H->elem = (ElemType*)malloc(MAX*sizeof(ElemType));
 	H->count = 0;
 	for(i = 0; i < MAX; i++)
 		H->elem[i].num = 0;//��ʼ����ʹSearchHash�������жϵ�����û��Ԫ��������
 }
 // Find func
 int SearHash(HashTable H, int key, int *p)
 {
 	int c = 0;
 	*p = Hash(key);
 	while(H.elem[*p].num != key && H.elem[*p].num != 0)//ͨ������̽����ɢ�н����ͻ 
 	{
 		c = c+1;
 		if(c%2 == 1)
 			*p = *p+(c+1)*(c+1)/4;
 		else
 			*p = *p - (c*c)/4;
	 }
	 if(H.elem[*p].num == key) 
	 	return 1;
	else
		return 0;
} 
// insert func
void InsertHash(HashTable *H, ElemType e) //������Ҳ����Ͳ���Ԫ��
{
	int p;
	SearHash(*H, e.num, &p);
	H->elem[p] = e;
	++H->count;
 } 
 int main()
 {
 	HashTable H;
 	int p, key, i;
 	ElemType e;
 	InitHash(&H);
 	for(i = 0; i < 3; i++)
 	{
 		loop:printf("�����%d��ѧ����ѧ��\n",i+1);
 		scanf("%d",&e.num);
 		if(!SearHash(H, e.num, &p))
 		{
 			printf("�����%d��ѧ������\n", i+1);
 			scanf("%s",e.name);
 			InsertHash(&H, e);
		 }
		 else{
		 	printf("��ѧ���Ѿ�����\n");
		 	goto loop;
		 }
	 }
	 printf("��������Ҫ���ҵ�ѧ��ѧ�ţ�\n");
	 scanf("%d",&key);
	 if(SearHash(H, key, &p))
	 {
	 	printf("���ҳɹ���ѧ����������%s\n",H.elem[p].name);
	 	printf("ѧ�����ڱ��е�λ����%d\n",p);
	 }
	 else
	 	printf("����ʧ�ܣ���Ҫ���ҵ�ѧ��������\n");
	  	return 0;
 }
