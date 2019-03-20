/*
* @Author: Yuuoniy
* @Date:   2018-01-02 22:14:34
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2018-01-03 19:27:38
*/
class Solution {
 public:
  int dominantIndex(vector<int>& nums) {
    vector<int> copy(nums);
    sort(copy.begin(), copy.end());
    if (copy[copy.size() - 1] >= copy[copy.size() - 2] * 2)
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == copy[copy.size() - 1]) return i;
      }
    else
      return -1;
  }
};
