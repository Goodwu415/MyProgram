#include <stdio.h>
#include <string.h>

#define LEN 100005
typedef struct{
	char name[100];//������ 
	int time;//ʱ�䣬��λ��ms 
}TASK;

TASK Q[LEN];
int length = 0;
int head,tail;
void Init(int len/*, TASK task*/);//��ʼ�� 
void enqueue(TASK task);//��� 
TASK dequeue();//���� 
int min(int a, int b){ return a < b ? a:b;}
int main()
{
	int n,q; //������ 
	int c;

	int total = 0;	//�ܵ�ʱ��Ƭ 
	
	TASK tmp;
	
	scanf("%d%d",&n,&q);
	
	if(q < 1)
		q = 1;
	else if(q > 1000)
		q = 1000;

	//length = n;
	Init(n);//��ʼ��

	head = 1; tail = n + 1; 
	while(head != tail)
	{
		tmp = dequeue();
		
		c = min(q, tmp.time);//ִ��ʱ��Ƭq������ʱ��tmp.time�Ĵ��� 
		
		tmp.time -= c;	//����ʣ��ʱ��
		total += c;	//�ܵ�ʱ��
		if(tmp.time > 0) enqueue(tmp);//ʱ��Ƭ���������¼������
		else{
			printf("%s %d\n",tmp.name, total);
		} 
	}
//	
	return 0;
}
void enqueue(TASK task)
{
	Q[tail] = task;
	tail = (tail + 1) % LEN;
}
void Init(int len/*,TASK task*/)
{
	//TASK *p = Q;
	int i;
	for(i = 1; i <= len; i++)
	{
		scanf("%s%d",Q[i].name,&Q[i].time);
	}
}
TASK dequeue() 
{
	TASK tmp;
	
	tmp = Q[head];
	head = (head + 1) % LEN;
	return tmp;
}

