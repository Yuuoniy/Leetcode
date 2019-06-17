/*
 * @Author: yuuoniy
 * @Date: 2019-06-16 08:49:55
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-16 09:06:17
 */

#include <iostream>
#include <string>
using namespace std;

int conversion(int d[], int data[], int n, int x, int y) {
  int size = 0;
  for (int i = 0; i < n;) {
    int k = 0; // 余数
    for (int j = i; j < n; j++) {
      int t = (d[j] + k * x) % y;
      d[j] = (d[j] + k * x) / y;
      k = t;
    }
    data[size++] = k;
    while (d[i] == 0) {
      i++;
    }
  }
  return size;
}

const int MAX_N = 4005;
int main() {
  string s;
  int d[4005], data[4005];
  while (cin >> s) {
    for (int i = 0; i < s.length(); i++) {
      d[i] = s[i] - '0';
    }
    int n = conversion(d, data, s.length(), 10, 2);
    int start = 0;
    while (data[start] == 0) {
      ++start;
    }
    for (int i = start; i < n; i++) {
      data[i - start] = data[i];
    }
    n = conversion(data, d, n - start, 2, 10);
    for (int i = n - 1; i >= 0; i--) {
      cout << d[i];
    }
    cout << endl;
  }
  return 0;
}
