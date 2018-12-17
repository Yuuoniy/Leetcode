/*
* @Author: Yuuoniy
* @Date:   2017-10-26 09:16:31
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-26 09:22:30
*/
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int ans = nums[0], sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      ans = max(sum, ans);
      sum = max(sum, 0);
    }
    return ans;
  }
};
//不断加每一个数 当和降为0时重置
