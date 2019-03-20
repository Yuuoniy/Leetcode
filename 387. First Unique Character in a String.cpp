/*
* @Author: Yuuoniy
* @Date:   2018-01-02 22:07:53
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2018-01-02 22:12:14
*/
class Solution {
 public:
  int firstUniqChar(string s) {
    unordered_map<char, int> p;
    for (auto c : s) {
      p[c]++;
    }
    for (int i = 0; i < s.size(); ++i) {
      if (p[s[i]] == 1) return i;
    }
    return -1;
  }
};
