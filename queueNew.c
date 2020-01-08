#include <stdio.h>
#include <string.h>

#define LEN 100005
typedef struct{
	char name[100];//人物名 
	int time;//时间，单位：ms 
}TASK;

TASK Q[LEN];
int length = 0;
int head,tail;
void Init(int len/*, TASK task*/);//初始化 
void enqueue(TASK task);//入队 
TASK dequeue();//出队 
int min(int a, int b){ return a < b ? a:b;}
int main()
{
	int n,q; //任务数 
	int c;

	int total = 0;	//总的时间片 
	
	TASK tmp;
	
	scanf("%d%d",&n,&q);
	
	if(q < 1)
		q = 1;
	else if(q > 1000)
		q = 1000;

	//length = n;
	Init(n);//初始化

	head = 1; tail = n + 1; 
	while(head != tail)
	{
		tmp = dequeue();
		
		c = min(q, tmp.time);//执行时间片q或所需时间tmp.time的处理 
		
		tmp.time -= c;	//计算剩余时间
		total += c;	//总的时间
		if(tmp.time > 0) enqueue(tmp);//时间片不够，重新加入队列
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

