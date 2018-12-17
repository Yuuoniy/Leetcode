/*
* @Author: Yuuoniy
* @Date:   2017-11-02 12:43:07
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-02 19:49:59
*/
// Solution 1
class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n == 1)
      return true;
    else if (n % 3 != 0 || n == 0)
      return false;
    return isPowerOfThree(n / 3);
  }
};

// Solution 2:
class Solution {
 public:
  bool isPowerOfThree(int n) { return fmod(log10(n) / log10(3), 1) == 0; }
};
