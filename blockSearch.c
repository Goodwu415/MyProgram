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
	for(i = 0; i < 4; i++)//ȷ��ģ�����ʼֵ�����ֵ  
	{	// index�����С 
		if(j + 1 < len)
		{
			index[i].start = j + 1;//ȷ��ÿ���鷶Χ����ʼֵ
			j = j + 1;
		}else break;
		if(j + 4 < len)
		{
			index[i].end = j + 4;	//ȷ��ÿ���鷶Χ�Ľ���ֵ
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
		
		index[i].key = a[j];// ȷ��ÿ���鷶Χ��Ԫ�ص����ֵ 
	}
	printf("index[2].start = %d\n",index[3].start);
	printf("index[2].end = %d\n",index[3].end);
	printf("index[2].key = %d\n", index[3].key);
	printf("������Ҫ���ҵ����֣�");
	scanf("%d",&key);
	k = search(key, a);
	
	if ( k >= 0)
		printf("���ҳɹ������ҵ���%d������ĵ�%d��λ��\n",key,k+1);
	else
		printf("����ʧ��\n");
	return 0;
}
// 4 index�����С 
int search(int key, int a[])
{
	int i,j;
	i = 0;
	while(i < 4 && key > index[i].key)//ȷ�����ĸ����� 
		i++;	
	if(i >= 4) 	//���ڷֵõĿ������򷵻�-1  
		return -1;
	j = index[i].start;	//j ���ڿ鷶Χ����ʼֵ
	while(j <= index[i].end && a[j] != key) //��ȷ���Ŀ��ڽ��в���
		j++;
	if(j > index[i].end)//������ڿ鷶Χ�Ľ���ֵ�� ��˵��û��Ҫ���ҵ����� j��-1
		j = -1;
	return j; 
}
