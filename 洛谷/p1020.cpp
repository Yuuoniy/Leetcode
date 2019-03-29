/*
 * @Author: yuuoniy
 * @Date: 2019-03-29 20:28:50
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-03-29 20:44:42
 */
//优化要用树状数组，还没学过，就先用 n^2 的吧，学了再改
// P1020 导弹拦截
#include <algorithm>
#include <memory.h>
#include <stdio.h>

using namespace std;

int height[100005];
int main() {

  int n = 0;
  while (~scanf("%d", &height[n])) {
    ++n;
  }
  // printf("finish reading\n");
  int p1[n], p2[n];
  int ans1 = 0, ans2 = 0;
  //求最长非上升子序列
  for (int i = n - 1; i >= 0; --i) {
    p1[i] = 1;
    for (int j = i + 1; j < n; j++) {
      if (height[j] <= height[i]) {
        if (p1[j] + 1 > p1[i])
          p1[i] = p1[j] + 1;
      }
    }
    if (p1[i] > ans1)
      ans1 = p1[i];
  }
  //求最长上升子序列
  for (int i = 0; i < n; i++) {
    p2[i] = 1;
    for (int j = 0; j < i; j++) {
      if (height[j] < height[i]) {
        if (p2[j] + 1 > p2[i])
          p2[i] = p2[j] + 1;
      }
    }
    if (ans2 < p2[i])
      ans2 = p2[i];
  }
  printf("%d\n%d", ans1, ans2);
  return 0;
}
