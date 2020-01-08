#include <iostream>

using namespace std;
#define MAX 2000000

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
int main()
{
	cin >> H;
	for(int i = 1; i <= H; ++i) cin >> A[i];
	//将给定数组转换为最大堆，从下标最大的非叶节点s开始自底向上地执行maxHeapify
	for(int i = H / 2; i >= 1; i--) maxHeapify(i);
	
	for(int i = 1; i <= H; ++i)
		cout << " " << A[i];
	cout << endl;
		
	return 0;
}
