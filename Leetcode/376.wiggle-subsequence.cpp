/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 * 参考了别人的题解，太巧妙了！对每个状态分为两种情况，这样就很容易写出状态转移方程
 * 空间还是可以优化的
 */
class Solution {
public:
  int wiggleMaxLength(vector<int> &nums) {
    if (nums.size() < 2)
      return nums.size();
    vector<int> up(2, 0);
    vector<int> down(2, 0);
    up[0] = down[0] = 1;
    int res = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > nums[i - 1]) {
        up[i & 1] = down[(i - 1) & 1] + 1;
        down[i & 1] = down[(i - 1) & 1];
      } else if (nums[i] < nums[i - 1]) {
        up[i & 1] = up[(i - 1) & 1];
        down[i & 1] = up[(i - 1) & 1] + 1;
      } else {
        up[i & 1] = up[(i - 1) & 1];
        down[i & 1] = down[(i - 1) & 1];
      }
      res = max(res, max(up[i & 1], down[i & 1]));
    }
    return res;
  }
};
