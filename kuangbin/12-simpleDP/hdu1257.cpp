/*
 * @Author: yuuoniy 
 * @Date: 2019-07-10 23:50:00 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-07-11 00:26:54
 */

#include <iostream>
#include <algorithm>


using namespace std;
int dp[1005];
int height[10005];
int main(){
  int n;
  while(cin >> n){
  int res = -1;
  for (int i = 0; i < n; i++)
  {
    cin >> height[i]; 
  }
  dp[0] =1;
  for (int i = 1; i < n; i++)
  {
    dp[i] =1;
    for (int j = 0; j<i; j++)
    {
      if(height[j]<height[i])
      {
        dp[i] = max(dp[j]+1,dp[i]);

      }
    }
    res = max(res,dp[i]);
  }
 
  cout << res << endl;
  } 
}
