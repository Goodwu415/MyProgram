#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

//�����ˮ��� 	water ˮ 
int main()
{
	int i;
	stack<int> S1;
	stack<pair<int, int> > S2;
	char ch;
	int sum = 0;
	cout << "Ctrl+z �������룡\n";
	for(i = 0; cin >> ch; i++)
	{
		if(ch == '\\')S1.push(i);// '\\' ���� 
		else if(ch == '/'&& S1.size()> 0)
		{
			int j = S1.top(); S1.pop();
			sum += i -j;	//���㵱ǰ�±������һ��ѹ��ջ�е��±�ľ��룬���ѽ���ۼӵ������� 
			int a = i - j;
			while(S2.size() > 0 && S2.top().first > j)
			{
				a += S2.top().second; S2.pop();
			}
			S2.push(make_pair(j, a));//��ˮ�����j��һ��'\'���±꣬ 
		 } 
	}
	vector<int> ans;
	while(S2.size()> 0)
	{
		ans.push_back(S2.top().second);
		S2.pop();
	}
	reverse(ans.begin(), ans.end());
	cout << sum << endl;
	cout << ans.size();
	for(i = 0; i < ans.size(); i++)
	{
		cout << " ";
		cout << ans[i];
	}
	return 0;
}
