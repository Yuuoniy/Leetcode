// DFS
// 注意边界条件，等号！

#include <stdio.h>

const int MAXN = 105;
const int MAXM = 105;
char field[MAXN][MAXM];
int n, m;

void dfs(int x, int y) {
  field[x][y] = '.';
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      int nx = x + dx;
      int ny = y + dy;
      // printf("nx is %d, ny is %d  field is %c\n",nx,ny,field[nx][ny]);
      if (0 <= nx && nx < n && 0 <= ny && ny < m && field[nx][ny] == 'W') {
        dfs(nx, ny);
      }
    }
  }
  return;
}

void solve() {
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // printf("%c",field[i][j]);
      // printf("i is %d, j is %d  field is %c\n",i,j,field[i][j]);
      if (field[i][j] == 'W') {
        dfs(i, j);
        ++res;
      }
    }
  }
  printf("%d\n", res);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    // for (size_t j = 0; j < m; j++) {
      scanf("%s", field[i]);
    // }
  }
  solve();
  return 0;
}
