#include <stdio.h>
#include <stdlib.h>

#define N 10
int SUM;
struct student{
	int number;
	char name[20];
	int age;
	char address[20];
};
struct student stu[N], *p;
void add()
{
	int i=0	;
	
	for ( ;i<N; i++)
	{
		if ( !stu[i].number )
		{
		
			printf("-------------------------------\n");
			printf("请输入学生的学号：\n");
			scanf("%d",&stu[i].number);
		 	printf("请输入学生的姓名：\n");
		 	scanf("%s",stu[i].name);
		 	printf("请输入学生的年龄：\n");
		 	scanf("%d",&stu[i].age);
			printf("请输入学生的地址：\n");
			scanf("%s",stu[i].address);
		
		}
		break;
	}
	SUM++;
//	printf("添加成功。\n");

}

void del()
{
	int x;
	int i;
	printf("请输入删除的学生学号：\n");
	scanf("%d",&x);
	
	int n=0;
	int j;

	for ( i=0; i<SUM; i++ )
	{
		if ( stu[i].number==x )
		{
			printf("确认删除？\n 是（1），否（2）\n");
			scanf("%d",&n);
			if ( n==1 )
			{
				for ( j=i; j<SUM-1; j++ )
				{
					stu[j]=stu[j+1];
				}
				SUM--;
			} else if( n==2 ) break;
		}
	break;
	}
}
void Moditf()
{
	
	int x;
	printf("请输入修改的学生学号：\n");
	scanf("%d",&x);
	 
	int  i;
	int n;
	for ( i=0; i<SUM; i++ )
	{
		if ( stu[i].number==x )
		{
			p=&stu[i];
			printf("请输入修改的内容：\n");
			printf("1.姓名\n2.年龄\n3.地址\n",stu[i].name,stu[i].age,stu[i].address);
			scanf("%d",&n);
			switch(n)
			{
			case 1:
				printf("请输入修改的内容：\n");
				*p->name=0;
				scanf("%s",p->name);
				 break;
			case 2:
				stu[i].age=0;
				printf("请输入修改的内容：\n");
				scanf("%d",&p->age);
				 break;
			case 3:
				*p->address=0; 
				printf("请输入修改的内容：\n");
				scanf("%s",p->address);
				break;
			default:
				printf("请确认输入的指令\n");	
			}
		break;
		}
		break;
	}
}

void select_stu()
{
	int x;
	printf("请输入查找的学生学号：\n");
	scanf("%d",&x);
	
	int  i;
	int n;
	for ( i=0; i<SUM; i++ )
	{
		if ( stu[i].number==x )
		{
			printf("查找成功\n");
		} else {
			printf("查找学号不存在！！！\n");
		}
	printf("是否查看？\n是（1），否（2）\n\n\n");
	scanf("%d",&n);
	if ( n==1 )
	{
		printf("学号；%d\n姓名：%s\n年龄：%d\n地址：%s\n",stu[i].number,stu[i].name,stu[i].age,stu[i].address); 
	} else if ( n==2 )
			break; 
	}
	
	
}
void print_stu()
{
	int i = 0;
	printf("-------------------------------\n");
	for ( ; i<SUM; i++ )
	{
		if ( stu[i].number )
		{
			printf("\n\n\n");
			printf("学生的学号：\n");
			printf("%d\n",stu[i].number);
			printf("学生的姓名：\n");
			printf("%s\n",stu[i].name);
			printf("学生的年龄：\n");
			printf("%d\n",stu[i].age);
			printf("学生的地址：\n");
			printf("%s\n",stu[i].address);
		}
	}
}
void init_stu()
{
	int i=0;
	for ( ; i<N; i++ )
	{
		stu[i].number = 0;
	}
}
int main(int argc, const char argv[])
{
	init_stu();
	int n;
	while (1)
	{
		printf("\n\n\n");
		printf("-------------------------\n");
		printf("------学生管理系统-------\n");
		printf("1.添加\n");
		printf("2.修改\n"); 
		printf("3.删除\n");
		printf("4.查找\n");
		printf("5.查看\n");
		printf("0.退出\n");
		printf("请输入指令：\n");
		printf("-------------------------\n");
		scanf("%d",&n);
		
		switch (n)
		{
			case 1:
				add(); 
				break;
			case 2:
				Moditf();
				break;	
			case 3:
				del(); 
				break;
			case 4:
				select_stu(); 
				break;
			case 5:
				print_stu();
				break;		
			case 0:
				break;	 
			default:
				printf("        	");
				printf("请重新输入：\n");
				printf("        	");
		 } 
	}
	return 0;
}
