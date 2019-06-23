/*
 * @Author: yuuoniy
 * @Date: 2019-06-18 16:08:41
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-18 16:29:23
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int a, b;
  string str;

  while (cin >> a >> str >> b) {
    long tmp = 0;
    for (int i = 0; i < str.length(); i++) {
      if (str[i] <= 'f' && str[i] >= 'a') {
        tmp = (str[i] - 'a') + 10 + tmp * a;
      } else if (str[i] <= 'F' && str[i] >= 'A') {
        tmp = (str[i] - 'A') + 10 + tmp * a;
      } else {
        tmp = (str[i] - '0') + tmp * a;
      }
    }
    string str2;
    do {
      if (tmp % b >= 10) {
        str2 += tmp % b - 10 + 'A';
      } else {
        str2 += tmp % b + '0';
      }
      tmp /= b;
    } while (tmp);
    reverse(str2.begin(), str2.end());
    cout << str2 << endl;
  }
  return 0;
}
