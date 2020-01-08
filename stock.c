#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top, S[1000];
void push(int x);//压栈
int pop();	//出栈
 
int main()
{
	int a,b;
	top = 0;
	char s[100];
	
	while(scanf("%s", s) != EOF)//每次只读取一个数字，放入s[0]. 
	{
		if(s[0] == '+')
		{
			a = pop();
			b = pop();
			push(a + b);
		}else if(s[0] == '-')
		{
			b = pop();	//减数 
			a = pop();//被减数 
			push(a - b);
		}else if(s[0] == '*')
		{
			a = pop();
			b = pop();
			push(a * b);
		}else{
			push(atoi(s));
		}
	}
	printf("%d\n",pop());
	
	return 0;
}
void push(int x) 
{
	S[++top] = x;
}
int pop()
{
	top--;
	return S[top+1];
}
 
