/*
 * @Author: yuuoniy
 * @Date: 2019-05-20 17:32:11
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-20 20:16:35
 */
//对于一个银行，可以抢或者不抢
//危险率是P，那么安全率就是1-P，那么XX抢劫的所有银行的安全率之积就不能小于1-P，这样就变成了一个01背包的裸题。

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAX_N = 100005;
double dp[MAX_N]; // 表示钱数
int money[105];
double pro[105];

int main() {

  int t;
  int tt = 0;
  double p;
  cin >> t;
  while (t--) {
    int n;
    cin >> p >> n;
    int sum = 0;
    p = 1.0 - p; //危险率转化为安全率
    for (int i = 0; i < n; i++) {
      scanf("%d%lf", &money[i], &pro[i]);
      sum += money[i];
      pro[i] = 1.0 - pro[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = 1; //起始状态
    //每一个都是选或者不选，选的话 sum 至少要>= money[i]
    for (int i = 0; i < n; i++) {
      for (int j = sum; j >= money[i]; j--) {
        //选安全率最高的
        dp[j] = max(dp[j], dp[j - money[i]] * pro[i]);
      }
    }
    int i;
    for (i = sum; i >= 0; i--) {
      if (dp[i] >= p) //找到钱数最多并且不被抓到
        break;
    }
    printf("Case %d: %d\n", ++tt, i);
  }
  return 0;
}
