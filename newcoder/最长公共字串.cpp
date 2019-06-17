
/*
 * @Author: yuuoniy 
 * @Date: 2019-06-16 10:16:32 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-16 10:31:26
 */


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int dp[1005][1005];

int main(){
  string a,b;
  cin >> a >> b;
  int ans = -1;
  for (int i = 0; i < a.length(); i++)
  {
    for (int j = 0; j < b.length(); j++)
    {
      if(a[i]==b[j]){
        dp[i+1][j+1] = dp[i][j]+1;
        ans = max(ans,dp[i+1][j+1]);
      }else{
        dp[i+1][j+1]= 0;
      }
    }
    
  }
  printf("%d",ans);
  return 0;
}
