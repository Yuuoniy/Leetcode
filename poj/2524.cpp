// 并查集

#include <stdio.h>
const int MAXN = 50005;
int par[MAXN];

//初始化 n 个元素
void init(int n) {
  for (int i = 0; i < n; i++) {
    par[i] = i;
  }
}

int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return;
  else
    par[x] = y;
}

int main() {
  int n, m;
  int count = 0;
  while (scanf("%d%d", &n, &m) != EOF) {
    if (n == 0 && m == 0)
      break;
    init(n);
    int x, y;
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &x, &y);
      unite(x, y);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (i == par[i])
        ++ans;
    }
    printf("Case %d: %d\n", ++count, ans);
  }
  return 0;
}
