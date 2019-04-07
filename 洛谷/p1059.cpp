#include <iostream>
#include <map>
using namespace std;

map<int,int> nums;
int inputs[105];
int main(){
  int n;
  cin >> n;
  int count = 0;
  for(int i = 0; i < n; i++)
  {
    cin >> inputs[i];
    if(nums[inputs[i]]!=1){
      ++count;
      nums[inputs[i]] = 1;
    }
  }

cout << count << endl;
for(map<int,int>::iterator it = nums.begin(); it !=nums.end(); it++)
{
  if(it==nums.begin())
    cout <<  it->first;
else
  cout <<" " <<  it->first;
}

return 0;
  
}
