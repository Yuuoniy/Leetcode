/*
 * @Author: yuuoniy 
 * @Date: 2019-05-12 16:49:47 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-12 16:51:03
 */
#include <iostream>
#include <map>
using namespace std;
const int MAX_N = 1005;
map<int,int> m;

int n;
int main(){
  cin >> n;
  for (int i = 0; i <  n; i++)
  {
    int t;
    cin >> t;
    ++m[t];    
  }
  int times = -1;
  int num = 0;
  for (auto it = m.begin(); it !=m.end(); it++)
  {
    if((*it).second>times) {
      times = (*it).second;
      num = (*it).first;
    }
  }
  
  cout << num << endl;
  return 0;
  
}
