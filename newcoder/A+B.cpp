/*
 * @Author: yuuoniy
 * @Date: 2019-06-17 22:22:32
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-17 23:16:19
 */

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int process(string str) {
  int tmp = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == ',' || str[i] == '-') {
      continue;
    } else {
      tmp = tmp * 10 + (str[i] - '0');
    }
  }
  if (str[0] != '-')
    return tmp;
  else
    return -tmp;
}
int main() {
  int a, b;
  string str1, str2;
  while (cin >> str1 >> str2) {
    a = process(str1);
    b = process(str2);

    cout << a + b << endl;
  }
  return 0;
}
