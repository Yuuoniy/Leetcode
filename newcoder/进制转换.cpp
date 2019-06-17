/*
 * @Author: yuuoniy
 * @Date: 2019-06-16 08:15:28
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-16 08:36:21
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  int num[31];
  int res[2000];
  
  while (cin >> str) {
    for (int i = 0; i < str.length(); i++) {
      num[i] = str[i]-'0';
    }
    // cout << str ;
    int idx = 0;
    for (int i = 0; i < str.length();)
    {
      int tmp,remain = 0;
      for (int j = i; j < str.length(); j++)
      {
        tmp = (10*remain+num[j])%2;
        // cout << num[j] << endl;
        num[j] = (10*remain+num[j])/2;
        remain = tmp;
      }
      res[idx] = remain;
      idx++;
      while (num[i]==0)
      {
        i++;
      }
      
    }
    for (int i = idx-1; i >=0; i--)
    {
      printf("%d",res[i]);
    }
    printf("\n");
    
  }
  return 0;
}
