#include <iostream>
#include <vector>
#include <stack> 

//图算法应用
// 朋友的朋友是朋友 
//question：输入 SNS 的朋友关系，判断从指定人物出发能否通过双向朋友
//	链抵达目标人物。
// 参见 挑战程序设计和数据结构 12.5  连通分量 
/* 	人生就像一部电影，你就是这部电影的主角；
	生活则是电影的内容，这是你作为主角的戏份。 
	生活平淡或者失败，只能说你还没向导演展现你的价值，
	你还没有能力让导演加戏，你是弱的，而且你很悲观。
	所以，这一切只能怪你，不能怨天尤人。
	而生活充满挫折、挑战、机会，则意味着导演看到了你，
	它想给你加戏，它看到了你或许能够让这部电影更出彩，更漂亮。 
	所以，它想磨练你、考验你、诱惑你，而你则要坚持、应对、抓住。
	这一切都是你能否演好导演给你加的戏的关键因素，
	你坚持下来了，你离成功进了一步，
	你应对了下来，你离成功更近了一步，
	你抓住了，你成功了。
	所有这一切，在生活中都是真实存在的，所谓人生如戏，
	你想让人生刻骨铭心、出彩、漂亮、成功，那么你就要
	不断的让导演给你加戏。
	当你的能力，使你能够成为一名导演的时候，你或许就要
	寻找能够成为你电影的主角了。
	你要想拍好这部电影，你就得思考这部电影要表达什么？ 
	为什么要表达这个思想出来？这个思想该怎样巧妙的表达出来？ 
	以什么方式？ 
	而这些都需要你的主角生动的表达出来，所以，这是你作为
	导演应该做到的。 
	
	演好戏，拍好戏。 
 */ 
using namespace std;

static const int MAX = 100000;
static const int NIL = -1;

int n;
//vector数组：存储用户关系，下标对应为用户，值对应用户的朋友
vector<int> G[MAX];	 
//	每个用户的朋友链，如果某个用户拥有相同的朋友，那么它们
// 	的value是一样的。 下标对应于用户id，值就是标识你属于那条链。 
int color[MAX];	 

void dfs(int r, int c)
{
	stack<int> S;	//存储朋友的id，以继续找朋友的朋友 
	S.push(r);
	color[r] = c;	//产生一条链 
	while(!S.empty())
	{
		int u = S.top();	//返回栈顶值 
		S.pop();	//出栈 
		for(int i = 0; i < G[u].size(); ++i)
		{//G[u][i],访问数组u下标中vector中,i下标的值，也就是用户的朋友id 
			int v = G[u][i];	
			if(color[v] == NIL)// ==等于NIL表示没访问过 
			{// 
				color[v] = c;	// 给这个用户在链中赋一个标识值。 
				//	把这个用户id压入栈，等会遍历这个用户是否有朋友。
				//	有的话，说明这个朋友是朋友的朋友。 
				S.push(v);		 
			}
		}
	}
}
void assignColor()
{
	int id = 1;	// 朋友链标识符 
	//初始化 
	for(int i = 0; i < n; ++i) color[i] = NIL;
	for(int u = 0; u < n; ++u) 
	{	 
		if(color[u] == NIL)//这个用户还没有找朋友 
			dfs(u, ++id);
	}
}
int main()
{// n: 用户数 m: 代表朋友关系数 

	int s, t, m, q;
	cin >> n >> m;
	for(int i = 0; i < m; ++i)
	{// s: 用户id t：用户id   表示 s t 是朋友关系 
		cin >> s >> t;
		G[s].push_back(t);	//在数组G.s下标,把 t压入s的朋友表 
		G[t].push_back(s);	//在数组G.t下标,把 s压入t的朋友表
	}
	
	assignColor();
	cin >> q;
	for(int i = 0; i < q; ++i)
	{
		cin >> s >> t;
		if(color[s] == color[t])	//比较下标对应的值 
		{
			cout << "yes" << endl;
		}else
		{
			cout << "no" << endl;
		}
	}
	return 0;
}


