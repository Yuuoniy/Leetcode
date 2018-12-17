/*
* @Author: Yuuoniy
* @Date:   2017-10-25 20:46:41
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-07 19:49:52
*/
class Solution {
 public:
  int getSum(int a, int b) {
    int sum = a;
    while (b != 0) {
      sum = a ^ b;       // calculate sum of a and b without thinking the carry
      b = (a & b) << 1;  // calculate the carry
      a = sum;           // add sum(without carry) and carry
    }
    return sum;
  }
};
