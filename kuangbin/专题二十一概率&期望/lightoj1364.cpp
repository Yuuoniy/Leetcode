/*
 * @Author: yuuoniy
 * @Date: 2019-05-21 11:31:41
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-21 16:28:20
 */

// 高维概率dp
/*
思路：假设dp[a][b][c][d][e][f]
表示此时已经翻出的前面四种花色的牌数对应分别为a，b，c，d
以及大小王所变对应的花色e，f时到达目标状态还需翻牌的期望次数。
dp[0][0][0][0][0][0]即答案
https://blog.csdn.net/elbadaernu/article/details/78535945
*/

// #include <algorithm>
// #include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

double dp[15][15][15][15][5][5];
int cnt[5];
int A, B, C, D;
const double eps = 1e-7;
double min(double a, double b) {
  if (a - b > eps)
    return b;
  else
    return a;
}

double dfs(int a, int b, int c, int d, int e, int f) {
  if (a > 13 || b > 13 || c > 13 || d > 13)
    return 0;
  cnt[1] = a;
  cnt[2] = b;
  cnt[3] = c;
  cnt[4] = d;
  if (e)
    cnt[e]++;
  if (f)
    cnt[f]++;
  if (cnt[1] >= A && cnt[2] >= B && cnt[3] >= C && cnt[4] >= D)
    return dp[a][b][c][d][e][f] = 0; //已经满足条件了
  if (dp[a][b][c][d][e][f] > -1)
    return dp[a][b][c][d][e][f]; //记忆化搜索
  double ans = 0;
  int num = 54 - cnt[1] - cnt[2] - cnt[3] - cnt[4]; //剩余的数目
  if (num == 0)
    return 0;
  if (e == 0) { //翻小王
    double tmp = 60;
    for (int i = 1; i <= 4; i++) {
      tmp = min(tmp, dfs(a, b, c, d, i, f));
    }
    ans += tmp / num;
  }
  if (f == 0) {
    double tmp = 60;
    for (int i = 1; i <= 4; i++) {
      tmp = min(tmp, dfs(a, b, c, d, e, i));
    }
    ans += tmp / num;
  }
  ans += dfs(a + 1, b, c, d, e, f) * (13 - a) / num;
  ans += dfs(a, b + 1, c, d, e, f) * (13 - b) / num;
  ans += dfs(a, b, c + 1, d, e, f) * (13 - c) / num;
  ans += dfs(a, b, c, d + 1, e, f) * (13 - d) / num;
  return dp[a][b][c][d][e][f] = ans + 1;
}

int main() {
  int t;
  int tt = 0;
  cin >> t;
  while (t--) {

    memset(dp, -1, sizeof(dp));
    cin >> A >> B >> C >> D;
    int falut = 0;
    if (A > 13)
      falut += A - 13;
    if (B > 13)
      falut += B - 13;
    if (C > 13)
      falut += C - 13;
    if (D > 13)
      falut += D - 13;
    if (falut > 2) {
      printf("Case %d: -1\n", ++tt);
      continue;
    }
    dfs(0, 0, 0, 0, 0, 0);
    printf("Case %d: %.7lf\n", ++tt, dp[0][0][0][0][0][0]);
  }
  return 0;
}
