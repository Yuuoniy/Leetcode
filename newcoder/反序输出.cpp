
/*
 * @Author: yuuoniy 
 * @Date: 2019-06-16 00:55:18 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-16 00:57:14
 */


#include <iostream>
#include <string>

using namespace std;


int main(){
  string str;
  while (cin >> str)
  {
    for (int i = str.length()-1; i >=0; i--)
    {
      cout << str[i];
    }
    
    cout << endl;
  }
  return 0;
}
