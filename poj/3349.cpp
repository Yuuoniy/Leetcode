// HASH 函数
#include <stdio.h>
#include <iostream>
#include <memory.h>
using namespace std;
const int SIZE = 100010;
int n,tot,P = 99991,snow[SIZE][6],head[SIZE],nextt[SIZE];


int H(int *a){
  int sum = 0,mul=1;
  for(int i = 0; i < 6; i++)
  {
    sum = (sum+a[i])%P;
    mul = (long long)mul*a[i]%P;
  }
  return (sum+mul)%P;
}

bool equal(int *a,int *b){
  for(int i = 0; i < 6; i++)
  {
    for(int j = 0; j < 6; j++)
    {
      bool eq = 1;
      for(int k = 0; k < 6; k++)
      {
        if(a[(i+k)%6]!=b[(j+k)%6]) eq=0;
      }
      if(eq) return 1;
      eq = 1;
      for(int k = 0; k < 6; k++)
      {
        if(a[(i+k)%6]!=b[(j-k+6)%6]) eq=0;
      }
      if(eq) return 1;
    }
  }
  return 0;
}

bool insert(int* a){
  int val = H(a);
  for(int i = head[val]; i ;i= nextt[i])
  {
    if(equal(snow[i],a)) return 1;
  }
  ++tot;
  memcpy(snow[tot],a,6*sizeof(int));
  nextt[tot] = head[val];
  head[val] = tot;
  return 0;
}


int main(){
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    int a[7];
    for(int j = 0; j < 6; j++)
    {
      scanf("%d",&a[j]);
    }
    if(insert(a)){
      cout << "Twin snowflakes found." << endl;
      return 0;
    }
    
  }
      cout << "No two snowflakes are alike." << endl;
  return 0;
}
