/*
 * @Author: yuuoniy 
 * @Date: 2019-05-18 10:14:08 
 * @Last Modified by:   yuuoniy 
 * @Last Modified time: 2019-05-18 10:14:08 
 */
#include <iostream>

using namespace std;

// 要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列
// 一行行搜索，放了棋子就标记这一列
// 重点：要一行一行搜索，而不是一个一个！
char m[10][10];
bool visited[10];
int ans;
int n, k;
//逐行扫描
void dfs(int r, int count) {
  if (count == k) {
    ++ans;
    return;
  }
  for (int i = r; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (m[i][j] == '#' && visited[j] != 1) {
        visited[j] = 1;
        dfs(i + 1, count + 1);
        visited[j] = 0;
      }
    }
  }
}

int main() {
  while (cin >> n >> k && n != -1 && k != -1) {
    for (int i = 0; i < n; i++) {
      visited[n] = 0;
    }

    ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> m[i][j];
      }
    }

    dfs(0, 0);

    cout << ans << endl;
  }
}
