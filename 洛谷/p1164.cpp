/*
 * @Author: yuuoniy 
 * @Date: 2019-03-29 22:25:07 
 * @Last Modified by:   yuuoniy 
 * @Last Modified time: 2019-03-29 22:25:07 
 */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <stdio.h>
using namespace std;
using namespace std;
int countNum = 0;
int n, m;
int mem[105][1005];
int price[105];

void dp(int pos, int left) {
  if (left == 0) {
    ++countNum;
    return;
  }
  // mem[pos][left] = 1;
  if (pos == n) {
    return;
  }
  dp(pos + 1, left);
  if (left >= price[pos]) {
    dp(pos + 1, left - price[pos]);
  }
}

int main() {
  countNum = 0;
  scanf("%d %d", &n, &m);
  memset(mem, -1, sizeof(mem));
  for (int i = 0; i < n; i++) {
    scanf("%d", &price[i]);
  }
  dp(0, m);
  printf("%d", countNum);
  return 0;
}
