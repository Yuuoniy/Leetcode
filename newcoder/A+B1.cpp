/*
 * @Author: yuuoniy
 * @Date: 2019-06-18 12:32:20
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-18 12:37:36
 */

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  map<string, int> mp;

  mp["zero"] = 0;
  mp["one"] = 1;
  mp["two"] = 2;
  mp["three"] = 3;
  mp["four"] = 4;
  mp["five"] = 5;
  mp["six"] = 6;
  mp["seven"] = 7;
  mp["eight"] = 8;
  mp["nine"] = 9;

  string s;
  while (cin >> s) {
    int a1, a2 = 0;
    a1 = mp[s];
    bool flag = false;
    while (true) {
      string temp;
      cin >> temp;
      if (temp == "+") {
        flag = true;
      } else if (temp == "=") {
        break;
      } else {
        if (flag) {
          a2 = a2 * 10 + mp[temp];
        } else {
          a1 = a1 * 10 + mp[temp];
        }
      }
    }
    if (a1 == 0 && a2 == 0)
      break;
    else
      cout << a1 + a2 << endl;
  }
  return 0;
}
