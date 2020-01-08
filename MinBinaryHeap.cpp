#include <iostream>

using namespace std;
#define MAX 2000000

int H, A[MAX + 1];
//最小堆 
void minHeapify(int i)
{
	int l, r, minimum;
	l = 2 * i;			//节点i的左子节点 
	r = 2 * i + 1;		//节点i的右子节点 
	
	//从左子节点、自身、右子节点中选出值最小的节点
	// l不大于堆大小，并且左子节点小于当前i节点。 
	if(l <= H && A[l] < A[i]) minimum = l;//左子节点小 
	else minimum = i;//当前i节点小。该条件终止递归条件。 
	//  r不大于堆大小，并且右子节点小于largest节点。 
	if(r <= H && A[r] < A[minimum]) minimum = r;	//右子节点最小 
	
	if(minimum != i)	//最小的节点不是当前节点 
	{
		swap(A[i], A[minimum]);	//最小的节点和当前i节点交换 
		//以最小节点为根节点，继续生成最小堆。直到largest等于i。 
		minHeapify(minimum); 
	}
}
int main()
{
	cin >> H;
	for(int i = 1; i <= H; ++i) cin >> A[i];
	//将给定数组转换为最小堆，从下标最小的非叶节点s开始自底向上地执行minHeapify
	for(int i = H / 2; i >= 1; i--) minHeapify(i);
	
	for(int i = 1; i <= H; ++i)
		cout << " " << A[i];
	cout << endl;
		
	return 0;
}
