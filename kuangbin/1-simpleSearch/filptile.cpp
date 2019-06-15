/*
 * @Author: yuuoniy
 * @Date: 2019-06-14 07:43:55
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-14 08:38:10
 */

// 翻转问题，先确定好第一行

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int MAX_N = 20;
int ma[MAX_N][MAX_N];
int n, m;

int opt[MAX_N][MAX_N];
int filp[MAX_N][MAX_N];
const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = {0, -1, 0, 1, 0};

int get(int x, int y) {
  int c = ma[x][y];
  for (int d = 0; d < 5; d++) {
    int xx = x + dx[d];
    int yy = y + dy[d];
    if (xx >= 0 && xx < m && yy >= 0 && yy < n) {
      c += filp[xx][yy];
    }
  }
  return c % 2;
}

int calc() {
  for (int i = 1; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (get(i - 1, j) != 0) {
        filp[i][j] = 1;
      }
    }
  }

  // 判断最后一行是否全为 0
  for (int i = 0; i < n; i++) {
    if (get(m - 1, i) != 0)
      return -1;
  }

  int res = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      res += filp[i][j];
    }
  }
  // cout << res << endl; 
  return res;
}

int solve() {
  int res = -1;
  for (int i = 0; i < 1 << n; i++) {
    memset(filp, 0, sizeof(filp));
    for (int j = 0; j < n; j++) {
      filp[0][n - j - 1] = i >> j & 1;
    }
    int num = calc();
    if (num >= 0 && (res < 0 || res > num)) {
      res = num;
      memcpy(opt, filp, sizeof(filp));
    }
  }
  if (res < 0) {
    printf("IMPOSSIBLE\n");
  } else {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        printf("%d%c", opt[i][j], j + 1 == n ? '\n' : ' ');
        
      }
    }
  }
}

int main() {
  scanf("%d%d", &m, &n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &ma[i][j]);
    }
  }
  solve();
  return 0;
}
