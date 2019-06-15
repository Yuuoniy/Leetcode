/*
 * @Author: yuuoniy
 * @Date: 2019-05-20 23:13:02
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-20 23:24:19
 */

/*
  令dp[i][j]表示i只老虎j只鹿时人活下来的最大几率，那么有
dp[0][i]=1,0<=i<=1000（人杀掉所有鹿）
dp[1][0]=0（老虎吃掉人）
dp[i][j]=(C(i,2)*dp[i-2][j]+C(j,2)*dp[i][j]++i*j*dp[i][j-1]+i*0+j*dp[i][j])/C(i+j+1,2)
（第一项表示两只老虎相遇会死掉两只老虎，第二项表示两只鹿相遇什么都没发生，第三项表示一只老虎遇见一只鹿会死掉一只鹿，第四项表示人遇到老虎会死掉，第五项表示人遇见鹿不会杀掉鹿（这样可以减小人遇见老虎的几率））
解该方程即得到dp[i][j]
https://blog.csdn.net/v5zsq/article/details/69951882
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

double dp[1005][1005];

int main() {
  int t;
  int tt = 0;
  cin >> t;
  dp[1][0] = 0; // 老虎吃人，老虎互相也有可能吃的，所以只设了 1
  for (int i = 0; i <= 1000; i++) {
    dp[0][i] = 1;
  }
  int a = 0; //分母
  double b;  //分子
  for (int i = 1; i <= 1000; i++) {
    for (int j = 0; j <= 1000; j++) {
      a = (i + j + 1) * (i + j) / 2;
      b = 0;
      if (i >= 2)
        b += 1.0 * i * (i - 1) / 2 * dp[i - 2][j];
      if (j >= 2)
        a -= j * (j - 1) / 2;
      if (j > 0) {
        b += 1.0 * i * j * dp[i][j - 1]; // T-D
        a -= j;                          // D-P
      }
      dp[i][j] = b / a;
    }
  }

  while (t--) {
    double p;
    int n, m;
    cin >> n >> m;

    printf("Case %d: %.8f\n", ++tt, dp[n][m]);
  }
  return 0;
}
