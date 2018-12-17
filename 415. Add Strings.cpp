/*
* @Author: Yuuoniy
* @Date:   2017-10-23 14:33:37
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-24 09:34:11
*/
class Solution {
 public:
  string addStrings(string num1, string num2) {
    int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
    string res = "";
    while (i >= 0 || j >= 0) {
      if (i >= 0) carry += num1[i--] - '0';
      if (j >= 0) carry += num2[j--] - '0';
      res = to_string(carry % 10) + res;  //这个好巧妙！！
      carry /= 10;
    }
    return carry ? "1" + res : res;
  }
};
// to_string的运用！
// 字符串相加
