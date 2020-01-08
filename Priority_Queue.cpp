#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX 2000000
#define INFTY (1<<30)
int H, A[MAX + 1];
//最大堆 
void maxHeapify(int i)//算法复杂度：O(log H) 
{
	int l, r, largest;
	l = 2 * i;			//节点i的左子节点 
	r = 2 * i + 1;		//节点i的右子节点 
	
	//从左子节点、自身、右子节点中选出值最大的节点
	// l不大于堆大小，并且左子节点大于当前i节点。 
	if(l <= H && A[l] > A[i]) largest = l;//左子节点大 
	else largest = i;//当前i节点大。该条件终止递归条件。 
	//  r不大于堆大小，并且右子节点大于largest节点。 
	if(r <= H && A[r] > A[largest]) largest = r;	//右子节点最大 
	
	if(largest != i)	//最大的节点不是当前节点 
	{
		swap(A[i], A[largest]);	//最大的节点和当前i节点交换 
		//以最大节点为根节点，继续生成最大堆。直到largest等于i。 
		maxHeapify(largest); 
	}
}

int extract()//获取队列中的最大值 
{
	int maxv;
	if(H < 1) return -INFTY;
	maxv = A[1];
	A[1] = A[H--];
	maxHeapify(1);
	return maxv;
}
void increaseKey(int i, int key)//算法复杂度：O(log n) n:队列元素数
{
	if(key < A[i])return;
	A[i] = key;
	while(i > 1 && A[i / 2] < A[i])
	{
		swap(A[i], A[i / 2]);
		i = i / 2;
	}
}
//heapIncreaseKey 和 maxHeapify 中执行兀素交换的次数都与树高成正比。
void insert(int key)//算法复杂度：O(log n) n:队列元素数 
{
	++H;
	A[H] = -INFTY;
	increaseKey(H, key);	//增加二叉堆的元素 
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
