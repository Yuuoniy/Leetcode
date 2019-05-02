#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int nums[1005];

int main(){
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  sort(nums,nums+n);
  int mid = nums[n/2];
  int small = 0, large = 0;
  for(int i = 0; i < n; i++)
  {
    if(nums[i]<mid) small++;
    else if(nums[i]>mid) large++;
  }
  if(small==large) cout << mid << endl;
  else cout << "-1" << endl;
  return 0;
  
}
