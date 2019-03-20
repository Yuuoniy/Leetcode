
// 思路：生成回文数，然后判断是否是素数，对于素数，我们同样初始化素数,如果可以整除，说明这个数不是素数。
#include <stdio.h>
#include <math.h>
#define N 40000

bool isNotPrime[N+1] = {0};
int prime[N] = {0};
int pcount = 0;

void setPrime(int n){
  int i = 0,j = 0;
  prime[pcount++] = 2;
  //标记素数
  for(i =3;i<=n;i+=2){ //跳过偶数
    if(isNotPrime[i]==false){
      // printf("%d ",i);
      prime[pcount++] = i;
      for(j = i*i; j<=n;j+=2*i) //j+=i 是偶数
      {
        isNotPrime[j] = true;
      }
    }
  }
}

bool isPrime(int n,int prime[]){
  int i = 0, m = sqrt(n);
  while(prime[i]<=m){
    if(n%prime[i]==0)
      return false;
    i++;
  }
  return true;
}

int main(){
  int n = 0, i =0;
  int digits[10] = {1} ;//用于构造回文数
  int ans[6000],acount = 0;
  setPrime(N);
  scanf("%d",&n);
  digits[n - 1] = 1;
  if(n==1){
    digits[n-1]++;
  }
  // printf("finish");
  while(!digits[n]){
    int a = 0,b = n/2;
    for( i = 0; i < b; i++)
    {
      digits[i] = digits[n-i-1];
    }
    for( i = 0; i < n; i++)
    {
      a*=10;
      a+=digits[i];
    }
    // printf("%d ",a);
    if(isPrime(a,prime))
      ans[acount++] = a;
    digits[b]++;
    while(b<n){ //看一下有没有进位的情况 1000 01xxx
      if(digits[b]>9){
        digits[b+1]++;
        digits[b]-=10;
      }
      b++;
    }
  }
  printf("%d\n",acount);
  for(i  = 0; i < acount; i++)
  {
    printf("%d ",ans[i]);
  }
  printf("\n");
  return 0;
}



// 超时版本：
/*
#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <cmath>
using namespace std;

int isPrime(int n)
{
    int i;

    if(n % 2) {
        if(n == 1)
            return false;
        for(i=3; i*i<=n; i+=2) {
            if(n % i == 0)
                return false;
        }
    } else {
        return n == 2 ? true : false;
    }

    return true;
}
bool isCycle(int n){
  int a = n;
  int b = 0;
  while(a){
    b = b*10+a%10;
    a/=10;
  }
  return b==n;
}
int nums[1000005];
int main(){
  int n = 1;
  scanf("%d",&n);
  int count = 0;
  for(int i=pow(10,n-1);i<pow(10,n);i++){
    if(isCycle(i)&&isPrime(i)){
      nums[count++] = i;
      
    }
  }
  printf("%d\n",count);
  for(int i = 0; i < count-1; i++)
  {
    // cout << nums[i] << " ";
    printf("%d ",nums[i]);
  }
  printf("%d",nums[count-1]);
}
*/
//
