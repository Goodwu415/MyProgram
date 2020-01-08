class Solution {
public:
    int myAtoi(string str) {
        int i;
        long long sum = 0;
        bool f = true;
        bool pre = true;// true:+ false: -
        for(i = 0; i < str.length(); ++i)
        {
            if(str[i] == ' ')
            {
                if(!f)
                {
                   break;
                }
                continue;
            }
            if(f)
            {
                 if(str[i] == '+')
                 {
                    f = false;
                 }else if(str[i] == '-')
                 {
                     f = false;
                     pre = false;
                 }else if(str[i] >= '0' && str[i] <= '9')
                 {
                     f = false;
                     sum = sum * 10 +(str[i] - '0');
                     continue;
                 }else
                 {
                     return 0;
                 }
            }else
            {
                if(str[i] >= '0' && str[i] <= '9')
                {
                     sum = sum * 10 +(str[i] - '0');
                    
                    if(sum > pow(2,31)-1)
                    {
                        if(!pre)
                        {
                            sum = -sum;
                            if(sum <= pow(-2, 31))
                                return pow(-2, 31);
                        }else
                        {
                            return pow(2,31)-1;
                        }
                        
                    }
                }else //其他符号
                {
                    if(!pre)
                    {
                        sum = -sum;
                    }
                    return sum;
                }
            }
        }
        //遍历结束
        if(!pre)
        {
            sum = -sum;
        }
        return sum;
    }
    
};
