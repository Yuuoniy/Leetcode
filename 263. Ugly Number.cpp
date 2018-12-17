/*
* @Author: Yuuoniy
* @Date:   2017-11-06 08:29:37
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-06 08:45:33
*/
class Solution {
 public:
  bool isUgly(int num) {
    if (num <= 0) return false;
    vector<int> divisor({2, 3, 5});
    for (auto i : divisor) {
      while (num % i == 0) {
        num /= i;
      }
    }
    return num == 1;
  }
};
