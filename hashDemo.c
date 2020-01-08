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
int hashsize[] = {11, 19,29,37};//hash table ��������table��one ���ʵ���������
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
void Destroyhashtable(Hashtable *h)// hash table ���ڣ�����hashtable 
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
void collision(int *p, int d)	//����̽����ɢ��
{
	*p = (*p + d)%m;
}
status Searchhash(Hashtable h, keytype k, int *p, int *c)//���ҹؼ���h��Ԫ��
{
	*p = Hash(k);	//���ϣ��ַ
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

void Recreatehashtable(Hashtable *h)	//�ؽ���ϣ��
{
	int i, count = (*h).count;
	Elemtype *p, *elem = (Elemtype*)malloc(count*sizeof(Elemtype));
	p = elem;
	printf("�ؽ���ϣ��\n");
	for(i = 0; i < m; i++)
	{
		if(((*h).elem+i)->key != NULLKEY)
			*p++ = *((*h).elem+i);
		(*h).count = 0;
		(*h).sizeindex++;	//����洢����
		m = hashsize[(*h).sizeindex];
		p = (Elemtype*)realloc((*h).elem, m*sizeof(Elemtype));
		if(!p)
			exit(OVERFLOW);	//�洢����ʧ��
		(*h).elem = p;
		for(i = 0; i < m; i++) 
			(*h).elem[i].key = NULLKEY;
		for(p = elem; p < elem+count; p++)
			Inserthash(h, *p);
	}
}
status Inserthash(Hashtable *h, Elemtype e)//���Ҳ��ɹ�ʱ���� 
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
 void Traversehash(Hashtable h, void(*Vi)(int ,Elemtype))//����ϣ��ַ��˳�������ϣ��
 {
 	int i;
 	printf("��ϣ��ַ0~%d\n", m-1);
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
			printf("�������йؼ���Ϊ%d�ļ�¼���޷��ٲ����¼(%d,%d)\n",r[i].key, r[i].key, r[i].ord);
	}
	printf("����ϣ��ַ��˳�������ϣ��\n");
	Traversehash(h, print);
	printf("����������Ҽ�¼�Ĺؼ��֣�");
	scanf("%d", &k);
	j = Find(h, k, &p);
	if(j == success)
		print(p, h.elem[p]);
	else
		printf("û�ҵ�\n");
	j = Inserthash(&h, r[i]);
	
	if(j == ERROR)	//�ؽ���ϣ�� 
		j = Inserthash(&h, r[i]);
	printf("����ϣ��ַ��˳������ؽ���Ĺ�ϣ��\n");
	Traversehash(h, print);
	printf("����������ҵĹؼ��֣�");
	scanf("%d",&k);
	j = Find(h,k, &p);
	
	if(j == success)
		print(p, h.elem[p]);
	else
		printf("û�ҵ�\n");
	Destroyhashtable(&h);
	
	return 0;
}
