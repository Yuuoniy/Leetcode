/*
* @Author: Yuuoniy
* @Date:   2017-11-09 19:01:18
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-09 19:19:54
*/
// Solution 1:
class Solution {
 public:
  bool hasAlternatingBits(int n) {
    bool flag = true;
    while (n) {
      if ((n & 1) == (n >> 1 & 1)) return false;
      n = n >> 1;
    }
    return true;
  }
};

// Solution 2:
class Solution {
 public:
  bool hasAlternatingBits(int n) {
    int d = n & 1;
    while ((n & 1) == d) {
      d = 1 - d;  //反转
      n >>= 1;
    }
    return n == 0;
  }
};
