/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (29.16%)
 * Total Accepted:    166.1K
 * Total Submissions: 569.7K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 *
 * Example 1:
 *
 *
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 *
 * Example 2:
 *
 *
 * Input: coins = [2], amount = 3
 * Output: -1
 *
 *  完全背包问题，好久不写都忘记了。。
 *  一定要注意边界问题和特殊情况啊呜呜呜呜
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 *
 */
class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
      if(amount==0) return 0; //特殊情况！
    vector<int> dp(amount + 1, -1);
    for (int i = 0; i < coins.size(); i++) {
        if(coins[i]<=amount) //注意！否则可能会越界！
            dp[coins[i]] = 1;
    }
    for (int i = 0; i < coins.size(); i++) {
      for (int j = coins[i]; j <= amount; j++) {
        if (dp[j - coins[i]] != -1&&dp[j]!=-1)
          dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        else if(dp[j - coins[i]] != -1){
            dp[j] =  dp[j - coins[i]] + 1;
        }
      }
    }
    return dp[amount];
  }
};
