// 动态规划
// 设置好状态 和 状态转移方程
// 设置好边界状态，每次有三种选择
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


const int table[5][5]={
  {5,-1,-2,-1,-3},
  {-1,5,-3,-2,-4},
  {-2,-3,5,-2,-2},
  {-1,-2,-2,5,-1},
  {-3,-4,-2,-1,0}
};
const int MAX_N =105;
int dp[MAX_N][MAX_N];
int a[MAX_N];
int b[MAX_N];

map<char,int> m{{'A',0},{'C',1},{'G',2},{'T',3}};
int main(){
  int n1,n2;
  string str1,str2;
  cin >> n1;
  cin >> str1;
  cin >> n2 >> str2;
  //初始化数组
  for (int i = 1; i <= n1; i++)
  {
    for (int j = 1; j <= n2; j++)
    {
      dp[i][j]=-2e8;
    }
    
  }
  for (int i = 1; i <=n1; i++)
  {
    a[i]=m[str1[i-1]];
  }
  
  
  for (int i = 1; i <=n2; i++)
  {
    b[i]=m[str2[i-1]];
  }
  for (int i = 1; i <=n1; i++)
  {
    dp[i][0] = dp[i-1][0]+table[a[i]][4];
  }
  for (int i = 1; i <=n2; i++)
  {
    dp[0][i] = dp[0][i-1]+table[b[i]][4];
  }
  for (int i = 1; i <=n1; i++)
  {
    for (int j = 1; j <=n2; j++)
    {
      dp[i][j] = max(dp[i][j],max(dp[i][j-1]+table[b[j]][4],dp[i-1][j]+table[a[i]][4]));
      dp[i][j]=max(dp[i][j],dp[i-1][j-1]+table[a[i]][b[j]]);
    }
  }
  cout<< dp[n1][n2] << endl;
  
  return 0;
}
