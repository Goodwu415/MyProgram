#include <stdio.h>
#include <string.h>
typedef struct{
	char name[100];//人物名 
	int time;//时间，单位：ms 
}TASK;
int length = 0;
void Init(TASK *p, int len/*, TASK task*/);//初始化 
void enqueue(TASK a[],TASK task);//入队 
TASK dequeue(TASK a[]);//出队 
int main()
{
	int n,q,m; //任务数 
	int i;
	int count = 0;//完成的时间片 
	int total = 0;	//总的时间片 
	
	TASK a[n];
	TASK b[n];
	TASK *pa = a;
	scanf("%d%d",&m,&q);
	if(m < 1)
		n = 1;
	else if(m > 100000)
		n = 100000;
	else{
		n = m;
	}
	if(q < 1)
		q = 1;
	else if(q > 1000)
		q = 1000;
	length = n;
	Init(pa,n);//初始化
	//(pa+1)->name[0] = 'j';
	//printf("%c\n",(pa+0)->name[0]);
	
	while(length > 0)
	{
		TASK tmp;
		printf("length %d\n",length);
		printf("-------------------------------\n");
		tmp = dequeue(a);
		printf("%s %d\n",tmp.name,tmp.time);
		printf("-------------------------------\n");
		if(tmp.time - q > 0)//时间片不够 
		{
			tmp.time = tmp.time - q;
			total += q; 
			enqueue(a,tmp);
		 }else if(tmp.time - q <= 0) //时间片够用 
		{
			strcpy(b[count].name,tmp.name);
			b[count].time =	total + tmp.time;//当前任务使用的时间片 
			count++;
			total += tmp.time;
		 } 
	}
//	for(i = 0; i < n; i++)
//	{
//		//printf("length %d\n",length);
//		printf("%s %d",b[i].name,b[i].time);
//		if(i+1 < n) printf("\n");
//		
//	}
	
	return 0;
}
void enqueue(TASK a[],TASK task)
{
	strcpy(a[length].name,task.name);
	a[length].time = task.time;
	length += 1;
}
void Init(TASK *p, int len/*,TASK task*/)
{
	int i;
	for(i = 0; i < len; i++)
	{
		scanf("%s%d",(p+i)->name,&(p+i)->time);
	}
//	for(i = 0; i < len; i++)
//		printf("%s %d\n",(p+i)->name,(p+i)->time);
}
TASK dequeue(TASK a[]) 
{
	TASK tmp;
	int i;
	//tmp.name = a[0].name;
	strcpy(tmp.name,a[0].name);
	tmp.time = a[0].time;
	for(i = 0; i < length-1; i++)
	{
		
		strcpy(a[i].name, a[i+1].name);
		a[i].time = a[i+1].time;
	}
	length -= 1;
	return tmp;
}

