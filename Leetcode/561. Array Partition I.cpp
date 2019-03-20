/*
* @Author: Yuuoniy
* @Date:   2017-10-23 21:49:08
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-24 09:17:43
*/
class Solution {
 public:
  int arrayPairSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int res = 0;
    for (int i = 0; i < nums.size(); i = i + 2) {
      res += nums[i];
    }
    return res;
  }
};
//让大的和更大的呆在一起 这样取min时比较大
