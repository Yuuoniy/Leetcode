/*
 * @Author: yuuoniy 
 * @Date: 2019-03-29 22:25:01 
 * @Last Modified by:   yuuoniy 
 * @Last Modified time: 2019-03-29 22:25:01 
 */
#include <iostream>
#include <memory.h>
#include <stdio.h>

int height[105];
int dp[2][105];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &height[i]);
  }
  //求1-n最长上升子序列的长度
  for (int i = 0; i < n; i++) {
    dp[0][i] = 1;
    for (int j = 0; j < i; j++) {
      if (height[j] < height[i] && dp[0][j] + 1 > dp[0][i])
        dp[0][i] = dp[0][j] + 1;
    }
  }
//n-1的最长上升子序列的长度
  for (int i = n - 1; i >= 0; --i) {
    dp[1][i] = 1;
    for (int j = i + 1; j < n; j++) {
      if (height[j] < height[i] && dp[1][j] + 1 > dp[1][i])
        dp[1][i] = dp[1][j] + 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (ans < (dp[0][i] + dp[1][i] - 1))
      ans = dp[0][i] + dp[1][i] - 1;
  }
  printf("%d", n-ans);
  return 0;
}
