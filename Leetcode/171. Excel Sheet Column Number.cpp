/*
* @Author: Yuuoniy
* @Date:   2017-10-28 16:41:34
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-28 16:55:16
*/
class Solution {
 public:
  int titleToNumber(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
      res *= 26;
      res += s[i] - 'A' + 1;
    }
    return res;
  }
};
//用 at 比直接用下标快
// 精简版
class Solution {
 public:
  int titleToNumber(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); res = res * 26 + (s.at[i] - 'A' + 1), ++i) {
      /* code */
    }
  }
};
