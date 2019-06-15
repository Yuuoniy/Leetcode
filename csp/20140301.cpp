/*
 * @Author: yuuoniy 
 * @Date: 2019-05-16 15:31:27 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-16 15:35:57
 */

#include <iostream>

using namespace std;

const int MAX_N = 1005;
int a[MAX_N*2];
int n;
int main(){
  cin >> n;
  int t;
  int ans  = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> t;
    if(t<0){
      if(a[-t+1000])
        ++ans;
      else
        a[t+1000] = 1;
    }else if(t>0){
      if(a[-t+1000]) ++ans;
      else
        a[t+1000] = 1;
    }
  }
  cout << ans ;
  return 0;
}
