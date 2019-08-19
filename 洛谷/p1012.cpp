/*
 * @Author: yuuoniy 
 * @Date: 2019-08-17 22:10:50 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-08-17 22:17:49
 */

#include <string>
#include <iostream>

using namespace std;

string nums[30];

int main(){
  int n;
  cin >> n;
  for (int i = 1; i <=n; i++)
  {
    cin >> nums[i];
  }
  for (int i = 1; i <=n; i++)
  {
    for (int j = i+1; j <=n; j++)
    {
      if(nums[j]+nums[i]>nums[i]+nums[j]){
        swap(nums[j],nums[i]);
      }
    }
    
  }

  for(int i=1;i<=n;i++){
    cout << nums[i];
  }
  return 0;
  


}
