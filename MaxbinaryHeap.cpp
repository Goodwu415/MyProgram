#include <iostream>

using namespace std;
#define MAX 2000000

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
int main()
{
	cin >> H;
	for(int i = 1; i <= H; ++i) cin >> A[i];
	//����������ת��Ϊ���ѣ����±����ķ�Ҷ�ڵ�s��ʼ�Ե����ϵ�ִ��maxHeapify
	for(int i = H / 2; i >= 1; i--) maxHeapify(i);
	
	for(int i = 1; i <= H; ++i)
		cout << " " << A[i];
	cout << endl;
		
	return 0;
}
