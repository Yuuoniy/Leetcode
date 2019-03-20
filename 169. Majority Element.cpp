/*
* @Author: Yuuoniy
* @Date:   2017-10-28 15:53:57
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-28 15:58:56
*/
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> count;
    for (int i = 0; i < nums.size(); ++i) {
      if (++count[nums[i]] > nums.size() / 2) return nums[i];
    }
  }
};
