/*
 * @Author: yuuoniy
 * @Date: 2019-06-16 15:09:24
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-16 15:13:40
 */

#include <iostream>

using namespace std;

const int MAX_N = 10005;
bool isRemove[MAX_N];

int main() {
  int l, m;
  while (cin >> l >> m) {
    for (int i = 0; i < m; i++) {
      int from, to;
      cin >> from >> to;
      for (int j = from; j <= to; j++) {
        isRemove[j] = true;
      }
    }
    int cnt = 0;
    for (int i = 0; i <= l; i++) {
      if (!isRemove[i])
        ++cnt;
    }
    cout << cnt << endl;
  }
  return 0;
}
