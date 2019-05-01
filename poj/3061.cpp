// 尺取法
#include <stdio.h>
#include <algorithm>
using namespace std;
int T;
int n,S;
int nums[10005];


void solve(){
  int s = 0,t = 0,sum = 0;
  int res = n+1;
  for(;;)
  {
    while(t<n&&sum<S){
      sum+=nums[t++];
    }
    if(sum<S) break;
    res = min(res,t-s);
    sum-=nums[s++];
  }
  if(res>n){
    res = 0;
  }
  printf("%d\n",res);
  
}
int main(){
  scanf("%d",&T);
  for(int i=0;i<T;i++){
    scanf("%d %d",&n,&S);
    for(int j=0;j<n;j++){
      scanf("%d",&nums[j]);
    }
    solve();
  }
  return 0;
}
