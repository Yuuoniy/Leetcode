/*
 * @Author: yuuoniy
 * @Date: 2019-06-16 00:59:42
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-16 09:31:48
 */

// https://www.nowcoder.com/questionTerminal/761fc1e2f03742c2aa929c19ba96dbb0
// bfs
#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

string ans = "2012";
map<string, int> M;

void bfs(int x, int cnt) {}

int step;
string str;

bool judge(string str) {
  if (str.find("2012") == string::npos)
    return false;
  else
    return true;
}

//第 i 位与第 i+1 位交换
string Swap(string str, int i) {
  string newStr = str;
  char tmp = newStr[i];
  newStr[i] = newStr[i + 1];
  newStr[i + 1] = tmp;
  return newStr;
}

int bfs(string str) {
  string newStr;
  M.clear();
  queue<string> q;
  q.push(str);
  M[str] = 0;
  while (!q.empty()) {
    str = q.front();
    q.pop();
    for (int i = 0; i < str.size() - 1; i++) {
      newStr = Swap(str, i);
      if (M.find(newStr) == M.end()) {
        M[newStr] = M[str] + 1;
        if (judge(newStr) == true)
          return M[newStr];
        else
          q.push(newStr);
      } else
        continue;
    }
  }
  return -1;
}


int main() {
  int n;
  string str;
  while (scanf("%d", &n) != EOF) {
    cin >> str;
    if (judge(str)) {
      printf("0\n");

    } else {
      int ans = bfs(str);
      printf("%d\n", ans);
    }
  }
  return 0;
}
