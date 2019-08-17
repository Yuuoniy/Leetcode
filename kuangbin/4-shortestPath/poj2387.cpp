/*
 * @Author: yuuoniy
 * @Date: 2019-05-19 08:55:28
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-07-10 23:18:13
 */
//最短路
// 用堆优化的 dis 吧
// 用邻接矩阵存储，要熟练
#include <iostream>
#include <queue>
#include <vector>

#define INF 0x3f3f3f3f;
using namespace std;

struct node {
  int to, value;
  node(int _to, int _value) {
    to = _to;
    value = _value;
  }
  bool operator<(const node &a) const {
    if (value == a.value)
      return to < a.to;
    else
      return value > a.value;
  }
};

const int MAX_N = 1005;
vector<node> v[MAX_N];
int d[MAX_N];
int t, n;

//最短路算法
void solve() {
  priority_queue<node> q;
  for (int i = 0; i <= n; i++) {
    d[i] = INF;
  }
  d[n] = 0;
  q.push(node(n, d[n]));
  while (!q.empty()) {
    node t = q.top();
    q.pop();
    for (int i = 0; i < v[t.to].size(); i++) {
      if (t.value + (v[t.to][i].value) < d[v[t.to][i].to]) {
        d[v[t.to][i].to] = t.value + v[t.to][i].value;

        q.push(node(v[t.to][i].to, d[v[t.to][i].to]));
      }
    }
  }
  cout << d[1] << endl;
  return;
}

int main() {
  cin >> t >> n;
  for (int i = 0; i < t; i++) {
    int x, y, value;
    cin >> x >> y >> value;
    v[x].push_back(node(y, value));
    v[y].push_back(node(x, value));
  }
  solve();
  return 0;
}
