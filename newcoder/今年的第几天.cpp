/*
 * @Author: yuuoniy 
 * @Date: 2019-06-16 13:35:40 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-16 13:41:06
 */


#include <iostream>

using namespace std;

int monthday[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool isleap(int y){
  return y%4==0&&y%100!=0||y%400==0;
}
int main(){
  int y,m,d;
  while (cin>>y>>m>>d)
  {
    if(isleap(y)){
      monthday[2] = 29;
    }else{
      monthday[2] = 28;
    }
    int tot = 0;
    for (int i = 1; i < m; i++)
    {
      tot+=monthday[i];
    }
    tot+=d;
    cout << tot << endl;
    
  }
  
}
