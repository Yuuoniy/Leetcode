#include <cstdio>

using namespace std;

const int MAX_N = 100005;
int par[MAX_N];
bool flag[MAX_N];
void init(int n) {
  for (int i = 0; i <= n; i++) {
    par[i] = i;
    flag[i] = false;
  }
}

int find(int n) { return par[n]=(par[n] == n ? n : find(par[n]));
}

void unite(int x, int y) {
  flag[x] = 1;
  flag[y] = 1;
  x = find(x);
  y = find(y);
  if (x == y)
    return;
  par[y] = x;
}

int main() {
  int x, y;
  bool ans = false;
  init(MAX_N);
  while (scanf("%d%d", &x, &y) && x != -1 && y != -1) {
    if (x == 0 && y == 0) {
      int last = -1;
      for (int i = 0; i <= MAX_N; i++) {
        if (!flag[i])
          continue;
        if (last == -1)
          last = find(i);
        if (last != find(i)) {
          ans = 1;
          break;
        }
      }
      if (ans)
        printf("No\n");
      else {
        printf("Yes\n");
      }
      ans = false;
      init(MAX_N);
      continue;
    }
    if (find(x) != find(y)) {
      unite(x, y);
    } else {
      ans = true;
    }
  }
  return 0;
}
