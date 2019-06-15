/*
 * @Author: yuuoniy 
 * @Date: 2019-06-15 19:24:09 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-15 19:43:54
 */
// 应该算是很简单的动规，感觉我也只能做这种了 TAT

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


void output(int tot){
  int hour = 8,min = 0,sec = tot;
  min = sec/60;
  sec =sec%60;
  hour += (min/60);
  min%=60;
  int pm = hour/12;
  hour%=12;
  printf("%02d:%02d:%02d %s\n",hour,min,sec,pm?"pm":"am");
  return;
}


int n,k;
const int MAX_K = 2005;
int single[MAX_K];
int adj[MAX_K];
int dp[MAX_K];


int main(){
  scanf("%d",&n);
  while (n--)
  {
    scanf("%d",&k);
    for (int i = 1; i <= k; i++)
    {
      scanf("%d",&single[i]);
    }
    for (int i = 2; i <= k; i++)
    {
      scanf("%d",&adj[i]);
    }
    dp[0] = 0;
    dp[1] = single[1];
    for (int i = 2; i <= k; i++)
    {
       dp[i] = min(dp[i-1]+single[i],dp[i-2]+adj[i]);
    }
    output(dp[k]);
  }
    return 0;
  
}
