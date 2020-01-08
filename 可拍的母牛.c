#include<stdio.h>
#define N 55
int monther_cow[N];
void monther_cow2(int n);
 
int main()
{
   int input[N];
   monther_cow2(N);
   int i = 0;
    do
    {
        scanf("%d",&input[i]);
    }while(input[i++] != 0);
 	int j; 
    for(j = 0 ; j < i-1 ; j++)
    {
        if( input[j] < 4)
        {
            printf("%d\n",monther_cow[input[j]]);
        }
         
        else
        {
            printf("%d\n",monther_cow[input[j] - 1] + monther_cow[input[j] - 3] );
        }      
    }
    return 0;
}
 
void monther_cow2(int n)//记录的斐波那契数列中对应的规律到数列
{
    int i;
    for(i = 1 ; i <= n ; i++)
    {
        if( i < 4)
        {
            monther_cow[i] = i;
        }
        else
        {
            monther_cow[i] = monther_cow[i - 1] + monther_cow[i - 3];
        }
        
    }
}
