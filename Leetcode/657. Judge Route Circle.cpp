/*
* @Author: Yuuoniy
* @Date:   2017-10-24 14:34:59
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-24 14:55:56
*/

class Solution {
 public:
  bool judgeCircle(string moves) {
    unordered_map<char, int> map1;
    for (char m : moves) {
      ++map1[m];
    }
    return (map1['L'] == map1['R'] && map1['U'] == map1['D']);
  }
};
