/*
 * @Author: yuuoniy
 * @Date: 2019-06-17 21:17:36
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-17 22:18:03
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

const int MAX_N = 10005;

int dp[MAX_N];
int num[MAX_N];

map<int, int> m;
int main() {
  int n;
  while (cin >> n && n != 0) {
    bool allNe = true;
    for (int i = 1; i <= n; i++) {
      cin >> num[i];
      if (num[i] >= 0)
        allNe = false;
    }
    if (allNe) {
      cout << 0 << " " << num[1] << " " << num[n] << endl;
      continue;
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    dp[1] = num[1];
    m[1] = 1;
    int cnt = 1;
    for (int i = 2; i <= n; i++) {
      if (dp[i - 1] + num[i] > num[i]) {
        dp[i] = dp[i - 1] + num[i];
        ++cnt;
        m[i] = cnt;
      } else {
        cnt = 1;
        dp[i] = num[i];
        m[i] = cnt;
      }
    }
    int pos = max_element(dp + 1, dp + n + 1) - dp;
    cout << dp[pos];
    cout << " " << num[pos - m[pos] + 1] << " " << num[pos] << endl;
  }
  return 0;
}
