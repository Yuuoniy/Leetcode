#include <memory.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
int mem[30][30005];
int price[30], priority[30];
int n, m;

int dp(int pos, int left) {
  if (mem[pos][left] != -1)
    return mem[pos][left];
  if (pos == m)
    return mem[pos][left] = 0;
  if (left >= price[pos])
    return mem[pos][left] =
               max(dp(pos + 1, left),
                   (dp(pos + 1, left - price[pos]) + price[pos] * priority[pos]));
  else
    return mem[pos][left] = dp(pos + 1, left);
}

int main() {
  scanf("%d %d", &n, &m);
  memset(mem,-1,sizeof(mem));
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &price[i], &priority[i]);
  }
  printf("%d\n", dp(0, n));
  return 0;
}
