#include <bits/stdc++.h>

using namespace std;

int nums[30005] = {0};
int w,n;

int main(){
  scanf("%d%d",&w,&n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d",&nums[i]);
  }
  sort(nums,nums+n);
  int l = 0,r = n-1;
  int ans = 0;
  while(l<=r){
    if(nums[l]+nums[r]<=w)
    {
      ++l;
      --r;
      ++ans;
    }else{
      --r;
      ++ans;
    }
  }
  printf("%d",ans);
  return 0;
  
  
}
