/*
 * @Author: yuuoniy 
 * @Date: 2019-06-13 21:50:45 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-13 22:06:35
 */
//写得好丑...

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, m;
const int MAX_N = 105;
const int INF = 0x3f3f3f3f;
struct edge {
  int u, v, cost;
};

bool cmp(const edge e1, const edge e2) { return e1.cost < e2.cost; }
int dis[MAX_N][MAX_N];
edge E[MAX_N * MAX_N];
int par[MAX_N];
int tot;

void init(int n) {
  for (int i = 1; i <= n; i++) {
    par[i] = i;
  }
}

int find(int x) { return par[x] = (par[x] == x ? x : find(par[x])); }

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return;
  par[y] = x;
}

int krusal() {
  int ans = 0;
  sort(E + 1, E + tot + 1, cmp);
  for (int i = 1; i <= m; i++) {
    int u = E[i].u;
    int v = E[i].v;
    if (find(u) != find(v)) {
      ans += E[i].cost;
      merge(u, v);
    }
  }
  return ans;
}

int main() {
  while (scanf("%d %d", &n, &m)==2 && n != 0) {
    init(n);
    tot = 0;
    memset(dis, INF, sizeof(dis));
    for (int i = 0; i < m; i++) {
      int u, v, cost;
      scanf("%d %d %d", &u, &v, &cost);
      if(u>v) dis[v][u] = min(dis[v][u], cost);
      else dis[u][v] = min(dis[u][v], cost);
    }

    for (int i = 1; i <= n; i++) {
      for (int j = i+1; j <= n; j++) {
        edge e;
        e.u = i;
        e.v = j;
        e.cost = dis[i][j];
        E[++tot] = e;
      }
    }
    printf("%d\n", krusal());
  }
  return 0;
}
