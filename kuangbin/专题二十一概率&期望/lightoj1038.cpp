/*
 * @Author: yuuoniy 
 * @Date: 2019-05-20 15:42:10 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-20 17:26:59
 */
// 好难 不太会 http://blog.leanote.com/post/sunshiness/60c93cea0288
/*　设一个数的约数有M个，E[n] = (E[a[1]]+1)/M+(E[a[2]]+1)/M+...+(E[a[M]]+1)/M
E[n] = (E[a[1]]+1)/M+(E[a[2]]+1)/M+...+(n+1)/M
(M-1)*E[n]=E[a[1]]+E[a[2]]+...+E[a[M-1]]+M
*/

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;


const int MAX_N = 100005;
double dp[MAX_N];

int main(){
  int t;
  int tt = 0;
  cin >> t;
  dp[1] = 0;
  for (int i = 2; i < MAX_N; i++)
  {
    int num = 0;
    for (int j = 1; j <=sqrt(i); j++)
    {
      if(i%j==0){
        dp[i] += dp[j];
        ++num;
        if(i/j!=j) {
          dp[i] += dp[i/j];
          num++;
          }
      }
    }
    dp[i] = (dp[i]+num)/(num-1);
    
  }
  
  while (t--)
  {
    int n;
    cin >> n;
    printf("Case %d: %.8f\n",++tt,dp[n]);
  }
  return 0;
}
