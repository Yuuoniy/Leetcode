/*
 * @Author: yuuoniy
 * @Date: 2019-06-20 09:47:21
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-20 09:59:55
 */

#include <iostream>

using namespace std;

int tot = 0;
int c[10];
int a[95][10];

void dfs(int idx) {
  if (idx == 9) {
    ++tot;
    // 记录这条路径
    for (int i = 1; i <= 8; i++) {
      a[tot][i] = c[i];
    }
  } else {
    for (int i = 1; i <= 8; i++) {
      c[idx] = i;
      bool ok = 1;
      for (int j = 1; j < idx; j++) {
        if (c[j] == i || idx - i == j - c[j] || idx + i == c[j] + j) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        dfs(idx + 1);
      }
    }
  }
}

int main() {
  int n;

  while (scanf("%d", &n) != EOF) {
    dfs(1);
    tot = 0;
    for (int i = 1; i <= 8; i++) {
      cout << a[n][i];
    }
    cout << endl;
  }
}
