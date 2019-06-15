/*
 * @Author: yuuoniy 
 * @Date: 2019-06-14 10:22:47 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-14 10:43:07
 */


// 注意是 unsigned 类型！！
#include <cstdio>
#include <iostream>

using namespace std;


int bit[33];
int main(){
  unsigned long long n;
  scanf("%ulld",&n);
  printf("%u",(n<<16)^(n>>16));
  return 0;
  
  
}
