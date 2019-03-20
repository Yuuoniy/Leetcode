
/*
* @Author: Yuuoniy
* @Date:   2017-10-26 23:51:03
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-27 00:01:15
*/
class Solution {
 public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int pigs = 0;
    while (pow(minutesToTest / minutesToDie + 1, pigs) < buckets) ++pigs;
    return pigs;
  }
};
//每试一轮都要等看有没有死
