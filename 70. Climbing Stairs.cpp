/*
* @Author: Yuuoniy
* @Date:   2017-10-23 21:24:43
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-24 09:17:45
*/
//类似斐波那契数列
class Solution {
 public:
  int climbStairs(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    int beforeOne = 2;  // n-1
    int beforeTwo = 1;  // n-2
    int total = 0;
    for (int i = 2; i < n; ++i) {
      total = beforeTwo + beforeOne;
      beforeTwo = beforeOne;
      beforeOne = total;
    }
    return total;
  }
};

// 超时：
// class Solution {
//  public:
//   int climbStairs(int n) {
//     if (n <= 0) return 0;
//     if (n == 1) return 1;
//     if (n == 2)
//       return 2;
//     else
//       return climbStairs(n - 1) + climbStairs(n - 2);
//   }
// };
//
