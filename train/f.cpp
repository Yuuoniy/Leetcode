#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAX_N = 1005;
char kind[MAX_N];
// char label[6] = [ 'U', 'W', 'R', 'B', 'L', 'S' ];
bool hasknown[MAX_N];

struct node {

  int x;
  int y;
  char op;
  node(int _x, int _y, char _op) {
    x = _x;
    y = _y;
    op = _op;
  }
};

vector<node> r;
int n, m;

void check() {
  for (int i = 0; i < m; i++) {
    int x = r[i].x, y = r[i].y;
    char op = r[i].op;
    cout << x << y << endl;
    if (hasknown[x] && hasknown[y])
      continue;
    if (op == '<') {
      if (kind[x] == 'U' && kind[y] == 'U') {
        kind[x] = 'S';
        kind[y] = 'L';
      } else if (kind[y] == 'S') {
        kind[x] = 'R';
        kind[y] = 'B';
        hasknown[x] = hasknown[y] = 1;
      } else if (kind[y] == 'R') {
        kind[x] = 'B';
        hasknown[x] = 1;
      } else if(kind[x]=='L'){
        kind[x] = 'R';
        kind[y] = 'W';
        hasknown[x]= hasknown[y] = 1;
      }
    } else if (op == '>') {
      if (kind[x] == 'U' && kind[y] == 'U') {
        kind[x] = 'L';
        kind[y] = 'S';
      } else if (kind[y] == 'L') {
        kind[y] = 'R';
        kind[x] = 'W';
        hasknown[x] = 1;
      } else if (kind[x] == 'W') {
        kind[y] = 'S';
      } else if (kind[x] == 'R') {
        kind[y] = 'B';
        hasknown[y] = 1;
      }
    } else if (op == '=') {
      if (kind[x] == 'U' && kind[y] == 'U') {
        continue;
      } else if (hasknown[x]) {
        kind[y] = kind[x];
        hasknown[y] = 1;
      } else if (hasknown[y]) {
        kind[x] = kind[y];
        hasknown[x] = 1;
      } else if (kind[x] != 'U') {
        kind[y] = kind[x];
      } else if (kind[y] != 'U') {
        kind[x] = kind[x];
      }
    }
  }
}

int main() {
  memset(kind, 'U', sizeof(kind));
  cin >> n >> m;
  for (int i = 0; i < m; i++) {

    int x, y;
    char op;
    cin >> x >> op >> y;
    r.push_back(node(x, y, op));
  }

  check();
  check();
  for (int i = 0; i < n; i++) {
    printf("%c", hasknown[i] ? kind[i] : '?');
  }
  return 0;
}
