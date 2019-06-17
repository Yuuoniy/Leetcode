/*
 * @Author: yuuoniy 
 * @Date: 2019-06-16 07:45:16 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-16 07:47:26
 */

#include <string>
#include <iostream>
#include <algorithm>


using namespace std;

int main(){
  for (int i = 1000; i < 10000; i++)
  {
    string s = to_string(i);
    reverse(s.begin(),s.end());
    int j = stoi(s);
    if(i*9==j){
      cout << i << endl;
    }
  }
  return 0;
  
}
