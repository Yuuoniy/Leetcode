/*
 * @Author: yuuoniy 
 * @Date: 2019-03-20 22:14:22 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-03-20 22:41:21
 */

// 思路：对于每个红绿灯，根据当时的时刻计算到达该处的情况
// 逆向，多少秒切换到下一个灯 转换为-> 这一周期过了多久
// 注意溢出！要用 Long long
#include <iostream>
#include <vector>

using namespace std;
int main(){
  int r,y,g;
  cin >> r >> y >> g;
  int n;
  cin >> n;
  vector<int> nums;
  long long sum = 0;
  int k,t;
  long long circle = r+y+g;
  for(int i = 0; i < n; i++)
  {
    cin >> k >> t;
    int left = 0;
    int tmp = 0;// 表示这一周期已经过了多少时间，以绿灯开始的
    if(k==0){
      sum += t;
      continue;
    }
    else if(k==1){ // red
      tmp = circle-t;
    }
    else if(k==2){
      tmp = g+y-t;
    }
    else if(k==3){
      tmp= g-t;
    }
    tmp = (sum+tmp)%circle;
    if(tmp>g) //说明还需要等待
      sum+=(circle-tmp);
  }
  cout << sum;
  
}
