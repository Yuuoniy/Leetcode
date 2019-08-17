/*
 * @Author: yuuoniy
 * @Date: 2019-07-07 15:01:30
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-07-07 15:29:55
 */
// 开始假设所有的数自成最大递增子序列，也就是sum[i]=num[i]；
// 后面再从前向后遍历，如果前面某个数小于当前的数，那么那个数的最大递增子序列的和加上当前的数会构成更大的

#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_N = 1005;
int dp[MAX_N];
int nums[MAX_N];
int main() {
  int n;
  int res = 0;
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }
    dp[0] = nums[0];
    int res = 0;
    for (int i = 1; i < n; i++) {
      dp[i] = nums[i];
      for (int j = i-1; j >= 0; j--) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[j] + nums[i] , dp[i]); //感觉都很相似
        }
      }
      res = max(res, dp[i]);
    }
    cout << res << endl;
  }
}
