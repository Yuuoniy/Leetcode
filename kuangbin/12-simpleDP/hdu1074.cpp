/*
 * @Author: yuuoniy
 * @Date: 2019-06-15 17:07:09
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-15 19:17:56
 */
// https://www.cnblogs.com/neopenx/p/4048722.html
// 状态压缩 DP
// dp[i] 记录状态 i 的情况，最后的状态是dp[i<<n-1] ,因为每个作业都要做。

#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct hw {
  int ddl;
  int duration;
  char name[150];
} hws[25];

const int INF = 0x3f3f3f3f;
const int maxn = (1 << 15) + 10;

struct node {
  int score;   // 扣分
  int nowtime; // 当前状态对应的时间
  int num;     //当前任务
  int pre;     //前一个状态
} dp[maxn];

int t, n;
int totTime;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    totTime = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s%d%d", &hws[i].name, &hws[i].ddl, &hws[i].duration);
    }
    dp[0].score = 0; //
    dp[0].nowtime = 0;
    int M = (1 << n) - 1;
    for (int i = 1; i <= M; i++) {
      dp[i].score = INF;
      for (int j = n - 1; j >= 0; j--) {
        if ((1 << j) & i) {
          int k = i ^ (1 << j); //上一个状态
          int x = dp[k].nowtime + hws[j].duration - hws[j].ddl;
          if (x < 0)
            x = 0;
          if (dp[k].score + x < dp[i].score) {
            dp[i].score = dp[k].score + x;
            dp[i].num = j;
            dp[i].nowtime = dp[k].nowtime + hws[j].duration;
            dp[i].pre = k;
          }
        }
      }
    }

    printf("%d\n", dp[M].score);
    stack<int> state;
    while (M != 0) {
      state.push(dp[M].num);
      M = dp[M].pre;
    }
    while (!state.empty())
    {
      printf("%s\n",hws[state.top()].name);
      state.pop();
    }
    
  }

  return 0;
}
