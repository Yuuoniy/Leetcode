/*
* @Author: Yuuoniy
* @Date:   2017-11-09 19:59:33
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-09 20:52:08
*/
class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    int i = 1, j = 0, n = s.size();
    vector<int> dp(n + 1, 0);
    while (i < s.size()) {
      if (s[i] == s[j])
        dp[++i] = ++j;  //从1到size()对应 而不是0-size()-1
      else if (j == 0)
        i++;
      else
        j = dp[j];  //回退
    }
    return dp[n] &&
           dp[n] % (n - dp[n]) == 0;  // dp[n] 代表最后一个重复子串的第一个位置
  }
};

// KMP算法
