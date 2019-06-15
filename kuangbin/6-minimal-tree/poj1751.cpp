/*
 * @Author: yuuoniy
 * @Date: 2019-06-13 15:12:44
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-13 16:57:09
 */
/* 求最小的花费使得各点联通. 初始时有一些已建的边.
最后要输出增加的边的端点.*/
/*
思路：
最小生成树.
把已建的边的长度赋成零后跑一遍kruskal，同时把添加到的长度不为零的边输出.
 */
// http://willem.linshihan.cn/302.html

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct edge {
  int u, v, cost;
};
bool cmp(const edge e1, const edge e2) { return e1.cost < e2.cost; }

const int MAX_N = 755;
int par[MAX_N];
edge E[MAX_N * MAX_N];
pair<int, int> location[MAX_N];

int n, m;
int cnt;
int dist[MAX_N][MAX_N];

void init() {
  for (int i = 0; i <= MAX_N; i++) {
    par[i] = i;
  }
}

int dis(int x, int y) {
  return (location[x].first - location[y].first) *
             (location[x].first - location[y].first) +
         (location[x].second - location[y].second) *
             (location[x].second - location[y].second);
}

int find(int x) { return par[x] = (par[x] == x ? x : find(par[x])); }

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return;
  par[y] = x;
}

void krusal() {
  sort(E + 1, E + cnt + 1, cmp);
  for (int i = 1; i <= cnt; i++) {
    int x = E[i].u;
    int y = E[i].v;
    if (find(x) != find(y) && E[i].cost != 0) {
      printf("%d %d\n", x, y);
    }
    merge(x, y);
  }
}

int main() {
  scanf("%d", &n);
  init();
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &location[i].first, &location[i].second);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      dist[i][j] = dis(i, j);
    }
  }
  scanf("%d", &m);
  int x, y;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    dist[x][y] = dist[y][x] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      edge e;
      e.u = i, e.v = j, e.cost = dist[i][j];
      E[++cnt] = e;
    }
  }
  krusal();
  return 0;
}
