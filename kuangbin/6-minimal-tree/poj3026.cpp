/*
 * @Author: yuuoniy
 * @Date: 2019-06-13 17:25:31
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-13 20:54:26
 */
// https://www.cnblogs.com/kuangbin/p/3147031.html
// https://blog.csdn.net/SDUTyangkun/article/details/52100380

//连接所的字母（S和A），使其连通，求最小生成树的权值之和
// 1. bfs
// 枚举每一个结点进行一遍BFS，求该结点到其他所有结点的距离，若距离小于初始值，则更新该距离。这样最终得到的就是每两个结点之间的最短距离。
// 套用最小生成树
//读入有坑，用 gets

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

int T;
char ma[55][55];
int a[55][55];
int dis[55][55];
int cost[105][105];
int mov[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs(int sx, int sy) {
  queue<pair<int, int> > q;
  memset(dis, -1, sizeof(dis));
  dis[sx][sy] = 0;
  q.push(make_pair(sx, sy));
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    if (a[cur.first][cur.second] != -1)
      cost[a[sx][sy]][a[cur.first][cur.second]] = dis[cur.first][cur.second];
    for (int i = 0; i < 4; i++) {
      int tx = cur.first + mov[i][0];
      int ty = cur.second + mov[i][1];
      if (ma[tx][ty] == '#' || dis[tx][ty] != -1)
        continue;
      dis[tx][ty] = dis[cur.first][cur.second] + 1;
      q.push(make_pair(tx, ty));
    }
  }
}

bool vis[105];
int lowc[105];
const int INF = 0x3f3f3f3f;

int prim(int n) {
  int ans = 0;
  memset(vis, false, sizeof(vis));
  vis[0] = true;
  for (int i = 1; i < n; i++) {
    lowc[i] = cost[0][i];
  }
  for (int i = 1; i < n; i++) {
    int minc = INF;
    int p = -1;
    for (int j = 0; j < n; j++) {
      if (!vis[j] && minc > lowc[j]) {
        minc = lowc[j];
        p = j;
      }
    }
    if (minc == INF)
      return -1;
    ans += minc;
    vis[p] = true;
    for (int j = 0; j < n; j++) {
      if (!vis[j] && lowc[j] > cost[p][j]) {
        lowc[j] = cost[p][j];
      }
    }
  }
  return ans;
}
int x, y;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &x, &y);
    int tot = 0;
    memset(a, -1, sizeof(a));
    gets(ma[0]);
    for (int i = 0; i < y; i++) {
      gets(ma[i]);

      for (int j = 0; j < x; j++) {
        if (ma[i][j] == 'A' || ma[i][j] == 'S')
          a[i][j] = tot++;
      }
    }

    for (int i = 0; i < y; i++) {
      for (int j = 0; j < x; j++) {
        if (a[i][j] != -1) {
          bfs(i, j);
        }
      }
    }
    printf("%d\n", prim(tot));
  }
}
