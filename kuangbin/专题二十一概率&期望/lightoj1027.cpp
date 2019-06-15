/*
 * @Author: yuuoniy 
 * @Date: 2019-05-20 12:55:52 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-20 15:09:16
 */
// 求期望
/*思路：设花费时间 出迷宫的期望为E。

每一个选择仅仅有两种情况——设当前门花费时间的绝对值为 T

一：选择的门能够直接把你传送出去。期望为1 / N * T。
二：选择的门把你传送到原来的位置，期望为1 / N * T。又回到初始状态，则出去的期望为1 / N * (T + E)。
*/
// 开始练习概率-期望 dp，要好好刷题！先参考别人的题解学习

/*设cnt为x为正的门数。则一次走出迷宫的概率为 cnt / n，走出迷宫的期望次数为 n / cnt
 走一次的平均时间为sum(abs[x[i]]) / n。则期望时间 ans = sum / n * n / cnt = sum / cnt。
*/
// 为什么走出迷宫的期望此时数 n/cnt 啊？？是几何分布，概率论的内容
// 所以我是不是应该先看下书。。


#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
  int t;
  scanf("%d",&t);
  int tt=0;
  while (t--)
  {
    
    int n;
    int cnt = 0,sum = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
      int tmp;
      scanf("%d",&tmp);
      if(tmp>0) ++cnt;
      sum+=abs(tmp);
    }
    printf("Case %d: ",++tt);
    if(!cnt) printf("inf\n");
    else printf("%d/%d\n",sum/__gcd(sum,cnt),cnt/__gcd(sum,cnt));
    
  }
  return 0;
  
}
