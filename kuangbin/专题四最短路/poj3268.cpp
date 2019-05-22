/*
 * @Author: yuuoniy
 * @Date: 2019-05-19 11:24:57
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-19 11:47:53
 */

//对每个 cow 求最小值，然后最后求最大值。每个 cow 的最小分为两部分
//他自己到目的地个目的地返回他自己。
// 感觉遍历有点麻烦
// 用两次
// dist,第一次是各个点到目的地，第二次是目的地到各个点，最后找加起来最大的值就好了
// 做完这道题真的不做了！！！TAT 要学习啊。。不要从刷题中寻求快感。。！

#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define INF 0x3f3f3f3f
using namespace std;

struct node {
  int to;
  int v;
  node(int _to, int _v) {
    to = _to;
    v = _v;
  }
  bool operator<(const node &a) const { return v > a.v; }
};

const int MAX_N = 1005;
int n, x, m;
int dis[MAX_N][MAX_N];
// int dis2[MAX_N];

vector<node> v[MAX_N];

void Dijkstra(int start) {
  dis[start][start] = 0;
  priority_queue<node> q;
  q.push(node(start, dis[start][start]));
  while (!q.empty()) {
    node tmp = q.top();
    q.pop();
    if (tmp.to == x && start != x)
      return;
    for (int i = 0; i < v[tmp.to].size(); i++) {
      node tmp_node = v[tmp.to][i];
      int update = tmp.v + tmp_node.v;
      if (dis[start][tmp_node.to] > update) {
        dis[start][tmp_node.to] = update;
        q.push(node(tmp_node.to, update));
      }
    }
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &x);
  for (int i = 0; i < m; i++) {
    int x, y, value;
    scanf("%d%d%d", &x, &y, &value);
    v[x].push_back(node(y, value));
  }
  memset(dis, INF, sizeof(dis));
  for (int i = 1; i <= n; i++) {
    Dijkstra(i);
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    res = max(res, dis[i][x] + dis[x][i]);
  }

  printf("%d\n", res);
  return 0;
}
