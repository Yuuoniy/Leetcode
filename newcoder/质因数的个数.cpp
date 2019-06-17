/*
 * @Author: yuuoniy 
 * @Date: 2019-06-15 23:52:56 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-15 23:55:10
 */



#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int m;
  while(cin>>m){
    int cnt = 0;
    for (int i = 2; i <=sqrt(m); i++)
    {
      while (m%i==0)
      {
        ++cnt;
        m/=i;
      }
      if(m<=1) break;
    }
    if(m>1) ++cnt;
    cout << cnt << endl;
    
  }
  return 0;
}

