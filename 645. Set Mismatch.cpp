/*
* @Author: Yuuoniy
* @Date:   2017-10-29 21:34:54
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-29 21:41:40
*/
class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    unordered_map<int, int> mp;
    int depu = 0, miss = 0;
    for (int i = 1; i <= nums.size(); ++i) {
      mp[i] = 0;
    }
    for (int i = 0; i < nums.size(); ++i) {
      mp[nums[i]]++;
      if (mp[nums[i]] == 2) depu = nums[i];
    }
    for (int i = 1; i <= mp.size(); ++i) {
      if (mp[i] == 0) {
        miss = i;
        break;
      }
    }
    return {depu, miss};
  }
};
