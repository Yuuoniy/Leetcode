/*
 * @Author: yuuoniy
 * @Date: 2019-06-14 14:52:34
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-14 15:50:03
 */

//注意 double
// 读题！！

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAX_N = 105;
struct edge {
  int u, v;
  double cost;
} E[MAX_N * MAX_N];

bool cmp(const edge e1, const edge e2) { return e1.cost < e2.cost; }

int par[MAX_N];

double dis[MAX_N][MAX_N];

void init(int n) {
  for (int i = 0; i < n; i++) {
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

int n;
int tot;
double ans;
double krusal() {
  int cnt = 0;
  sort(E, E + tot, cmp);
  for (int i = 0; i < tot; i++) {
    int x = E[i].u;
    int y = E[i].v;
    if (find(x) != find(y)) {
      ans += E[i].cost;
      merge(x, y);
      if (++cnt >= n - 1)
        return ans;
    }
  }
  return -1; //代表不能联通
}

pair<int, int> location[MAX_N];

double getDistance(int x, int y) {
  return sqrt((location[x].first - location[y].first) *
                  (location[x].first - location[y].first) +
              (location[x].second - location[y].second) *
                  (location[x].second - location[y].second));
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    ans = 0;
    tot = 0;
    init(n);
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &location[i].first, &location[i].second);
    }
    bool quit = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        edge e;
        e.u = i, e.v = j, e.cost = getDistance(i, j);
        if (e.cost > 1000 || e.cost < 10) {
          continue; //表示不能联通
        }
        E[tot++] = e;
      }
    }
    double res = krusal() * 100;
    if (res < 0)
      printf("oh!\n");
    else
      printf("%.1f\n", res);
  }
  return 0;
}
