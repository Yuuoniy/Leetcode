/*
* @Author: Yuuoniy
* @Date:   2017-10-27 00:07:42
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-27 00:14:17
*/
class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> map;
    for (int i = 0; i < magazine.size(); ++i) {
      ++map[magazine[i]];
    }
    for (int i = 0; i < ransomNote.size(); ++i) {
      --map[ransomNote[i]];
      if (map[ransomNote[i]] < 0) return false;
    }

    return true;
  }
};
