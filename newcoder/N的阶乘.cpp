/*
 * @Author: yuuoniy
 * @Date: 2019-06-16 08:03:23
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-16 16:02:13
 */

#include <cstring>
#include <iostream>

using namespace std;

const int max_bit = 3000;
int main() {
  int n;
  int d[3000];
  memset(d, 0, sizeof(d));
  d[0] = 1;
  int k = 0;
  int t = 0;
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) { // i 相乘
      k = 0; //表示进位
      for (int j = 0; j <= t; j++) { // 乘以结果的每一位
        int r = (d[j] * i + k) / 10;
        d[j] = (d[j] * i + k) % 10;
        k = r;
      }
      while (k != 0) {
        d[++t] = k % 10;
        k = k / 10;
      }
    }
      for (int i = t; i >= 0; i--) {
        printf("%d", d[i]);
      }
      printf("\n");
  }
  return 0;
}
