/*
 * @Author: yuuoniy
 * @Date: 2019-06-13 21:18:01
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-13 21:39:06
 */
// 模板题
#include <algorithm>
#include <cstdio>

using namespace std;

int n, m;
const int MAX_N = 105;
struct edge {
  int u, v, cost;
};

bool cmp(const edge e1, const edge e2) { return e1.cost < e2.cost; }
int dis[MAX_N][MAX_N];
edge E[MAX_N * MAX_N];
int par[MAX_N];
int tot ;
void init() {
  for (int i = 0; i < MAX_N; i++) {
    par[i] = i;
  }
}

int find(int x) {
  return par[x] = (par[x]==x?x:find(par[x]));
}

void merge(int x, int y) {
   x = find(x);
   y = find(y);
  if (x == y)
    return;
  par[y] = x;
}

int krusal() {
  int ans = 0;
  init();
  sort(E+1, E + tot+1, cmp);
  for (int i = 1; i <= tot; i++) {
    int u = E[i].u;
    int v = E[i].v;
    if (find(u) != find(v)) {
      ans += E[i].cost;
    }
    merge(u, v);
  }
  return ans;
}



int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &dis[i][j]);
    }
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    dis[x][y] = dis[y][x] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      edge e;
      e.u = i, e.v = j, e.cost = dis[i][j];
      E[++tot] = e;
    }
  }
  printf("%d", krusal());
  return 0;
}
