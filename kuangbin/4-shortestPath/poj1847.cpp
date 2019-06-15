/*
 * @Author: yuuoniy
 * @Date: 2019-05-19 12:53:06
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-19 13:21:07
 */

// 一开始不知道怎么转化题意，要怎么求最小呢
//一个 intersection 不会经过两次的，不然的话直接取第二次的情况就好了
// 做完这道题就不做了！
// 分清楚 to 和 v 啊。。

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

const int MAX_N = 105;
int n, a, b;
vector<node> v[MAX_N];
int dis[MAX_N];

void Dijkstra(int start) {
  //首先起点
  memset(dis, INF, sizeof((dis)));
  dis[start] = 0;
  priority_queue<node> q;
  q.push(node(start, dis[start]));
  while (!q.empty()) {
    node tmp = q.top();
    q.pop();
    if (tmp.to == b) {
      cout << tmp.v << endl;
      return;
    }
    for (int i = 0; i < v[tmp.to].size(); i++) {
      node nod = v[tmp.to][i];
      int update = tmp.v + ((i == 0) ? 0 : 1);
      if (update < dis[nod.to]) {
        dis[nod.to] = update;
        q.push(node(nod.to, update));
      }
    }
  }
  cout << "-1" << endl;
}

int main() {
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    int count;
    cin >> count;
    for (int j = 0; j < count; j++) {
      int inter;
      cin >> inter;
      int value = (j == 0) ? 0 : 1;
      v[i].push_back(
          node(inter, value)); //该 intersection 可以到达的其他 intersectin
    }
  }
  Dijkstra(a);
  return 0;
}
