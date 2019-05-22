/*
 * @Author: yuuoniy
 * @Date: 2019-05-19 10:10:42
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-19 11:10:38
 */

// 求权值的最大最小值,即所经过所有公路的载重量最小值
// 最大的一条路，相当于让选择的那条路最小值尽量大, 改写 dijkstra,修改松弛
// 注意初始值应该是 0 还是 INF ,起始节点是 1 不是 0
// 为什么会T啊啊啊啊 用 scanf 
// 为什么会WA啊啊啊啊 清空的时候没清完，是 <= n ！
 
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

struct node {
  int to, v;
  node(int _to, int _v) {
    to = _to;
    v = _v;
  }
  bool operator<(const node &a) const {
    return v < a.v;
  }
};

int n, m;
const int MAX_N = 1005;
int dis[MAX_N];
bool visited[MAX_N];
vector<node> v[MAX_N];
int t, tt;

void solve() {
  dis[1] = INF;
  priority_queue<node> q;
  q.push(node(1, dis[1]));
  while (!q.empty()) {
    node tmp = q.top();
    q.pop();
    if(tmp.to==n) break; //可以提前退出的！
    for (int i = 0; i < v[tmp.to].size(); i++) {
      node x_node = v[tmp.to][i];
      int update_value = min(tmp.v, x_node.v);
      if (update_value > dis[x_node.to]) {
        dis[x_node.to] = update_value;
        q.push(node(x_node.to, update_value));
      }
    }
  }
  printf("Scenario #%d:\n%d\n\n", tt, dis[n]);
  return;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    ++tt;
    scanf("%d%d",&n,&m);
    for (int i = 0; i <= n; i++) {
      v[i].clear();
      dis[i] = 0;
    }
    for (int i = 0; i < m; i++) {
      int x, y, z;
      scanf("%d%d%d",&x,&y,&z);
      v[x].push_back(node(y, z));
      v[y].push_back(node(x, z));
    }
    solve();
  }
}
