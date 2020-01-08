#include <stdio.h> 


typedef struct
{
	char suit;//花色 
	int value;//数字
}CARD;
void choice(CARD a[],int len);//选择排序 
void bubb(CARD a[],int len);//冒泡排序
int isStable(CARD c1[], CARD c2[],int n);
int main()
{
	int n;
	CARD card[36];//花色 
	CARD card2[36];//数字
	int i;
	
	scanf("%d",&n);	
	if( n > 36)
		n = 36;
	else if( n < 1)
		n = 1;
	setbuf(stdin,NULL);//清空标准输入流 
	for(i = 0; i < n; i++)
	{
		scanf("%c",&card[i].suit);
		if(i < n-1)
			scanf("%d ",&card[i].value);
		else
			scanf("%d",&card[i].value);
	}
	for(i = 0; i < n; i++)
	{
		card2[i].suit = card[i].suit;
		card2[i].value = card[i].value;
	}
	bubb(card,n);
	choice(card2, n);
	for(i = 0; i < n; i++)
	{
		if(i > 0)printf(" ");
		printf("%c%d",card[i].suit,card[i].value);
	}
	printf("\nStable\n");
	for(i = 0; i < n; i++)
	{
		if(i > 0)printf(" ");
		printf("%c%d",card2[i].suit,card2[i].value);
	}
	printf("\n");
	if(isStable(card,card2,n))
		printf("Stable\n");
	else
		printf("Not stable\n");
	return 0;
}
void bubb(CARD a[],int n)
{
	
	int i = 0;//未排序部分的起始下标
	int j;
	int flag = 1; 
	int tmp = 0;
	char tmp2 = 0;
	while(flag)
	{
		flag = 0;
		for(j = n - 1; j > i; j--)
		{
			if(a[j].value < a[j - 1].value)
			{
				tmp = a[j].value;
				a[j].value = a[j - 1].value;
				a[j - 1].value = tmp;
				tmp2 = a[j].suit;
				a[j].suit = a[j -1].suit;
				a[j - 1].suit = tmp2;
				flag = 1;
				//count++;
			}
		}
		i++;
	}
}
void choice(CARD a[],int n)
{
	int i,j,minj=0;
	int tmp = 0;
	char tmp2 = NULL;
	for(i = 0; i < n; i++)
	{
		minj = i;
		for(j = i+1;j < n; j++)
		{
			if(a[j].value < a[minj].value)
				minj = j;
		}
		if(minj != i)
		{
			tmp = a[i].value;
			a[i].value = a[minj].value;
			a[minj].value = tmp;
			tmp2 = a[i].suit;
			a[i].suit = a[minj].suit;
			a[minj].suit = tmp2;
			//count++;
		} 
	}
}
int isStable(CARD c1[], CARD c2[],int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(c1[i].suit != c2[i].suit)return 0;
	}
	return 1;
}
