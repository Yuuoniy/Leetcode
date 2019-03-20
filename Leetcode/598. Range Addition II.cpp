/*
* @Author: Yuuoniy
* @Date:   2017-11-07 20:10:30
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-07 20:12:07
*/

class Solution {
 public:
  int maxCount(int m, int n, vector<vector<int>>& ops) {
    for (int i = 0; i < ops.size(); ++i) {
      m = min(m, ops[i][0]);
      n = min(n, ops[i][1]);
    }
    return m * n;
  }
};
