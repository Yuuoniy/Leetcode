/*
* @Author: Yuuoniy
* @Date:   2017-10-24 14:09:56
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-24 14:17:57
*/
class Solution {
 public:
  int hammingDistance(int x, int y) {
    int distance = 0, n = x ^ y;
    for (int i = 0; n; n >>= 1) {
      distance += n & 1;
    }
    return distance;
  }
};
