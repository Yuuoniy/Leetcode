/*
 * @Author: yuuoniy
 * @Date: 2019-06-17 12:19:19
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-17 12:42:47
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  int n;
  while (~scanf("%d", &n)) {
    char proxy[1000][16];
    char server[2000][16];
    for (int i = 0; i < n; i++) {
      scanf("%s", proxy[i]);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      scanf("%s", server[i]);
    }
    int index = 0, count = 0, flag = 1;
    while (flag && index != m) {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        int j = index;
        while (strcmp(proxy[i], server[j]) && j < m) {
          j++;
        }
        cnt = max(cnt, j - index);
      }
      // cout << cnt << endl;
      if (cnt == 0) {
        flag = 0;
        break;
      }
      ++count;
      index += cnt;
    }
    if (flag)
      printf("%d\n", count - 1);
    else
      printf("-1\n");
  }
  return 0;
}
