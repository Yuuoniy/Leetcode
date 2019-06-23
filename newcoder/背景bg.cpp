
/*
 * @Author: yuuoniy
 * @Date: 2019-06-18 15:51:40
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-18 16:05:30
 */

#include <algorithm>
#include <iostream>

using namespace std;

struct event {
  int happiness;
  int lastTime;
  int leaveTime;
  bool operator<(const event a) const { return leaveTime < a.leaveTime; }
};

int n;
int main() {
  while (cin >> n && n != 0) {
    int dp[1000] = {0};
    event eventList[30];
    for (int i = 0; i < n; i++) {
      cin >> eventList[i].happiness >> eventList[i].lastTime >>
          eventList[i].leaveTime;
    }
    sort(eventList, eventList + n);
    int maxValue = 0;
    for (int i = 0; i < n; i++) {
      for (int j = eventList[i].leaveTime; j >= eventList[i].lastTime; --j) {
        dp[j] =
            max(dp[j - eventList[i].lastTime] + eventList[i].happiness, dp[j]);
        maxValue = max(maxValue, dp[j]);
      }
    }
    cout << maxValue << endl;
  }

  return 0;
}
