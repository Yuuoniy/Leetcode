/*
* @Author: Yuuoniy
* @Date:   2017-11-06 15:43:16
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-06 15:50:06
*/

// Solution 1:
class Solution {
 public:
  int countSegments(string s) {
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != ' ') {
        ++count;
        while (s[i] != ' ' && i < s.size()) {
          ++i;
        }
      }
    }
    return count;
  }
};

// Solution 2:
class Solution {
 public:
  int countSegments(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
      res += s[i] != ' ' && (i + 1 == s.size() || s[i + 1] == ' ');
    }
    return res;
  }
};
