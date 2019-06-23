/*
 * @Author: yuuoniy
 * @Date: 2019-06-18 09:51:55
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-18 10:04:15
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
int len;
vector<string> res;
bool used[7];
void solve(string cur, int n) {
  if (n == len) {
    res.push_back(cur);
    return;
  }
  for (int i = 0; i < len; i++) {
    if (!used[i]) {
      used[i] = true;
      solve(cur + str[i], n + 1);
      used[i] = false;
    }
  }
}

int main() {
  while (cin >> str) {
    res.clear();
    len = str.length();
    solve("", 0);
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
      cout << res[i] << endl;
    }
    cout << endl;
  }

  return 0;
}
