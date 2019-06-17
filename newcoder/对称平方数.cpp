/*
 * @Author: yuuoniy 
 * @Date: 2019-06-16 07:50:12 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-16 07:54:51
 */


#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
  for (int i = 0; i <= 256; i++)
  {
    int mul = i*i;
    string s = to_string(mul);
    bool flag = true;
    for (size_t j = 0; j< s.length()/2; j++)
    {
      if(s[j]!=s[s.length()-j-1]){
        flag = false;
        break;
      }
    }
    if(flag) cout << i << endl;
  }
  return 0;
}
