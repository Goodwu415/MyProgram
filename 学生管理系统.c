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
			printf("������ѧ����ѧ�ţ�\n");
			scanf("%d",&stu[i].number);
		 	printf("������ѧ����������\n");
		 	scanf("%s",stu[i].name);
		 	printf("������ѧ�������䣺\n");
		 	scanf("%d",&stu[i].age);
			printf("������ѧ���ĵ�ַ��\n");
			scanf("%s",stu[i].address);
		
		}
		break;
	}
	SUM++;
//	printf("��ӳɹ���\n");

}

void del()
{
	int x;
	int i;
	printf("������ɾ����ѧ��ѧ�ţ�\n");
	scanf("%d",&x);
	
	int n=0;
	int j;

	for ( i=0; i<SUM; i++ )
	{
		if ( stu[i].number==x )
		{
			printf("ȷ��ɾ����\n �ǣ�1������2��\n");
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
	printf("�������޸ĵ�ѧ��ѧ�ţ�\n");
	scanf("%d",&x);
	 
	int  i;
	int n;
	for ( i=0; i<SUM; i++ )
	{
		if ( stu[i].number==x )
		{
			p=&stu[i];
			printf("�������޸ĵ����ݣ�\n");
			printf("1.����\n2.����\n3.��ַ\n",stu[i].name,stu[i].age,stu[i].address);
			scanf("%d",&n);
			switch(n)
			{
			case 1:
				printf("�������޸ĵ����ݣ�\n");
				*p->name=0;
				scanf("%s",p->name);
				 break;
			case 2:
				stu[i].age=0;
				printf("�������޸ĵ����ݣ�\n");
				scanf("%d",&p->age);
				 break;
			case 3:
				*p->address=0; 
				printf("�������޸ĵ����ݣ�\n");
				scanf("%s",p->address);
				break;
			default:
				printf("��ȷ�������ָ��\n");	
			}
		break;
		}
		break;
	}
}

void select_stu()
{
	int x;
	printf("��������ҵ�ѧ��ѧ�ţ�\n");
	scanf("%d",&x);
	
	int  i;
	int n;
	for ( i=0; i<SUM; i++ )
	{
		if ( stu[i].number==x )
		{
			printf("���ҳɹ�\n");
		} else {
			printf("����ѧ�Ų����ڣ�����\n");
		}
	printf("�Ƿ�鿴��\n�ǣ�1������2��\n\n\n");
	scanf("%d",&n);
	if ( n==1 )
	{
		printf("ѧ�ţ�%d\n������%s\n���䣺%d\n��ַ��%s\n",stu[i].number,stu[i].name,stu[i].age,stu[i].address); 
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
			printf("ѧ����ѧ�ţ�\n");
			printf("%d\n",stu[i].number);
			printf("ѧ����������\n");
			printf("%s\n",stu[i].name);
			printf("ѧ�������䣺\n");
			printf("%d\n",stu[i].age);
			printf("ѧ���ĵ�ַ��\n");
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
		printf("------ѧ������ϵͳ-------\n");
		printf("1.���\n");
		printf("2.�޸�\n"); 
		printf("3.ɾ��\n");
		printf("4.����\n");
		printf("5.�鿴\n");
		printf("0.�˳�\n");
		printf("������ָ�\n");
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
				printf("���������룺\n");
				printf("        	");
		 } 
	}
	return 0;
}
