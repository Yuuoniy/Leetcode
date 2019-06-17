/*
 * @Author: yuuoniy
 * @Date: 2019-06-17 13:24:06
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-17 20:10:15
 */

// https://blog.csdn.net/u013480600/article/details/40313875
//  0 1 背包问题，需要转化为整数求解

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 1000 * 30 * 100 + 5;
int max_val;
int dp[maxn];
int cnt;
int val[35];

int main() {
  double v;
  int n;
  while (scanf("%lf%d", &v, &n) == 2 && n != 0) {
    // cout << v << " " << n << endl;
    cnt = 0;
    max_val = (int)(v * 100);
    for (int i = 1; i <= n; i++) {
      int num;
      char type;
      double va = 0, vb = 0, vc = 0;
      scanf("%d\n", &num);
      bool flag = true; //标记是否为合法发票
      for (int i = 0; i < num; i++) {
        scanf("%c:%lf\n", &type, &v);
        if (type == 'A')
          va += v;
        else if (type == 'B')
          vb += v;
        else if (type == 'C')
          vc += v;
        else
          flag = false;
      }
      if (flag && va <= 600 && vb <= 600 && vc <= 600 &&
          (va + vb + vc) <= 1000) {
        val[++cnt] = (int)((va + vb + vc) * 100);
      }
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= cnt; i++) {
      for (int j = max_val; j >= val[i]; j--) {
        dp[j] = max(dp[j], dp[j - val[i]] + val[i]);
      }
    }
    printf("%.2lf\n", (dp[max_val]) / 100.0);
  }
  return 0;
}
