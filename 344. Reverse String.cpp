/*
* @Author: Yuuoniy
* @Date:   2017-10-24 16:21:14
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-24 16:33:46
*/
class Solution {
 public:
  string reverseString(string s) { return string(s.rbegin(), s.rend()); }
};
// rbegin 返回 string 的最后一个字符的位置
// rend 返回 string 第一个字符位置的前面
