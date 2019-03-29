// P1280 尼克的任务
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
struct task {
  int begin, len;
} t[10005];

int taskBegin[10005] = {0};
int dp[10005];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &t[i].begin, &t[i].len);
    // ++taskBegin[t[i].begin];
  }
  int now = k-1; //任务开始的时间是递增的，所以这样遍历每个任务,如果没有可以自己排序
  for (int i = n - 1; i >= 0; --i) {
    if (t[now].begin != i+1)
      dp[i] = dp[i + 1] + 1;
    else
      while (now>=0&&t[now].begin == i+1) {
        dp[i] = max(dp[i], dp[i + t[now].len]);
        --now;
      }
  }
  printf("%d", dp[0]);
  return 0;
}
