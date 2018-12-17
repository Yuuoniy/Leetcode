/*
* @Author: Yuuoniy
* @Date:   2017-10-27 17:22:50
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-27 18:21:13
*/
// Solution 1:
class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    vector<int> res;
    int temp;
    int carry = (digits[digits.size() - 1] + 1) / 10;
    digits[digits.size() - 1] = (digits[digits.size() - 1] + 1) % 10;
    for (int i = digits.size() - 2; i >= 0; --i) {
      temp = digits[i];
      digits[i] = (carry + digits[i]) % 10;
      carry = (carry + temp) / 10;
    }
    if (carry) res.push_back(1);
    for (int i = 0; i < digits.size(); ++i) {
      res.push_back(digits[i]);
    }
    return res;
  }
};
// Solution 2:
class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    for (int i = digits.size(); i--;
         digits[i] = 0) {  // 一开始不是size-1是因为第二部分要执行i--
                           // digits[i]= 0 是因为有进位
      if (digits[i]++ < 9) return digits;  //表示没有进位了
    }
    digits[0]++;  //说明一直进位到最高位
    digits.push_back(0);
    return digits;
  }
};
//利用好for 。。
//思路好巧妙
