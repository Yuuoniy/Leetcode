/*
 * @Author: yuuoniy
 * @Date: 2019-06-16 15:42:10
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-16 15:46:19
 */

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool cmp(const string s1, const string s2) {
  return s1.size() < s2.size() || s1.size() == s2.size() && s1 < s2;
}

const int MAX_N = 105;
string strs[MAX_N];
int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> strs[i];
    }
    sort(strs, strs + n, cmp);
    for (int i = 0; i < n; i++) {
      cout << strs[i] << endl;
    }
  }

  return 0;
}
