/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *  快速幂运算
 *  要 Long long 这操作也太迷了，怎么可能一发过嘛呜呜呜，太细节了
 *  注意类型转换！
 */
class Solution {
public:
  double myPow(double x, int n) {
    double ans = 0;
    int isNegative =(n < 0);
    int b = abs(n);
    while (b != 0) {
      if (b & 1)
        ans *= x;
      x *= x;
      b >>= 1;
    }
    // if (isNegative)
    //   ans = 1.0 / ans;
    return ans;
  }
};
