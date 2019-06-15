/*
 * @Author: yuuoniy 
 * @Date: 2019-05-16 15:44:03 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-16 16:05:57
 */

//数位 dp，第一次接触
// 主要是看别人的题解做的
// 首先要会分解状态
/*
0－－用了2，剩0，1，3
1－－用了0，2，剩1，3
2－－用了2，3，剩0，1
3－－用了0，1，2，剩3
4－－用了0，2，3，剩1
5－－全部用了
*/
// 仔细分析，只能以2开头
//  states[i][0]表示第i位状态为0的情况

#include <iostream>

using namespace std;
const long long mod = 1000000007;
long long dp[1005][6];
int main(){
  int n;
  cin >> n;
  for (int i = 1; i <=n; i++)
  {
    dp[i][0] = 1;
    dp[i][1] = (dp[i-1][0]+dp[i-1][1]*2)%mod;
    dp[i][2] = (dp[i-1][0]+dp[i-1][2])%mod;
    dp[i][3] = (dp[i-1][1]+dp[i-1][3]*2)%mod;
    dp[i][4] = (dp[i-1][1]+dp[i-1][2]+dp[i-1][4]*2)%mod;
    dp[i][5] = (dp[i-1][3]+dp[i-1][4]+dp[i-1][5]*2)%mod;
  }
  cout << dp[n][5] << endl;
  
  return 0;
}
