/*
 * @Author: yuuoniy
 * @Date: 2019-06-18 10:06:24
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-18 10:45:58
 */

#include <iostream>

using namespace std;

int main() {
  unsigned short M, N;
  while (cin >> M >> N) {
    for (int i = 0; i < 16; i++) {
      if (M == N) {
        cout << "YES" << endl;
        break;
      } else if (i == 15) {
        cout << "NO" << endl;
      } else {

        M = M << 1 | (M >> 15 & 1);
      }
    }
  }
  return 0;
}
