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
 		H->elem[i].num = 0;//初始化，使SearchHash函数能判断到底有没有元素在里面
 }
 // Find func
 int SearHash(HashTable H, int key, int *p)
 {
 	int c = 0;
 	*p = Hash(key);
 	while(H.elem[*p].num != key && H.elem[*p].num != 0)//通过二次探测再散列解决冲突 
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
void InsertHash(HashTable *H, ElemType e) //如果差找不到就插入元素
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
 		loop:printf("输入第%d个学生的学号\n",i+1);
 		scanf("%d",&e.num);
 		if(!SearHash(H, e.num, &p))
 		{
 			printf("输入第%d个学生名字\n", i+1);
 			scanf("%s",e.name);
 			InsertHash(&H, e);
		 }
		 else{
		 	printf("该学号已经存在\n");
		 	goto loop;
		 }
	 }
	 printf("请输入您要查找的学生学号：\n");
	 scanf("%d",&key);
	 if(SearHash(H, key, &p))
	 {
	 	printf("查找成功！学生的姓名是%s\n",H.elem[p].name);
	 	printf("学生所在表中的位置是%d\n",p);
	 }
	 else
	 	printf("查找失败，您要查找的学生不存在\n");
	  	return 0;
 }
