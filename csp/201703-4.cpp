

#include <algorithm>
#include <iostream>
using namespace std;
int n, m;

struct edge {
  int from, to, cost;
  bool operator<(const edge &t) const { return cost < t.cost; } //注意重载函数
} edges[200005];

int p[100005];
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

void unionEle(int x, int y) {
  int p1 = find(x), p2 = find(y);
  if (p1 == p2)
    return;
  p[p1] = p2;
}

int kruskal() {
  sort(edges, edges + m);
  for (int i = 0; i < m; i++) {
    if (find(edges[i].from) != find(edges[i].to))
      unionEle(edges[i].from, edges[i].to);
    if (find(1) == find(n))
      return edges[i].cost;
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }

  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &edges[i].from, &edges[i].to, &edges[i].cost);
  }
  printf("%d\n",kruskal());
  return 0;
}
