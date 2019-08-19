/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */
class Solution {
public:
  int rob(vector<int> &nums) {
    int size = nums.size();
    if(size==0) return 0;
    int dp[size + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = nums[0];
    int res = dp[0];
    for (int i = 1; i < size; i++) {
      if (i > 1)
        dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
      else
        dp[i] = max(dp[i - 1], nums[i]);
      res = max(dp[i], res);
    }
    return res;
  }
};
