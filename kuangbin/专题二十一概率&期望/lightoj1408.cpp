/*
 * @Author: yuuoniy 
 * @Date: 2019-05-23 12:44:02 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-23 13:13:33
 */

/*
https://blog.csdn.net/L123012013048/article/details/46448729
不进球概率为p，进概率 q=1-p。
设g[i]为已经投中了i颗，还需要投进m-i颗球的期望，设f[i]为投丢了i颗，还需要再投丢n－i颗球的期望
g[i] = (1-p) * (g[i+1] + 1) + p * (f[1] + 1),
g[i] = (1-p) * g[i+1] + f[1] + 1 
*/
// 等比数列，主要是推公式！
// 注意特殊情况，p 很小或者 p 很大！
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

double esp = 1e-9;

int main() {
  int t;
  int tt = 0;
  cin >> t;
  while (t--) {
    double p;
    int in,out;
   scanf("%lf%d%d",&p,&in,&out);
   if(p<esp){
     printf("Case %d: %d\n",++tt,in);
     continue;
   }else if(1.0-p<esp)
   {
     printf("Case %d: %d\n",++tt,out);
     continue;
   }
    double q = 1.0-p;
    double k1 = 1.0-pow(q,in-1);
    double k2 = 1.0-pow(p,out-1);
    k1 = k1/p;
    k2 = k2/q;
    double f = ((k1*k2*p)+k1)/(1.0-k1*k2*p*q);
    double g = k2*(q*f+1.0);
    double ans = q*f+p*g+1.0;
    printf("Case %d: %.7lf\n", ++tt, ans);
  }
  return 0;
}
