#include <stdio.h>

int main()
{
	int n;
	int r;
	int fir,lst;// fir：上上一次的输入  cur：上一次的输入 
	int maxdiff;	//差 
	int i;
	int tmp;//存储最新一次输入 
	scanf("%d\n%d\n%d",&n,&fir,&lst);
	if(n > 200000)
		n = 200000;
	else if(n < 2)
		n = 2;
	
	maxdiff = lst - fir;	// 最大差，方便后面计算，可以避免一个bug，比如：跳转->kk 
	
	for(i = 1; i < n - 1; i++)//当 n = 2时，此for循环不成立，所以直接 lst - fir 即可得出最大差 
	{
		scanf("%d",&tmp);	//当前数
		if(lst < fir)	// 判断上一次的输入是否小于 上上一次的输入
		{
			fir = lst;	//  成立，把 上上一次的输入 更新为 上一次的输入
			lst = tmp;	// 上一次的输入 更新为 当前数 
		}else{
			lst = tmp;// 否： 只把上一次的输入更新为当前数 
		}		
		if(lst - fir > maxdiff)	//kk: 刚开始的第一个数 的 减 0 操作，可能得到一个最大差。 
			maxdiff = lst - fir;	// 只对能产生最大差的数进行赋值。 
	}
	printf("%d\n",maxdiff);	
	return 0;
}
