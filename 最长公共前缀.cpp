#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) 
{
		if(strs.empty())
            return string();
		int n=0;
		int j = 0;//j:访问字符串第j个字符的index
        string pre = strs.front();
        if(strs.size() < 2) 
        	return pre;
        int len = pre.size() > 0 ? pre.size() : 1; 
        
        char pre2[len];
        bool isLoop = true;
        while(isLoop)
        {
        	for(int i = 1; i < strs.size(); i++)
            {
            	if(strs[i].empty())
            	{
            			isLoop = false;
            			break;
				}
                auto str = strs[i].begin()+j;
                if(str == strs[i].end()|| *str != pre[j])//当前字符串的第j个字符不等于当前公共前缀的第j个字符
                {
                    isLoop = false;
                    break;
                }
                if(i == strs.size()-1)
                    pre2[n++] = *str;
					                   //cout << *str<<endl;
            }
            j++;
          
        }
        pre2[n] = '\0';
        //cout << pre2 << endl;
    return string(pre2);
}
int main()
{
	vector<string> str{"c","c","c"};
	string st = longestCommonPrefix(str);
	cout << st;
	return 0;
}
