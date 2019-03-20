/*
* @Author: Yuuoniy
* @Date:   2017-11-07 20:13:03
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-07 20:27:39
*/
class Solution {
 public:
  int longestPalindrome(string s) {
    map<char, int> m;
    int len = 0;
    bool flag = true;
    for (int i = 0; i < s.size(); ++i) {
      ++m[s[i]];
    }
    for (int i = 0; i < m.size(); ++i) {
      if (m[i] % 2 == 0)
        len += m[i];
      else {
        if (flag) {
          ++len;
          flag = false;
        }
        len += m[i] - 1;
      }
    }
    return len;
  }
};

// 改进版：
class Solution {
 public:
  int longestPalindrome(string s) {
    int odds = 0;
    for (char c = 'A'; c <= 'z'; c++) {
      odds += count(s.begin(), s.end(), c) & 1;  //判断是否为奇数
    }
    return s.size() - odds + (odds > 0);
  }
};
//关注奇数个
