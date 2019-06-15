/*
 * @Author: yuuoniy
 * @Date: 2019-05-21 17:01:27
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-21 17:31:41
 */

/*
每次修好电脑后，将它可以通信的电脑(距离满足且已修好)与它进行连通。
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<int> nei[1005];
pair<int, int> loc[1005];
bool isGood[1005];
int par[1005];

void init(int n) {
  for (int i = 1; i <= n; i++) {
    par[i] = i;
  }
}

int find(int x) {
  if (par[x] == x)
    return x;
  else
    return par[x] = find(par[x]);
}

int dist(int x, int y) {
  return (loc[x].first - loc[y].first) * (loc[x].first - loc[y].first)+(loc[x].second - loc[y].second)*(loc[x].second - loc[y].second);
}
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  init(n);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    loc[i]=make_pair(x,y);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (dist(i, j) <= d * d) {
        nei[i].push_back(j);
        nei[j].push_back(i);
      }
    }
  }

  char op;
  while (~scanf("%c", &op)) {
    if (op == 'O') {
      int x;
      scanf("%d", &x);
      isGood[x] = 1;
      for (int i = 0; i < nei[x].size(); i++) {
        if (isGood[nei[x][i]]) {
          int b = find(nei[x][i]);
          par[b] = x;
        }
      }

    } else if (op == 'S') {
      int x, y;
      scanf("%d%d", &x, &y);
      if (find(x) == find(y)) {
        printf("SUCCESS\n");
      } else {
        printf("FAIL\n");
      }
    }
  }
}
