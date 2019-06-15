/*
 * @Author: yuuoniy
 * @Date: 2019-06-15 19:46:00
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-15 20:00:25
 */

// http://www.hankcs.com/program/cpp/poj-3616-milking-time.html

/*
关键在于 dp[i] 表示什么
定义dp[i]表示第i个时间段挤奶能够得到的最大值，拆开来说，就是前面 i –
1个时间段任取0到i –
1个时间段挤奶，然后加上这个时间段（i）的产奶量之和。dp[i]满足如下递推关系：

第i个时间段挤奶的最大值 = 前 i – 1 个时间段挤奶最大值中的最大值 + 第i次产奶量。
 */


#include <iostream>
#include <algorithm>

using namespace std;

struct Interval
{
  int startTime,endTime,effci;
  bool operator<(const Interval & i) const{
    return startTime < i.startTime;
  }
}interval[1024];

int dp[1024];

int main(){
  int n,m,r;
  cin >> n >> m >> r;
  for (int i = 0; i < m; i++)
  {
    cin >> interval[i].startTime >> interval[i].endTime >> interval[i].effci;
    interval[i].endTime+=r;
  }
  sort(interval,interval+m);
  for (int i = 0; i < m; i++)
  {
    dp[i] = interval[i].effci;
    for (int j = 0; j < i; j++)
    {
      if(interval[j].endTime<=interval[i].startTime){
        dp[i] = max(dp[i],dp[j]+interval[i].effci);
      }
    }
    
  }
  cout << *max_element(dp,dp+m) << endl;
  return 0;
}



