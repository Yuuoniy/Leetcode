/*
 * @Author: yuuoniy
 * @Date: 2019-05-22 10:31:38
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-22 11:03:59
 */

/*
 逆向 dp
倒着遍历时间，然后遍历每一个位置
dp[i][j] += max(dp[i+1][j], max(dp[i+1][j-1], dp[i+1][j+1]));
*/

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 100005;

int dp[MAX_N][15];

int main() {
  int n;
  int a, b, max_time = 0;
  while (scanf("%d", &n) && n != 0) {
    memset(dp, 0, sizeof(dp));
    max_time = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &a, &b);
      dp[b][a + 1]++;
      max_time = b > max_time ? b : max_time;
    }
    for (int i = max_time - 1; i >= 0; i--) {
      for (int j = 11; j >= 1; j--) {
        dp[i][j] += max(dp[i + 1][j], max(dp[i + 1][j + 1], dp[i + 1][j - 1]));
      }
    }
    printf("%d\n", dp[0][6]);
  }
  return 0;
}
