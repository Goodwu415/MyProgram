#include <stdio.h>

int main()
{
	int n;
	int r;
	int fir,lst;// fir������һ�ε�����  cur����һ�ε����� 
	int maxdiff;	//�� 
	int i;
	int tmp;//�洢����һ������ 
	scanf("%d\n%d\n%d",&n,&fir,&lst);
	if(n > 200000)
		n = 200000;
	else if(n < 2)
		n = 2;
	
	maxdiff = lst - fir;	// ������������㣬���Ա���һ��bug�����磺��ת->kk 
	
	for(i = 1; i < n - 1; i++)//�� n = 2ʱ����forѭ��������������ֱ�� lst - fir ���ɵó����� 
	{
		scanf("%d",&tmp);	//��ǰ��
		if(lst < fir)	// �ж���һ�ε������Ƿ�С�� ����һ�ε�����
		{
			fir = lst;	//  �������� ����һ�ε����� ����Ϊ ��һ�ε�����
			lst = tmp;	// ��һ�ε����� ����Ϊ ��ǰ�� 
		}else{
			lst = tmp;// �� ֻ����һ�ε��������Ϊ��ǰ�� 
		}		
		if(lst - fir > maxdiff)	//kk: �տ�ʼ�ĵ�һ���� �� �� 0 ���������ܵõ�һ����� 
			maxdiff = lst - fir;	// ֻ���ܲ�������������и�ֵ�� 
	}
	printf("%d\n",maxdiff);	
	return 0;
}
