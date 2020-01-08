#include <iostream>

using namespace std;
#define MAX 2000000

int H, A[MAX + 1];
//��С�� 
void minHeapify(int i)
{
	int l, r, minimum;
	l = 2 * i;			//�ڵ�i�����ӽڵ� 
	r = 2 * i + 1;		//�ڵ�i�����ӽڵ� 
	
	//�����ӽڵ㡢�������ӽڵ���ѡ��ֵ��С�Ľڵ�
	// l�����ڶѴ�С���������ӽڵ�С�ڵ�ǰi�ڵ㡣 
	if(l <= H && A[l] < A[i]) minimum = l;//���ӽڵ�С 
	else minimum = i;//��ǰi�ڵ�С����������ֹ�ݹ������� 
	//  r�����ڶѴ�С���������ӽڵ�С��largest�ڵ㡣 
	if(r <= H && A[r] < A[minimum]) minimum = r;	//���ӽڵ���С 
	
	if(minimum != i)	//��С�Ľڵ㲻�ǵ�ǰ�ڵ� 
	{
		swap(A[i], A[minimum]);	//��С�Ľڵ�͵�ǰi�ڵ㽻�� 
		//����С�ڵ�Ϊ���ڵ㣬����������С�ѡ�ֱ��largest����i�� 
		minHeapify(minimum); 
	}
}
int main()
{
	cin >> H;
	for(int i = 1; i <= H; ++i) cin >> A[i];
	//����������ת��Ϊ��С�ѣ����±���С�ķ�Ҷ�ڵ�s��ʼ�Ե����ϵ�ִ��minHeapify
	for(int i = H / 2; i >= 1; i--) minHeapify(i);
	
	for(int i = 1; i <= H; ++i)
		cout << " " << A[i];
	cout << endl;
		
	return 0;
}
