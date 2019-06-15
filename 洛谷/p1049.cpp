/*
 * @Author: yuuoniy 
 * @Date: 2019-05-15 09:17:59 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-15 09:32:10
 */
//装箱问题 动态规划


#include <iostream>
#include <algorithm>
using namespace std;

int v,n;
int product[35];
int dp[35][20005];

int main(){
  cin >> v >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> product[i];
  }
  for (int i = 1; i <=n; i++)
  {
    for (int j = 1; j<=v; j++)
    {
      if(j<product[i]){
        dp[i][j] = dp[i-1][j];
      }else 
        dp[i][j] = max(dp[i-1][j],dp[i-1][j-product[i]]+product[i]);
    }
    
  }
  cout <<v-dp[n][v] << endl;
  
}
