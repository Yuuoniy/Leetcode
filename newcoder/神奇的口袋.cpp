/*
 * @Author: yuuoniy
 * @Date: 2019-06-18 16:42:24
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-18 16:48:03
 */

#include <cstdio>

int vol[21];
int dp[41];

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &vol[i]);
    }
    for (int i = 1; i <= n; i++) {
      for (int j =40; j >= vol[i]; j--) {
        dp[j] += dp[j - vol[i]];
      }
      dp[vol[i]]++;
    }
    printf("%d\n", dp[40]);
  }
  return 0;
}
