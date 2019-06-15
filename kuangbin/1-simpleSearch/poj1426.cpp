/*
 * @Author: yuuoniy 
 * @Date: 2019-06-14 00:31:56 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-14 00:38:52
 */

// 广搜每一位是0还是1

#include <cstdio>

int k;

bool dfs(int cnt,long long sum){
  if(cnt>18) return false;
  if(sum%k==0){
    printf("%lld\n",sum);
    return true;
  }
  if(dfs(cnt+1,sum*10+1)) return true;
  if(dfs(cnt+1,sum*10)) return true;
}


int main(){
  while (scanf("%d",&k)!=EOF)
  {
    if(k==0) break;
    dfs(0,1);
  }
  return 0;
}
