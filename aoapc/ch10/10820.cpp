/*
 * @Author: yuuoniy 
 * @Date: 2019-05-06 23:30:18 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-06 23:30:50
 */
#include <iostream>
#include <cmath>

using namespace std;

const int MAX_N = 50005;
int phi[MAX_N]={0};
int phi_sum[MAX_N];

void phi_table(int n){
  phi[1] = 0;
  for(int i = 2; i <=n; i++)
  {
    if (!phi[i]) {
      for(int j = i; j <=n; j+=i)
      {
        if (!phi[j]) {
          phi[j] = j;
        }
        phi[j] = phi[j]/i*(i-1);
      }
    }
  }
}

int main(){
  int n;
  phi_table(MAX_N);
  for(int i = 1; i <=MAX_N; i++)
  {
    phi_sum[i] = phi_sum[i-1]+phi[i];
  }
  while(scanf("%d",&n)==1&&n){
    printf("%d\n",2*phi_sum[n]+1);
  }
  return 0;
}
