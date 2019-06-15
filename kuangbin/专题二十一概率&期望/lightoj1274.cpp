/*
 * @Author: yuuoniy 
 * @Date: 2019-05-21 07:33:01 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-21 11:20:34
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

/*
      期望 dp 或者直接使用组合数
      滚动数组 x=l-2n，y=3n-l
      一串连续的”Yes”和”No”组成了输出序列。我们需要猜出来答案，第一次一定是猜”Yes”，
      当猜对时，下一次会猜上一次猜过的答案；当猜错时会再猜另一个相反的答案。
      给出”Yes”和”No”的个数和序列的长度，问猜错的期望是多少次？
      http://crazyforsaken.com/?p=737
      https://blog.csdn.net/qinyibut/article/details/78470045
      dp[i][j][k]保存的是：当遍历到i这个位置，已经有j个字符1，要加入的字符为k(0, 1)的不匹配数
      该匹配是自身匹配，相当于前一个字符与后一个字符对比，如果是不同字符不能匹配数就+1 
*/
// 记得清空 dp 数组
double dp[2][5005][2];

int main(){
   int t;
  int tt = 0;
  cin >> t;
  while (t--)
  {
    int n,s;
      int a,b;
      cin >>  n >> s;
       a = s-2*n,b = n-a;
        memset (dp, 0, sizeof (dp));
      for (int i = n-1; i >=0; i--)
      {
        int maxm = min(i,a); int minm = max(i-b,0);
        for (int j = minm; j <=maxm; j++)
        {
          double lasty = 1.0*(a-j)/(n-i); 
          double lastn = 1.0*(b-(i-j))/(n-i);
          int now = i&1,nxt = 1-now;
          dp[now][j][1] = dp[nxt][j+1][1]*lasty+(dp[nxt][j][0]+1)*lastn;
          dp[now][j][0] = (dp[nxt][j+1][1]+1)*lasty+dp[nxt][j][0]*lastn;
          
        }
        
      }
      printf("Case %d: %.8f\n", ++tt, dp[0][0][1]);
  }
  return 0;
}
