/*
* @Author: Yuuoniy
* @Date:   2017-10-26 22:30:46
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-26 22:52:36
*/
// Solution 1：
class Solution {
 public:
  char findTheDifference(string s, string t) {
    int table[26];
    for (int i = 0; i < 26; ++i) {
      table[i] = 0;  //初始化
    }
    for (int i = 0; i < s.size(); ++i) {
      ++table[s[i] - 'a'];
    }
    for (int i = 0; i < t.size(); ++i) {
      --table[t[i] - 'a'];
      if (table[t[i] - 'a'] < 0) return t[i];
    }
  }
};

// Solution 2 :
class Solution {
 public:
  char findTheDifference(string s, string t) {
    char res = 0;
    for (auto m : s) {
      res ^= m;
    }
    for (auto m : t) {
      res ^= m;
    }
    return res;
  }
};
//使用异或一定要记得初始化！
//涉及到除了一个字符其他的都出现两次的要想到异或
