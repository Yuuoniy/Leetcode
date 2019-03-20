/*
* @Author: Yuuoniy
* @Date:   2017-12-26 18:55:32
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-12-26 20:06:58
*/
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> waits(n, 0);
    vector<int> next(101, INT_MAX);
    for (int i = n - 1; i >= 0; i--) {
      int earliest = INT_MAX;
      for (int t = temperatures[i] + 1; t <= 100; t++) {
        earliest = min(earliest, next[t]);
      }
      if (earliest != INT_MAX) waits[i] = earliest - i;
      next[temperatures[i]] = i;
    }
    return waits;
  }
};
