/*
* @Author: Yuuoniy
* @Date:   2017-11-06 15:55:31
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-06 16:09:27
*/
class Solution {
 public:
  int arrangeCoins(int n) {
    int res = 0, i = 1;
    while (n >= i) {
      ++res;
      n -= i;
      ++i;
    }
    return res;
  }
};

// Solution 2:
class Solution {
 public:
  int arrangeCoins(int n) { return floor(-0.5 + sqrt((double)2 * n + 0.25)); }
};
