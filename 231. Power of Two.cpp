/*
* @Author: Yuuoniy
* @Date:   2017-11-02 19:50:55
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-02 20:09:36
*/
// Solution 1:
class Solution {
 public:
  bool isPowerOfTwo(int n) { return fmod(log10(n) / log10(2), 1) == 0; }
};
// Solution 2:
class Solution {
 public:
  bool isPowerOfFour(int num) {
    return num > 0 && !(num & num - 1) && !((num - 1) % 3);
  }
};
// 1. (num & num - 1) = 0 说明num是2的次方
//数学证明4的次方-1都能整除3
