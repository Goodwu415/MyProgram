#include <stdio.h>

	
typedef struct index
{
	int key;
	int start;
	int end;
}INDEX;
int search(int key, int a[]);
//struct index index[4];
INDEX index[4];
int main()
{
	

	int i, j = -1,k,key;
	
	int a[] = {23,33,39,44,62,79,324,444,553,691,976,8784,8794,9874,12331,21231};
	int len = sizeof(a)/sizeof(int);
	for(i = 0; i < 4; i++)//确认模块的起始值和最大值  
	{	// index数组大小 
		if(j + 1 < len)
		{
			index[i].start = j + 1;//确定每个块范围的起始值
			j = j + 1;
		}else break;
		if(j + 4 < len)
		{
			index[i].end = j + 4;	//确定每个块范围的结束值
			j = j + 4;
		}else if(len-1 > j){
			index[i].end = j+(len-1 - j);
			j = j + (len-1 - j);
		}else if(len-1 == j)
		{
			index[i].end = j;
			//j = j + (len-1 - j);
		}
		else{
			break;
		}
		
		index[i].key = a[j];// 确定每个块范围中元素的最大值 
	}
	printf("index[2].start = %d\n",index[3].start);
	printf("index[2].end = %d\n",index[3].end);
	printf("index[2].key = %d\n", index[3].key);
	printf("请输入要查找的数字：");
	scanf("%d",&key);
	k = search(key, a);
	
	if ( k >= 0)
		printf("查找成功，查找的数%d在数组的第%d的位置\n",key,k+1);
	else
		printf("查找失败\n");
	return 0;
}
// 4 index数组大小 
int search(int key, int a[])
{
	int i,j;
	i = 0;
	while(i < 4 && key > index[i].key)//确定在哪个块中 
		i++;	
	if(i >= 4) 	//大于分得的块数，则返回-1  
		return -1;
	j = index[i].start;	//j 等于块范围的起始值
	while(j <= index[i].end && a[j] != key) //在确定的块内进行查找
		j++;
	if(j > index[i].end)//如果大于块范围的结束值， 则说明没有要查找的数， j置-1
		j = -1;
	return j; 
}
