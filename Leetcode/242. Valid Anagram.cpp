/*
* @Author: Yuuoniy
* @Date:   2017-11-09 21:25:39
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-09 21:38:54
*/
class Solution {
 public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); ++i) {
      ++mp[s[i]];
    }
    for (int i = 0; i < t.size(); ++i) {
      --mp[t[i]];
    }
    for (int i = 0; i < mp.size(); ++i) {
      if (mp[i]) return false;
    }
    return true;
  }
};

// 改进版：
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;  //！
    int n = s.length();
    unordered_map<char, int> counts;
    for (int i = 0; i < n; i++) {
      counts[s[i]]++;
      counts[t[i]]--;
    }
    for (auto count : counts)
      if (count.second) return false;
    return true;
  }
};
