/*
 * @Author: yuuoniy 
 * @Date: 2019-06-16 15:46:53 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-16 15:49:30
 */


#include <iostream>
#include <algorithm>
#include <cstring>


using namespace std;

const int MAX_N = 95;
int dp[MAX_N];
int n;

int main(){
  while (cin>>n)
  {
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <=n; i++)
    {
      dp[i] = dp[i-1]+dp[i-2];
    }
    cout << dp[n] << endl;
    
  }
  
}
