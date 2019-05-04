#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX_N = 1005;
int nums[MAX_N];
int n,r;


void solve(){
  sort(nums,nums+n);
  int i = 0, ans = 0;
  while(i<n){
    int s= nums[i++];
    while(i<n&&nums[i]<=s+r){
      i++;
    }
    int p = nums[i-1];
    while(i<n&&nums[i]<=p+r){
      i++;
    }
    ans++;
    
    
  }
  printf("%d\n",ans);
  
}
int main(){
  while(scanf("%d %d",&r,&n)&&r!=-1&&n!=-1){
    for(int i = 0; i < n; i++)
    {
      scanf("%d",&nums[i]);
    }
    solve();
  }
  return 0;

}
