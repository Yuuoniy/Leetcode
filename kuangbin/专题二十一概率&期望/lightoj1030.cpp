/*
 * @Author: yuuoniy 
 * @Date: 2019-05-20 15:15:37 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-20 15:42:28
 */
// 期望 dp
/*
题意：给定n个格子以及每个格子上的gold值，你从第一个格子出发，每次掷1-6的骰子，根据掷出的值前进。若当前位置 + 掷出的值 > n，则重新掷骰子，到达第n个格子游戏结束。问你获得gold值的期望。
*/
/*设dp[i]为到达i个格子获得gold值的期望，则有dp[i] = (dp[i+1]/6 + ... + dp[i+6]/6) + dp[i]     dp[n] = val[n]*/
// 但有可能+6 会超过n,那加到 n 就好了吧，注意 
// 想好状态转移方程 逆推就好了！
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int MAX_N = 105;
double dp[MAX_N];
int main(){
  int t;
  int tt = 0;
  cin >> t;
  while (t--)
  {
    memset(dp,0,sizeof(dp));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
      cin >> dp[i];
    }
    // dp[n] =num[n];
    for (int i = n-1; i >0; i--)
    {
     int range = min(6,n-i);
     for (int j = 1; j <= range; j++)
     {
       dp[i] += dp[i+j]/(double)range; 
     }
     
    }
    printf("Case %d: %.8f\n",++tt,dp[1]);
    
  }
  return 0;
  
}
