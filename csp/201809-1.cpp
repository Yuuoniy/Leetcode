	// 卖菜
#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n = 0,tmp = 0;
  cin >> n;
  vector<int> nums;
  for(int i = 0; i < n; i++)
  {
    cin >> tmp;
    nums.push_back(tmp);
  }
  int ava = 0;
  for(int i = 0; i < n; i++)
  {
    if(i==0){
      ava = (nums[i]+nums[i+1])/2;
    }else if(i==n-1){
      ava = (nums[i]+nums[i-1])/2;
    }else{
      ava = (nums[i-1]+nums[i]+nums[i+1])/3;
    }
    cout << ava;
    if(i!=n-1)
      cout << " ";
  }
  return 0;
  
}
