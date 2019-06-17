/*
 * @Author: yuuoniy
 * @Date: 2019-06-16 15:50:47
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-16 15:53:06
 */
// 我干嘛都在刷一些水题...
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
  while (cin >> str) {
    string tmp = str;
    reverse(str.begin(), str.end());
    printf("%s\n", tmp == str ? "Yes!" : "No!");
  }
  return 0;
}
