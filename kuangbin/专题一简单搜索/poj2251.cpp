/*
 * @Author: yuuoniy
 * @Date: 2019-05-18 18:02:08
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-18 20:06:31
 */

//这道题是三维搜索。。之前没做过，重点想想要怎么扫描状态吧，使用bfs 吧
// 怎么 WA 了。。为什么会WA 啊还不知道样例 TAT 好迷啊！ z < l 而不是 < r . 变量写错了。。
// 刷这种题好难受，没有样例可以测，都不知道错哪，找错要好久

#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct point {
  int x;
  int y;
  int z;
  int step;
  point(int _x = 0, int _y = 0, int _z = 0, int _step = 0) {
    x = _x;
    y = _y;
    z = _z;
    step = _step;
  }
};

const int MAX_N = 35;

char m[MAX_N][MAX_N][MAX_N];
bool visited[MAX_N][MAX_N][MAX_N];
int l, r, c;
point start, endpoint; //标记起点和终点

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

//判断点是否在边界内
bool isValid(int x, int y, int z) {
  return (x >= 0 && x < r && y >= 0 && y < c && z >= 0 && z < l);
}

void bfs() {
  queue<point> q;
  visited[start.z][start.x][start.y] = 1;
  q.push(start);
  while (!q.empty()) {
    point t = q.front();
    q.pop();
    if (t.x == endpoint.x && t.y == endpoint.y && t.z == endpoint.z) {
      cout << "Escaped in " << t.step <<" minute(s)." << endl;
      return;
    }

    for (int i = 0; i < 6; i++) {
      int xx = t.x + dx[i];
      int yy = t.y + dy[i];
      int zz = t.z + dz[i];
      if (!isValid(xx, yy, zz))
        continue;
      if (!visited[zz][xx][yy]&&m[zz][xx][yy]!='#') {
        visited[zz][xx][yy] = 1;
        point vis(xx, yy, zz, t.step + 1);
        q.push(vis);
      }
    }
  }
  cout << "Trapped!" << endl;
  return;
}

void init() {
  for (int i = 0; i < MAX_N; i++) {
    for (int j = 0; j < MAX_N; j++) {
      for (int k = 0; k < MAX_N; k++) {
        visited[i][j][k] = 0;
      }
    }
  }
}

int main() {
  while (cin >> l >> r >> c && l != 0 && r != 0 && c != 0) {
     init();
     for (int i = 0; i < l; i++) {
      for (int j = 0; j < r; j++) {
        for (int k = 0; k < c; k++) {
          cin >> m[i][j][k];
          if (m[i][j][k] == 'S') {
            start = point(j, k, i);
          } else if (m[i][j][k] == 'E') {
            endpoint = point(j, k, i);
          }
        }
      }
    }

    bfs();
  }
  return 0;
}
