/*
 * @Author: yuuoniy
 * @Date: 2019-05-18 10:10:52
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-18 10:13:10
 */
// 重点在于怎么记录最短路径？
//需要记录结点的前驱结点，来形成路径。
// 特殊的，起始节点的前驱设置为其本身。

#include <iostream>
#include <map>
#include <queue>
#include <utility>

using namespace std;
typedef pair<int, int> point;
int m[5][5];

queue<point> q;
vector<point> v;
map<point, point> pre; //记录前驱结点
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> m[i][j];
    }
  }
  //bfs
  q.push(make_pair(0, 0));
  pre[make_pair(0, 0)] = make_pair(0, 0);
  while (!q.empty()) {
    point t = q.front();
    q.pop();
    if (t.first == 4 && t.second == 4)
      break;
    for (int i = 0; i < 4; i++) {
      int xx = t.first + dx[i];
      int yy = t.second + dy[i];
      if (xx < 0 || xx >= 5 || yy < 0 || yy >= 5)
        continue;
      if (m[xx][yy] == 0 && pre.find(make_pair(xx, yy)) == pre.end()) {
        q.push(make_pair(xx, yy));
        pre[make_pair(xx, yy)] = t;
      }
    }
  }
  //回溯前继结点，输出路径
  v.push_back(make_pair(4, 4));
  point h = make_pair(4, 4);
  while (true) {
    point anc = pre[h];
    v.push_back(anc);
    if (anc.first == 0 && anc.second == 0)
      break;
    h = anc;
  }
  for (int i = v.size() - 1; i >= 0; i--) {
    cout << "(" << v[i].first << ", " << v[i].second << ")" << endl;
  }
  return 0;
}
