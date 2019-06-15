
/*
 * @Author: yuuoniy
 * @Date: 2019-06-15 20:07:21
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-15 20:56:12
 */

// 应该是最长递增自子序列
// https://blog.csdn.net/weizhuwyzc000/article/details/45823031
// 不明白为什么为 w。。呜呜呜呜：因为输入没有注释掉！傻逼
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

struct Mice {
  int idx, weight, speed;
  bool operator<(const Mice &m) const {
    return weight < m.weight || weight == m.weight && speed > m.speed;
  }
} mice[1024];

int dp[1024], pre[1024], ans[1024];
int main() {
  int w, s;
  int idx = 0;
  // freopen("in.txt", "r", stdin);
  while (~scanf("%d%d", &w, &s)) {
    mice[++idx].weight = w;
    mice[idx].speed = s;
    mice[idx].idx = idx;
  }
  sort(mice + 1, mice + 1 + idx);
  int res = -1;
  int pos = 0;
  for (int i = 1; i <= idx; i++) {
    dp[i] = 1;
    for (int j = 1; j < i; j++) {
      if (mice[j].weight < mice[i].weight && mice[j].speed > mice[i].speed) {
        if (dp[i] < dp[j] + 1) {
          pre[i] = j;
          dp[i] = dp[j] + 1;
        }
      }
    }
    if (res < dp[i]) {
      res = dp[i];
      pos = i;
    }
  }
  int cur = 0;
  printf("%d\n", dp[pos]);
  stack<int> state;
  while (pos != 0) {
    state.push(pos);
    pos = pre[pos];
  }
  while (!state.empty()) {
    printf("%d\n", mice[state.top()].idx);
    state.pop();
  }

  return 0;
}
