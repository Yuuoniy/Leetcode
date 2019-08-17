/*
 * @Author: yuuoniy 
 * @Date: 2019-07-10 21:35:37 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-07-10 22:04:53
 */


#include <iostream>
#include <algorithm>


using namespace std;
const int MAX_T = 1005;
const int MAX_M = 105;
int t,m;

int dp[MAX_T];
int weight[MAX_T];
int value[MAX_T];
int main(){
  cin >> t >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> weight[i] >> value[i];
  }
  
  for (int i = 0; i < m; i++)
  {
    for (int j = t; j>=weight[i]; j--)
    {
      dp[j] = max(dp[j-weight[i]]+value[i],dp[j]);
    }
    
  }
  cout << dp[t] << endl;
  return 0;
}
