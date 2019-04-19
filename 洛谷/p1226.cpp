/*
 * @Author: yuuoniy 
 * @Date: 2019-04-19 08:52:44 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-04-19 09:06:20
 */

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
  long long b,p,k;
  long long ans = 1;
  scanf("%lld%lld%lld",&b,&p,&k);
  long long tmp_b = b;
  long long tmp_p = p;
  // cout << "finish reading " << endl;
  if(p==0) ans = 1%k;
  while(p>0){
    if(p&1){
      ans*= b;
      ans%=k;
    }
    b *=b;
    b %= k;
    p >>= 1;
  }
  printf("%lld^%lld mod %lld=%lld",tmp_b,tmp_p,k,ans);
  return 0;
}
