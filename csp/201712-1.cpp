#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int nums[1005];
int main(){
  int n;
  int res  = 10000;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  for(int i = 0; i <= n; i++)
  {
    for(int j = i+1; j < n; j++)
    {
      res = min(res,abs(nums[i]-nums[j]));
    }
    
  }
  cout << res << endl;
  return 0;
  
  
}
