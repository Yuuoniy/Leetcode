/*
 * @Author: yuuoniy 
 * @Date: 2019-03-20 22:04:48 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-03-20 22:11:41
 */

// 小明上学

#include <iostream>

using namespace std;

int main(){
  int r = 0,y = 0,g = 0;
  cin >> r >> y >> g;
  int  n =0;
  cin >> n;
  int k,t;
  int sum = 0;
  for(int i = 0; i < n; i++)
  {
    cin >> k >> t;
    if(k==0)
      sum+=t;
    else if(k==1)
      sum+=t;
    else if(k==2)
      sum+=t+r;
    // else if(k==3)
  }
  cout << sum;
  return 0;
}
