/*
 * @Author: yuuoniy
 * @Date: 2019-06-18 10:52:05
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-18 11:00:03
 */

#include <iostream>

using namespace std;

int main() {
  int n;
  while (cin >> n && n != 0) {
    int s = 0;
    while (n != 1) {
      if (n & 1)
        n = (3 * n + 1) / 2;
      else
        n = n / 2;
      s++;
    }
    printf("%d\n", s);
  }
}
