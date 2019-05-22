/*
 * @Author: yuuoniy
 * @Date: 2019-05-18 10:17:27
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-18 17:58:57
 */
// 关键是题意的转化，理解每一个状态，状态间的转移，隐式图遍历
// 状态用二维数组表示
// 要明确：因为没有刻度，要不不倒，要倒就倒完
// 注意清空状态！
// 不知道哪错了。。  每次都要赋值为原水位！
#include <iostream>
#include <queue>

using namespace std;

int s, n, m;
int ans;

struct state {
  int v[3]; //三个瓶子的容量
  int step; // bfs 的 step
};

bool visited[105][105];

int vol[3];     ///三个瓶子的容量
state cur, tmp; //当前状态

// x 向 y 倒水
void pour(int x, int y) {
  //查看当前状态
  int sum = cur.v[x] + cur.v[y];
  int pour_vol = 0;
  if (sum >= vol[y]) //倒满
    pour_vol = vol[y] - cur.v[y];
  else 
    pour_vol = cur.v[x]; //倒完
  tmp = cur;
  tmp.v[x] -= pour_vol; //更新容量
  tmp.v[y] += pour_vol;
}

void bfs() {
  queue<state> q;
  state t;
  t.v[0] = s;
  t.v[1] = 0;
  t.v[2] = 0;
  t.step = 0;
  q.push(t);
  cur = t; //当前状态
  visited[t.v[0]][t.v[1]] = 1;

  while (!q.empty()) {
    state t = q.front();
    int count_equal_half = 0;
    q.pop();
    if (t.v[0] == s / 2)
      ++count_equal_half;
    if (t.v[1] == s / 2)
      ++count_equal_half;
    if (t.v[2] == s / 2)
      ++count_equal_half;
    if (count_equal_half == 2) { //说明可以平分
      cout << t.step << endl;
      return;
    }
    cur = t;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i == j)
          continue;
        //每次都要赋值为原水位！
        cur = t;
        pour(i, j);
        if (visited[tmp.v[0]][tmp.v[1]] == 0) {
          visited[tmp.v[0]][tmp.v[1]] = 1;
          tmp.step = tmp.step + 1;
          q.push(tmp);
        }
      }
    }
  }
  cout << "NO" << endl;
}

int main() {
  while (cin >> s >> n >> m && s != 0 && n != 0 && m != 0) {
    for (int i = 0; i < 105; i++) {
      for (int j = 0; j < 105; j++) {
        visited[i][j] = 0;
      }
    }
    vol[0] = s;
    vol[1] = n;
    vol[2] = m;
    if (s & 1) {
      cout << "NO" << endl;
      continue;
    } else
      bfs();
  }
  return 0;
}
