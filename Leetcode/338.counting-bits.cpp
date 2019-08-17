/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */
class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> dp(num + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= num; i++) {
      dp[i] = (i % 2) + dp[i / 2];
    }
    return dp;
  }
};
