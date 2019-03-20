/*
* @Author: Yuuoniy
* @Date:   2017-10-23 13:41:40
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-24 09:17:42
*/
class Solution {
 public:
  int divide(int dividend, int divisor) {
    if (!divisor || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    long dvd = labs(dividend);
    long dvs = labs(divisor);
    long res = 0;
    while (dvd >= dvs) {
      long temp = dvs, multiple = 1;
      while (dvd >= (temp << 1)) {
        temp <<= 1;
        multiple <<= 1;
      }
      dvd -= temp;
      res += multiple;
    }
    return sign == 1 ? res : -res;
  }
};
//考虑符号
// abs(INT_MIN) = INT_MAX + 1
//使用^判断符号是否相同
// C 库函数 long int labs(long int x) 返回 x 的绝对值。
//注意超时问题 巧妙地使用 位运算符
// int 不够
