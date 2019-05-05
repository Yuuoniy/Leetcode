/*
 * @Author: yuuoniy 
 * @Date: 2019-05-03 13:33:21 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-03 13:38:58
 */

#include <iostream>

using namespace std;
int n;
int nums[1005];
int flag[1005];
int main(){
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  int res = 0;
  for(int i = 1; i < n-1; i++)
  {
    if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]) 
      ++res;
    else if(nums[i]<nums[i-1]&&nums[i]<nums[i+1])
     ++res;

  }
  cout << res << endl;
  
  
}
