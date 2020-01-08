#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

//计算积水面积 	water 水 
int main()
{
	int i;
	stack<int> S1;
	stack<pair<int, int> > S2;
	char ch;
	int sum = 0;
	cout << "Ctrl+z 结束输入！\n";
	for(i = 0; cin >> ch; i++)
	{
		if(ch == '\\')S1.push(i);// '\\' 反义 
		else if(ch == '/'&& S1.size()> 0)
		{
			int j = S1.top(); S1.pop();
			sum += i -j;	//计算当前下标距离上一次压入栈中的下标的距离，并把结果累加到总面积里。 
			int a = i - j;
			while(S2.size() > 0 && S2.top().first > j)
			{
				a += S2.top().second; S2.pop();
			}
			S2.push(make_pair(j, a));//积水面积，j上一个'\'的下标， 
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
