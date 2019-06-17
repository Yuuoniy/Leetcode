/*
 * @Author: yuuoniy 
 * @Date: 2019-06-16 00:15:58 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-16 00:27:03
 */
// 完全背包求解

#include <iostream>
#include <cstring>
using namespace std;

int n,dp[1000005],a[21];

int main(){
  int i,j,t;
  for (int i = 1; i <=20; i++)
  {
    a[i] = (1<<(i-1));
  }
  dp[0] = 1;
  while (cin>>n)
  {
    memset(dp+1,0,sizeof(dp));
    for (int i = 1; i <=20; i++) 
    {
      for (int j = a[i]; j<= n; j++)
      {
        dp[j]+=dp[j-a[i]]; // 关键
        dp[j] %=1000000000;
      }
    }
    cout << dp[n] << endl;
    
  }
  return 0;
  
}
