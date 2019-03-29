/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (40.22%)
 * Total Accepted:    197.4K
 * Total Submissions: 490.9K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 *
 * Example:
 *
 *
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4.
 *
 * Note:
 *
 *
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n^2) complexity.
 *
 *
 * Follow up: Could you improve it to O(n log n) time complexity?
 *
 */
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    int n = nums.size();
    int dp[n];
    int inf = numeric_limits<int>::max();
    fill(dp, dp + n, inf);
    for (int i = 0; i < n; i++) {
      *lower_bound(dp, dp + n, nums[i]) = nums[i];
    }
    int res = lower_bound(dp, dp + n, inf) - dp;
    return res;
  }
};

// another solution:
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    if (nums.size() == 0) //要注意边界条件!
      return 0;
    int n = nums.size();
    int d[n];
    int len = 0;
    for (int i = 0; i < n; i++) {
      d[i] = 1;
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          if (d[j] + 1 > d[i])
            d[i] = d[j] + 1;
        }
      }
      if (d[i] > len)
        len = d[i];
    }
    return len;
  }
};
