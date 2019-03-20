/*
* @Author: Yuuoniy
* @Date:   2017-11-05 10:48:51
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-05 11:12:14
*/

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> res, temp(1, 1);
    for (int i = 0; i <= rowIndex; ++i) {
      res.resize(i + 1);
      res[0] = res[i] = 1;
      for (int j = 1; j < i; ++j) {
        res[j] = temp[j - 1] + temp[j];
      }
      temp = res;
    }
    return res;
  }
};

// 改进版：
class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> res(rowIndex + 1);
    res[0] = 1;
    for (int i = 0; i <= rowIndex; ++i) {
      for (int j = i; j > 0; --j) {  //从后往前运算才不会影响
        res[j] = res[j] + res[j - 1];
      }
    }
    return res;
  }
};
