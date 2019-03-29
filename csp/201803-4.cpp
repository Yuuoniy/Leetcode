// 1 表示 Alice, 2 表示 Bob
#include <iostream>

using namespace std;
int map[4][4];

//判断是否连成一条边
bool rowLine(int r, int person) {
  // cout << "in rowLine" << endl;
  return map[r][0] == person && map[r][1] == map[r][0] &&
         map[r][2] == map[r][0];
}

bool colLine(int col, int person) {
  return map[0][col] == person && map[1][col] == map[0][col] &&
         map[2][col] == map[0][col];
}

bool dig(int person) {
  return (map[0][0] == person && map[1][1] == person && map[2][2] == person) ||
         (map[0][2] == person && map[1][1] == person && map[2][0] == person);
}

int countSpace() {
  int count = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (map[i][j] == 0)
        ++count;
    }
  }
  // cout << "current space" << count << endl;
  return count;
}

int isWin(int person) {
  int win = 0, ans = 1; //为什么是 1 呢
  if (rowLine(0, person) || rowLine(1, person) || rowLine(2, person))
    win = 1;
  if (colLine(0, person) || colLine(1, person) || colLine(2, person))
    win = 1;
  if (dig(person))
    win = 1;
  if (win == 0)
    return 0;
  // cout << "win!!" << endl;
  ans += countSpace();
  return person == 1 ? ans : -ans;
}

int dfs(int person) {
  if (countSpace() == 0){
    // cout << "could keep on" << endl;
    return 0; //无法再继续下了
  }
  int maxScore = -10, minScore = 10;
  int winScore = 0;;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (map[i][j] == 0) {
        map[i][j] = person;
        winScore = isWin(person);
        if (winScore) { //如果赢了
          map[i][j] = 0;
          return winScore > 0 ? max(maxScore, winScore)
                              : min(minScore, winScore);
        }
        //没赢的继续下
        if (person == 1)
          maxScore = max(maxScore, dfs(2));
        else
          minScore = min(minScore, dfs(1));
        map[i][j] = 0;
      }
    }
  }
  return person == 1 ? maxScore : minScore;
}

int main() {
  int n = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int row = 0; row < 3; row++) {
      for (int col = 0; col < 3; col++) {
        cin >> map[row][col];
      }
    }
    //首先判断当前局面是否赢了！
    int isAliceWin = isWin(1);
    int isBobWin = isWin(2);
    if (isAliceWin){
      // cout << "alice win" << endl;
      cout << isAliceWin << endl;
    }
    else if (isBobWin){
      // cout << "bob win" << endl;
      cout << isBobWin << endl;
    }
    else{
      // cout << "start dfs" << endl;
      cout << dfs(1) << endl; // Alice 开始

    }
  }
  return 0;
}
