/*
 * @Author: yuuoniy
 * @Date: 2019-06-16 13:44:06
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-16 15:07:49
 */

// 简单动态规划

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAX_N = 1000005;
int num[MAX_N];
int dp[MAX_N];

int main() {
  int n;
  while (cin >> n) {
    for (int i = 1; i <= n; i++) {
      cin >> num[i];
    }
    memset(dp,0,sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
      if(dp[i-1]<0) dp[i] = num[i];
      else dp[i] = dp[i-1]+num[i];
    }
    cout << *max_element(dp+1,dp+n+1) << endl;
  }
}
