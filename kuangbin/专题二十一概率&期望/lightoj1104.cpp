/*
 * @Author: yuuoniy 
 * @Date: 2019-05-20 20:18:51 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-20 20:36:03
 */
/* 生日悖论
所有人中至少有两个人的生日是同一天的概率就等于1减去所有人的生日都不是同一天的概率
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
    double p = 1;//第一个人可以任意选，第二个人在 n-1 里面选，以此递推
    // 找到所有人都不在同一天生日的概率，只要这个概率小于等于0.5 就跳出去。
    int i;
    for ( i = 1; i <n; i++)
    {
      p = p*(n-i)/n;
      if(p<=0.5){
        break;
      }
    }
    printf("Case %d: %d\n",++tt,i);
      
    
  }
  return 0;
}
