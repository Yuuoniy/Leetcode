/*
 * @Author: yuuoniy 
 * @Date: 2019-04-11 02:23:01 
 * @Last Modified by:   yuuoniy 
 * @Last Modified time: 2019-04-11 02:23:01 
 */
#include <iostream>
#include <algorithm>
using namespace std;

int num[1005];
bool cmp(int a,int b){
  return a<b;
}
int main(){
  int n,k;
  cin >> n >> k;
  for(int i = 0; i < n; i++)
  {
    cin >> num[i] ;
  }
  
  sort(num,num+n,cmp);
  int count = 0;
  int cur = 0;
  for(int i = 0; i < n; i++)
  {
    // cout << num[i] <<  endl;
    if(cur<k){
      cur += num[i];
    }else{
      // cout << "yes" << endl;
      ++count;
      cur = 0;
      --i;
    }
  }
  if(cur!=0) ++count;
  cout << count ;
  return 0; 
  
}
