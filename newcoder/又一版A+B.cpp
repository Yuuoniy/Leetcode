/*
 * @Author: yuuoniy
 * @Date: 2019-06-17 20:34:20
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-17 21:05:01
 */

// 要用 unsigned 存储

#include <cstdio>
#include <iostream>

#define N 1000
using namespace std;

int convert(unsigned n, unsigned m, unsigned buf[N]) {
  int i;
  for (int i = 0; i < N; i++) {
    buf[i] = 0;
  }
  i = 0;
  while (n >= m) {
    buf[i] = n % m;
    n /= m;
    i++;
  }
  buf[i] = n;
  return i;
}

int main() {

  unsigned a, b;
  unsigned m, buf[N];
  int i, pos;
  while (scanf("%d", &m) != EOF) {
    if (m == 0)
      break;
    scanf("%d %d", &a, &b);
    pos = convert(a + b, m, buf);
    for (int i = pos; i >= 0; i--) {
      printf("%d", buf[i]);
    }
    printf("\n");
  }
  return 0;
}
