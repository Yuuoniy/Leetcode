/*
 * @Author: yuuoniy
 * @Date: 2019-05-18 20:08:59
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-18 20:18:22
 */

// 简单 bfs

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

const int MAX_N = 100005;
typedef pair<int, int> node;

bool visited[MAX_N];
int n, k;
void bfs() {
  queue<node> q;
  q.push(make_pair(n, 0));
  visited[n] = true;
  while (!q.empty()) {
    node t = q.front();
    q.pop();
    if (t.first == k) {
      cout << t.second << endl;
      return;
    }
    if (t.first - 1 >= 0 && !visited[t.first - 1]) {
      visited[t.first - 1] = 1;
      q.push(make_pair(t.first - 1, t.second + 1));
    }
    if (t.first + 1 <= 100000 && !visited[t.first + 1]) {
      visited[t.first + 1] = 1;
      q.push(make_pair(t.first + 1, t.second + 1));
    }
    if (t.first * 2 <= 100000 && !visited[t.first * 2]) {
      visited[t.first * 2] = 1;
      q.push(make_pair(t.first * 2, t.second + 1));
    }
  }
}
int main() {
  cin >> n >> k;
  bfs();
  return 0;
}
