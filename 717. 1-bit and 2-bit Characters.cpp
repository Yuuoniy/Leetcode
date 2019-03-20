/*
* @Author: Yuuoniy
* @Date:   2017-11-06 16:12:45
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-06 16:22:35
*/
class Solution {
 public:
  bool isOneBitCharacter(vector<int>& bits) {
    bool a = false;
    for (int i = 0; i < bits.size();) {
      if (bits[i]) {
        a = false;
        i += 2;
      } else {
        a = true;
        ++i;
      }
    }
    return a;
  }
};
