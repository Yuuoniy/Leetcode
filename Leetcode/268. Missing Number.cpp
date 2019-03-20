/*
* @Author: Yuuoniy
* @Date:   2017-10-26 00:08:56
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-26 00:11:08
*/
class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int res = nums.size();  //因为i不能到size 只能自己添加
    int i = 0;
    for (int n : nums) {
      res ^= n;
      res ^= i;
      i++;
    }
    return res;
  }
};
