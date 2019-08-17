/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */
class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    vector<bool> dp(s.length() + 1, false);
    unordered_set<string> dict = {std::begin(wordDict), std::end(wordDict)};
    dp[0] = true;
    int i, j;
    for (int i = 0; i < s.length(); i++) {
      for (int j = 0; j <= i; j++) {
        bool flag = false;
        if (dict.find(s.substr(j, i - j + 1)) != dict.end()) {
        //   cout << "find " << s.substr(j, i - j - 1) << endl;
          flag = true;
        //   cout << j << " " << i + 1 << endl;
        }
        if (flag && dp[j]) {
          dp[i + 1] = true;
          break;
        }
      }
    }
    return dp[s.length()];
  }
};
