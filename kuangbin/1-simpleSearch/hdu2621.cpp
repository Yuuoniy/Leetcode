/*
 * @Author: yuuoniy
 * @Date: 2019-06-14 00:43:09
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-14 01:30:07
 */
// bfs 但是有两个端点，怎么处理？其实搜索所有的情况就好了？ 嗯...
// 解：Y和M分别进行bfs，遍历到所有能够遍历到的KFC的位置，并分别记录Y和M到达某个KFC的时间。最后遍历所有的KFC，每遍历到一个KFC就计算一下Y和M到达此KFC所用的时间和，找出最小的时间和就是题目的解。
// https://blog.csdn.net/Biuasm/article/details/78993064
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 205;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char maze[MAX_N][MAX_N];
int tag[202][202], c[202][202];
int n, m;
struct node {
  int x, y, step;
};

bool isValid(int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] != '#');
}

void bfs(int x, int y) {
  node a, b;
  queue<node> q;
  a.x = x, a.y = y, a.step = 0;
  q.push(a);
  while (!q.empty()) {
    a = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      b.x = a.x + dir[i][0];
      b.y = a.y + dir[i][1];
      b.step = a.step + 1;
      if (!isValid(b.x, b.y))
        continue;
      if (tag[b.x][b.y])
        continue;
      tag[b.x][b.y] = 1;
      c[b.x][b.y] += b.step;
      q.push(b);
    }
  }
}

int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(maze,0,sizeof(maze));
    memset(c,0,sizeof(c));
    for (int i = 0; i < n; i++) {
      scanf("%s", maze[i]);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (maze[i][j] == 'Y' || maze[i][j] == 'M') {
          memset(tag, 0, sizeof(tag));
          bfs(i, j);
        }
      }
    }
    int step = 10000;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (maze[i][j] == '@' && c[i][j] < step && c[i][j] != 0) {
          step = c[i][j];
        }
      }
    }
    printf("%d\n", step * 11);
  }

  return 0;
}
