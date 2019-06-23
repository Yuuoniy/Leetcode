/*
 * @Author: yuuoniy
 * @Date: 2019-06-18 10:46:19
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-18 10:49:50
 */

// 巧妙使用 stl
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  string s;
  while (cin >> s) {

    map<string, int> m;
    for (int i = 0; i <= s.size(); i++) {
      for (int j = 0; j < i; j++) {
        m[s.substr(j, i - j)]++;
      }
    }

    for (auto it = m.begin(); it != m.end(); it++) {
      if (it->second > 1) {
        cout << it->first << " " << it->second << endl;
      }
    }
  }
  return 0;
}
