/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */
// 那么如果字符串的第i-1位和第i位能组成一个10到26的数字，说明我们是在第i-2位的解码方法上继续解码。如果字符串的第i-1位和第i位不能组成有效二位数字，而且第i位不是0的话，说明我们是在第i-1位的解码方法上继续解码。所以，如果两个条件都符合，则dp[i]=dp[i-1]+dp[i-2]，否则dp[i]=dp[i-1]。

// 和爬梯子类似
class Solution {
public:
    int numDecodings(string s) {
        if(s.length()==0) return 0;
        vector<int> dp(s.size()+1,0);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); i++)
        {
           dp[i] = (s[i-1]=='0')?0:dp[i-1];
           if(i>1&&(s[i-2]=='1'||(s[i-2]=='2'&&s[i-1]<='6')))
                dp[i] += dp[i-2];
        }
        return dp[s.size()];
    }
};

