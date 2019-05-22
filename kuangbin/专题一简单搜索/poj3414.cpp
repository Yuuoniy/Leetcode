/*
 * @Author: yuuoniy
 * @Date: 2019-05-18 16:49:01
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-18 17:58:39
 */

// 宽度优先搜索，和前面倒水很类似
// 不过结果好迷啊。。为什么会变成 fill2 ??
// map 还是不要用自定义类吧，有点坑，因为 step 不一样也更新了吧,用 pair 就好了！
// 代码风格还可以再优化的..不过现在懒得改了

#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <utility>


using namespace std;
typedef pair<int,int> P;

struct state {
  int v[2];
  int step;
  // bool operator<(const state s) const { return step < s.step; }
};

struct node {
  state s;
  string op;
};

vector<string> ops;

int v[2];
map<P, node> pre;
bool visited[105][105];
int a, b, c;

string tostring(int i) {
  stringstream ss;
  ss << i;
  string res;
  ss >> res;
  return res;
}

int main() {
  cin >> v[0] >> v[1] >> c;
  state t;
  t.v[0] = t.v[1] = t.v[2] = 0;
  t.step = 0;
  queue<state> q;
  q.push(t);
  visited[t.v[0]][t.v[1]] = 1;
  bool find = false;
  while (!q.empty()) {
    t = q.front();
    q.pop();
    if (t.v[0] == c || t.v[1] == c) {
      cout << t.step << endl;
      find = true;
      break;
    }
    // fill
    for (int i = 0; i < 2; i++) {
      state tmp = t;
      tmp.v[i] = v[i];
      if (visited[tmp.v[0]][tmp.v[1]] == 0) {
        visited[tmp.v[0]][tmp.v[1]] = 1;
        tmp.step = t.step + 1; //添加步数
        node prev; //记录前驱结点，包括状态以及下一步的操作
        prev.s = t;
        prev.op = "FILL(" + tostring(i + 1) + ")";
        pre[make_pair(tmp.v[0],tmp.v[1])] = prev;
        q.push(tmp);
      }
    }

    // drop
    for (int i = 0; i < 2; i++) {
      if (t.v[i] == 0)
        continue;
      state tmp = t;
      tmp.v[i] = 0;
      if (visited[tmp.v[0]][tmp.v[1]] == 0) {
        visited[tmp.v[0]][tmp.v[1]] = 1;
        tmp.step = t.step + 1; //添加步数
        node prev; //记录前驱结点，包括状态以及下一步的操作
        prev.s = t;
        prev.op = "DROP(" + tostring(i + 1) + ")";
        pre[make_pair(tmp.v[0],tmp.v[1])] = prev;
        q.push(tmp);
      }
    }
    // pour
    for (int i = 0; i < 2; i++) {
      if (t.v[i] == 0)
        continue;
      int j = i == 0 ? 1 : 0;
      int sum = t.v[0] + t.v[1];
      state tmp = t;
      if (sum >= v[j]) //倒满
      {
        tmp.v[j] = v[j];
        tmp.v[i] -= (v[j] - t.v[j]);
      } else { //倒完
        tmp.v[j] += tmp.v[i];
        tmp.v[i] = 0;
      }
      if (visited[tmp.v[0]][tmp.v[1]] == 0) {
        visited[tmp.v[0]][tmp.v[1]] = 1;
        tmp.step = t.step + 1; //添加步数
        node prev; //记录前驱结点，包括状态以及下一步的操作
        prev.s = t;
        prev.op = "POUR(" + tostring(i + 1) + "," + tostring(j + 1) + ")";
        pre[make_pair(tmp.v[0],tmp.v[1])] = prev;
        q.push(tmp);
      }
    }
  }

  if (find) {
    node n = pre[make_pair(t.v[0],t.v[1])];
    while (true) {
      ops.push_back(n.op);
      if (n.s.v[0] == 0 && n.s.v[1] == 0)
        break;
      n = pre[make_pair(n.s.v[0],n.s.v[1])];
    }
    for (int i = ops.size() - 1; i >= 0; i--) {
      cout << ops[i] << endl;
    }

  } else {
    cout << "impossible";
  }
  return 0;
}
