#include <bits/stdc++.h>

using namespace std;
int n,m;
int nums[10005];
int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  while(m--){
    next_permutation(nums,nums+n);
  }
  for(int i = 0; i < n-1; i++)
  {
    cout << nums[i] << " ";
  }
  cout << nums[n-1];
  return 0;
}
