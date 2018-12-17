/*
* @Author: Yuuoniy
* @Date:   2017-10-25 20:21:04
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-25 20:39:26
*/
class Solution {
 public:
  bool judgeSquareSum(int c) {
    for (int i = 0; i <= sqrt(c); i++) {
      int sum_left = c - i * i;
      if ((int)sqrt(sum_left) * (int)sqrt(sum_left) == sum_left) return true;
    }
    return false;
  }
};
