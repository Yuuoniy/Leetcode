/*
* @Author: Yuuoniy
* @Date:   2017-11-04 22:32:49
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-04 22:33:26
*/
class Solution {
 public:
  int trailingZeroes(int n) {
    int res = 0;
    while (n) {
      n /= 5;
      res += n;
    }
    return res;
  }
};
