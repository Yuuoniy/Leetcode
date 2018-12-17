/*
* @Author: Yuuoniy
* @Date:   2017-10-25 23:51:50
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-25 23:59:55
*/

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      res ^= nums[i];
    }
    return res;
  }
};
// XOR !!a^a = 0
