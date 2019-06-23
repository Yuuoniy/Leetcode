/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
// 最长回文子串
// d[i][j] 表示区间 [i,j] 是否为回文串
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==0) return "";
        int dp[s.size()+5][s.size()+5]={0};
        int left = 0,right = 0,len = 0;
        for (int i = 0; i < s.size(); i++)
        {
            dp[i][i] = 1;
            for (int j = 0;j<i; j++)
            {
               dp[j][i] = (s[i]==s[j]&&(i-j<2||dp[j+1][i-1]));
               if(dp[j][i]&&len<(i-j+1)){
                   len = i-j+1;
                   left = j;
                   right = i;
               }
            }
            
        }
        return s.substr(left,right-left+1);
    }
};
