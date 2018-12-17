/*
* @Author: Yuuoniy
* @Date:   2017-11-05 10:23:32
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-05 10:43:23
*/
// Solution 1:
class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res(numRows);
    for (int i = 0; i < numRows; ++i) {
      res[i].resize(i + 1);
      for (int j = 0; j < i + 1; ++j) {
        if (j == 0 || j == i) {
          res[i][j] = 1;
          continue;
        }
        res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
      }
    }
    return res;
  }
};

// 改进版：
class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res(numRows);
    for (int i = 0; i < numRows; i++) {
      res[i].resize(i + 1);
      res[i][0] = res[i][i] = 1;
      for (int j = 0; j < i; ++j) {
        res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
      }
    }
    return res;
  }
};
