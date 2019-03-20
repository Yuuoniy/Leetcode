/*
* @Author: Yuuoniy
* @Date:   2017-11-04 21:35:13
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-04 21:53:21
*/
// Solution 1:
class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    map<char, char> cor1;
    map<char, char> cor2;
    for (int i = 0; i < s.size(); ++i) {
      cor1[s[i]] = t[i];
      cor2[t[i]] = s[i];
    }
    string str1, str2;
    for (int i = 0; i < s.size(); ++i) {
      str1 += cor1[s[i]];
      str2 += cor2[t[i]];
    }
    return str1 == t && str2 == s;
  }
};

// Solution 2:
class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    char charArrS[256] = {0};
    char charArrT[256] = {0};
    int i = 0;
    while (s[i] != 0) {
      if (charArrS[s[i]] == 0 && charArrT[t[i]] == 0) {
        charArrS[s[i]] = t[i];
        charArrT[t[i]] = s[i];
      }
      if (charArrS[s[i]] != t[i] || charArrT[t[i]] != s[i]) return false;
      ++i;
    }
    return true;
  }
};
