/*
 * @Author: yuuoniy 
 * @Date: 2019-05-15 09:37:38 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-15 10:17:35
 */

//方格取数
// 只需输出一个整数，表示22条路径上取得的最大的和。
// 四位动态规划，因为 N 比较小，所以可以直接用四维，但其实可以优化的地方很多
#include<iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 10;
int m[MAX_N][MAX_N];
int dp[MAX_N][MAX_N][MAX_N][MAX_N];
int main(){
  int n;
  cin >> n;
    int x,y,v;
  while(cin >> x >> y >> v&&x!=0&&y!=0&&v!=0){
    // cin >> x >> y >> v;
    m[x][y] = v;
  }
  for (int i = 1; i <=n; i++)
  {
    for (int j = 1; j <=n; j++)
    {
      for (int k = 1; k <=n; k++)
      {
        for (int l = 1; l <=n; l++)
        {
          dp[i][j][k][l] = max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1]))+m[i][j]+m[k][l];
          if(i==k&&j==l) dp[i][j][k][l]-=m[i][j];
        }
        
      }
      
    }
    
  }
  cout << dp[n][n][n][n] << endl;
  return 0;
}
