/*
 * @Author: yuuoniy 
 * @Date: 2019-06-18 15:29:48 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-18 15:43:51
 */

// 超时了，这都能超时？？


#include <iostream>
#include <cmath>


using namespace std;

int main(){
  int a,b,k;
  while (scanf("%d%d%d",&a,&b,&k)&&a!=0&&b!=0 )
  {
    // cout << (int)(pow(10.0,k)+0.5) << endl;
    if((a-b)%(int)(pow(double(10),k)+0.5)==0){
      printf("-1\n");
    }else 
      // cout << a+b << endl;
      printf("%d\n",a+b);
  }
  return 0;
  
}
