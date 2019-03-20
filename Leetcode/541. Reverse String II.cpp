/*
* @Author: Yuuoniy
* @Date:   2017-11-09 21:38:57
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-09 21:48:43
*/
class Solution {
 public:
  string reverseStr(string s, int k) {
    for (int i = 0; i < s.size(); i += 2 * k) {
      reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
    }
    return s;
  }
};
