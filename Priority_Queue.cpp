#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX 2000000
#define INFTY (1<<30)
int H, A[MAX + 1];
//���� 
void maxHeapify(int i)//�㷨���Ӷȣ�O(log H) 
{
	int l, r, largest;
	l = 2 * i;			//�ڵ�i�����ӽڵ� 
	r = 2 * i + 1;		//�ڵ�i�����ӽڵ� 
	
	//�����ӽڵ㡢�������ӽڵ���ѡ��ֵ���Ľڵ�
	// l�����ڶѴ�С���������ӽڵ���ڵ�ǰi�ڵ㡣 
	if(l <= H && A[l] > A[i]) largest = l;//���ӽڵ�� 
	else largest = i;//��ǰi�ڵ�󡣸�������ֹ�ݹ������� 
	//  r�����ڶѴ�С���������ӽڵ����largest�ڵ㡣 
	if(r <= H && A[r] > A[largest]) largest = r;	//���ӽڵ���� 
	
	if(largest != i)	//���Ľڵ㲻�ǵ�ǰ�ڵ� 
	{
		swap(A[i], A[largest]);	//���Ľڵ�͵�ǰi�ڵ㽻�� 
		//�����ڵ�Ϊ���ڵ㣬�����������ѡ�ֱ��largest����i�� 
		maxHeapify(largest); 
	}
}

int extract()//��ȡ�����е����ֵ 
{
	int maxv;
	if(H < 1) return -INFTY;
	maxv = A[1];
	A[1] = A[H--];
	maxHeapify(1);
	return maxv;
}
void increaseKey(int i, int key)//�㷨���Ӷȣ�O(log n) n:����Ԫ����
{
	if(key < A[i])return;
	A[i] = key;
	while(i > 1 && A[i / 2] < A[i])
	{
		swap(A[i], A[i / 2]);
		i = i / 2;
	}
}
//heapIncreaseKey �� maxHeapify ��ִ��أ�ؽ����Ĵ����������߳����ȡ�
void insert(int key)//�㷨���Ӷȣ�O(log n) n:����Ԫ���� 
{
	++H;
	A[H] = -INFTY;
	increaseKey(H, key);	//���Ӷ���ѵ�Ԫ�� 
}
int main()
{
	int key;
	char com[10];
	while(1)
	{
		scanf("%s", com);
		if(com[0] == 'e' && com[1] == 'n')break;
		if(com[0] == 'i')
		{
			scanf("%d", &key);
			insert(key);
		}else{
			printf("%d\n", extract());
		}
	}
	
	return 0;
}
