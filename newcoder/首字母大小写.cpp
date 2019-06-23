/*
 * @Author: yuuoniy
 * @Date: 2019-06-18 16:31:30
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-18 16:33:34
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  getline(cin, s);
  for (int i = 0; i < s.length(); i++) {
    if (i == 0) {
      s[i] = toupper(s[i]);
    } else {
      if (s[i - 1] == ' ' || s[i - 1] == '\t' || s[i - 1] == '\r' ||
          s[i - 1] == '\n')
        s[i] = toupper(s[i]);
    }
  }
  cout << s;
  return 0;
}
