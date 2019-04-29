// 归并排序求逆序对个数
// #include<bits/stdc++.h>
#include <stdio.h>


long long nums[500005];
long long tmp[500005];
long long cnt;


void merge(int l,int r){
  if(l==r) return;
  int mid = (l+r)>>1;
  merge(l,mid);
  merge(mid+1,r);
  int i=l,j=mid+1,k=l;
  while(j<=r||i<=mid){
  
    if(j>r||(i<=mid&&nums[i]<=nums[j]))
      tmp[k++] = nums[i++];
    else{
      tmp[k++] = nums[j++];
      cnt +=mid-i+1;
    }
  }

  for(int k = l; k <=r; k++)
  {
    nums[k] = tmp[k];
  }
}
int main(){
  int t;
  // fopen("a.in","r",stdin);
 scanf("%d",&t);
    cnt = 0;
    for(int i =1 ; i <= t; i++)
    {
      scanf("%lld",&nums[i]);
    }
    merge(1,t);
    printf("%lld\n",cnt);
  
  return 0;


}
