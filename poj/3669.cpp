// BFS
// 思路：对流星雨下落的时间排序，然后将地图的每个点的值设为该点最早被炸毁的时间

#include <queue>
#include <stdio.h>
#include <algorithm>  
#include <memory.h>
using namespace std; 
const int MAXN = 505;
int n = 0;
int last = 0;
int map[MAXN][MAXN];
bool visited[MAXN][MAXN];

struct node {
  int x, y, t;
};

node m[50005];
const int dir[5][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {0, 0},
};

int bfs() {
  //
  queue<node> q;
  node current; //记录当前的位置和时间
  current.x = 0;
  current.y = 0;
  current.t = 0;
  q.push(current);
  while (!q.empty()) {
    node p = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) //找到下一个可以移动的点
    {
      current = p;
      current.x = current.x + dir[i][0];
      current.y = current.y + dir[i][1];
      ++current.t;
      if (current.x >= 0 && current.y >= 0 && current.x < n && current.y < n &&
          map[current.x][current.y] > current.t &&
          !visited[current.x][current.y]) {
        visited[current.x][current.y] = true;
        if (map[current.x][current.y] > last) //此时是安全的
        {
          return current.t;
        }
        q.push(current);
      }
    }
  }

  return -1;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &m[i].x, &m[i].y, &m[i].t);
  }
  memset(map, 0X7f, sizeof(map));
  memset(visited, 0, sizeof(visited));
  //记录每个点被流星炸毁的最早时间
  for (int i = 0; i < n; i++) {
    last = max(last, m[i].t); //记录最晚流星落下的时间
    {
      for (int j = 0; j < 5; j++) {
        int nx = m[i].x + dir[j][0];
        int ny = m[i].y + dir[j][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] > m[i].t) {
          map[nx][ny] = m[i].t;
        }
      }
    }
  }
  if (map[0][0] == 0) //无解
    printf("-1\n");
  else {
    printf("%d", bfs());
  }
  return 0;
}
