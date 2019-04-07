/*
 * @Author: yuuoniy 
 * @Date: 2019-04-07 17:21:45 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-04-07 17:27:13
 */
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

#define N 1000005 
int prime[N] ={0};
bool isNotPrime[N+1] = {0};


void setPrime(int n){
  long long i = 0,j = 0;
  prime[1] = 0;
  isNotPrime[1] = true;
  //标记素数
  for(i =2;i<=n;i++){ 
    if(isNotPrime[i]==false){
      prime[i] = prime[i-1]+1;
      for(j = i+i; j<=n;j+=i) //j+=i 是偶数
      {
        isNotPrime[j] = true;
      }
    }else{
      prime[i] = prime[i-1];
    }
  }
}


int cal(int left,int right){
  return prime[right]-prime[left-1]; //注意这里！！
}



int main(){
  int n,m;
  scanf("%d %d",&n,&m);
  int left,right;
  setPrime(N);
  for(int i = 0; i < n; i++)
  {
  scanf("%d %d",&left,&right);
   
    if(right>m||left<1){
      printf("Crossing the line\n");
      continue;
    }
    int count = cal(left,right);
    printf("%d\n",count);
  }
  return 0;
}
