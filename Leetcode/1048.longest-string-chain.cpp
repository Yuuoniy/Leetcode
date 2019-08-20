/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 * // 第一眼看思路大概就是：套用最长递增子序列，但是判断的时候不是单纯的<,
 * 啊.. 题目选择不一定按序的，要审题啊！
 * 而是使用题目给的关系
 * 时间复杂度太高了。。
 * 感觉现在什么题都想无脑用 dp，不是太好。
 */
class Solution {
public:
  int longestStrChain(vector<string> &words) {

    int size = words.size();
    if (size == 0)
      return 0;
    sort(words.begin(),words.end(),[](string& a,string& b){
        if(a.size()!=b.size()) return a.size()<b.size();
        else return  a <b ;
    });
    int res = 1;
    vector<int> dp(words.size()+1, 1);
    for (int i = 1; i < words.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (isPro(words[j], words[i])) {
          dp[i] = max(dp[i], dp[j] + 1);
          res = max(dp[i],res);
        }
      }
    }
    return res;
    
  };
  bool isPro(string a, string b) {
    if (a.size() + 1 != b.size())
      return false;
    bool isInsert = 0;
    int j = 0, i = 0;
    for (int i = 0; i < a.size();) {
      if (a[i] == b[j]) {
        ++i;
        ++j;
        continue;
      } else if (!isInsert) {
        isInsert = 1;
        ++j;
      } else {
        return false;
      }
    }
    return true;
  }
};
