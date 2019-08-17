#include <iostream>
#include <memory.h>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
const int MAX_N = 105;
#define INF 0X3F3F3F3F

int n, m;

struct node {
  int to;
  int v;
  node(int _to, int _v) {
    to = _to;
    v = _v;
  }
  bool operator<(const node &t) const { return v < t.v; }
};
vector<node> edge[MAX_N];

bool isVisited[MAX_N];
int dis[MAX_N];
void solve(int start) {
  memset(dis, INF, sizeof(dis));

  dis[start] = 0;
  isVisited[start] = true;
  priority_queue<node> q;
  q.push(node(0, 0));
  while (!q.empty()) {
    node t = q.top();
    // isVisited[t.to] = true;
    q.pop();
    for (int i = 0; i < edge[t.to].size(); i++)
    {
      node tmp = edge[t.to][i];
      // if(isVisited[tmp.to])  continue;
      if(dis[tmp.to]>dis[t.to]+tmp.v){
        dis[tmp.to] = dis[t.to]+tmp.v;
        q.push(node(tmp.to,dis[t.to]+tmp.v));
      }
    }
    
  }
  return;
}

int main() {
  cin >> n >> m;
  int c =1;
  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;
    edge[from].push_back(node(to, c));
    edge[to].push_back(node(from, c));
    c *= 2;
  }
  solve(0);
  for (int i = 1; i < n; i++)
  {
    // if(isVisited[i]) cout << dis[i] << endl;
    // else cout << -1 << endl;
    if(dis[i]==INF) cout << -1 << endl;
    else cout << dis[i] << endl;
  }
  
  return 0;
}
