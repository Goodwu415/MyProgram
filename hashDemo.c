#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define OK 1
#define ERROR 0
typedef int status;
#define NULLKEY 0
#define N 10	//data count 
typedef int keytype;
typedef struct
{
	keytype key;
	int ord;
}Elemtype;

#define EQ(a,b)((a)==(b)) 
int hashsize[] = {11, 19,29,37};//hash table 容量递增table，one 合适的素数序列
int m = 0;		//tash table length
typedef struct
{
	Elemtype *elem;
	int count;
	int sizeindex;
 } Hashtable;
 
#define success 1
#define unsucess 0
#define duplicate -1
status Inithashtable(Hashtable *h)//constructor one null hash table
{
	int i;
	(*h).count = 0;
	(*h).sizeindex = 0;
	m = hashsize[0];
	(*h).elem = (Elemtype*)malloc(m*sizeof(Elemtype));
	if(!(*h).elem)
		exit(OVERFLOW);// new faild
	for(i = 0; i < m; i++)
		(*h).elem[i].key = NULLKEY;
	return OK; 
} 
void Destroyhashtable(Hashtable *h)// hash table 存在，销毁hashtable 
{
	free((*h).elem);
	(*h).elem = NULL;
	(*h).count = 0;
	(*h).sizeindex = 0; 
}
unsigned Hash(keytype k)
{
	return k%m;
}
void collision(int *p, int d)	//线性探测再散列
{
	*p = (*p + d)%m;
}
status Searchhash(Hashtable h, keytype k, int *p, int *c)//查找关键字h的元素
{
	*p = Hash(k);	//求哈希地址
	while(h.elem[*p].key != NULLKEY && !EQ(k, h.elem[*p].key))
	{
		(*c)++;
		if(*c < m)
			collision(p, *c);
		else
			break;
	}
	if EQ(k,h.elem[*p].key)
		return success;
	else
		return unsucess;
}
status Inserthash(Hashtable *h, Elemtype e);

void Recreatehashtable(Hashtable *h)	//重建哈希表
{
	int i, count = (*h).count;
	Elemtype *p, *elem = (Elemtype*)malloc(count*sizeof(Elemtype));
	p = elem;
	printf("重建哈希表\n");
	for(i = 0; i < m; i++)
	{
		if(((*h).elem+i)->key != NULLKEY)
			*p++ = *((*h).elem+i);
		(*h).count = 0;
		(*h).sizeindex++;	//增大存储容量
		m = hashsize[(*h).sizeindex];
		p = (Elemtype*)realloc((*h).elem, m*sizeof(Elemtype));
		if(!p)
			exit(OVERFLOW);	//存储分配失败
		(*h).elem = p;
		for(i = 0; i < m; i++) 
			(*h).elem[i].key = NULLKEY;
		for(p = elem; p < elem+count; p++)
			Inserthash(h, *p);
	}
}
status Inserthash(Hashtable *h, Elemtype e)//查找不成功时插入 
{
	int c, p;
	c = 0;
	if(Searchhash(*h, e.key, &p, &c))
		return duplicate;
	else if(c < hashsize[(*h).sizeindex] / 2)
	{
		(*h).elem[p] = e;
		++(*h).count;
		return OK;
	}
	else
		Recreatehashtable(h);
	return ERROR;
 } 
 void Traversehash(Hashtable h, void(*Vi)(int ,Elemtype))//按哈希地址的顺序遍历哈希表
 {
 	int i;
 	printf("哈希地址0~%d\n", m-1);
 	for(i = 0; i < m; i++)
 		if(h.elem[i].key != NULLKEY)
 			Vi(i,h.elem[i]);
} 
status Find(Hashtable h, keytype k, int *p)
{
	int c = 0;
	*p = Hash(k);
	while(h.elem[*p].key != NULLKEY && !EQ(k, h.elem[*p].key))	
	{
		c++;
		if( c < m)
			collision(p, c);
		else
			return unsucess;
	}
	if(EQ(k, h.elem[*p].key))
		return success;
	else
		return unsucess;
}
void print(int p, Elemtype r)
{
	printf("address = %d(%d, %d)\n", p,r.key, r.ord);
}
int main()
{
	Elemtype r[N] = {{17,1},{60,2},{29,3},{38,4},{1,5},{2,6},{3,7},{4,8},{60,9},{13,10}};
	Hashtable h;
	int i,p;
	status j;
	keytype k;
	Inithashtable(&h);
	for(i = 0; i < N; i++)
	{
		j = Inserthash(&h, r[i]);
		if( j == duplicate)
			printf("表中已有关键字为%d的记录，无法再插入记录(%d,%d)\n",r[i].key, r[i].key, r[i].ord);
	}
	printf("按哈希地址的顺序遍历哈希表：\n");
	Traversehash(h, print);
	printf("请输入待查找记录的关键字：");
	scanf("%d", &k);
	j = Find(h, k, &p);
	if(j == success)
		print(p, h.elem[p]);
	else
		printf("没找到\n");
	j = Inserthash(&h, r[i]);
	
	if(j == ERROR)	//重建哈希表 
		j = Inserthash(&h, r[i]);
	printf("按哈希地址的顺序遍历重建后的哈希表：\n");
	Traversehash(h, print);
	printf("请输入待查找的关键字：");
	scanf("%d",&k);
	j = Find(h,k, &p);
	
	if(j == success)
		print(p, h.elem[p]);
	else
		printf("没找到\n");
	Destroyhashtable(&h);
	
	return 0;
}
