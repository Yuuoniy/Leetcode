
/*
 * @Author: yuuoniy 
 * @Date: 2019-05-16 15:37:04 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-16 15:42:07
 */

#include <iostream>
#include <map>


using namespace std;
map<int,int> m;
int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int t;
    cin >> t;
    cout << ++m[t] <<" ";
  }
  return 0;
}
