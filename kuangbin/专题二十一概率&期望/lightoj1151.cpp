/*
 * @Author: yuuoniy 
 * @Date: 2019-05-20 20:39:54 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-20 21:01:05
 */

/*
  期望DP+高斯消元
  如果i没有传送阵，则有：DP[i] = 1 / 6 * sum(DP[i + j]) + 1，1<= j <= 6，如果超出100则有：DP[i] = 1 / 6 * sum((DP[i + j]) + DP[i] * k)，k = min(100 - i，6)，1<= j < k
  有传送阵：DP[i] - DP[tp[i]] = 0
  然后根据上式解出这个100元1次方程，用高斯消元 
  主要是添加了传送阵，即添加关系 DP[i] - DP[tp[i]] = 0
  使用高斯消元求解
  http://www.cnblogs.com/DOLFAMINGO/p/8447350.html
  https://www.cnblogs.com/Yumesenya/p/6131505.html 
  https://www.bbsmax.com/A/MyJxMn0E5n/
  不想打高斯消元。。
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;


int main(){
   int t;
  int tt = 0;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      int a,b;
      cin >>  a >> b;
      
    }
    
      
    
  }
  return 0;
}
