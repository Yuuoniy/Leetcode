/*
* @Author: Yuuoniy
* @Date:   2017-11-05 09:14:29
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-05 09:36:59
*/
class Solution {
 public:
  int rob(vector<int>& nums) {
    int even = 0, odd = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i % 2 == 0) {
        even = max(even + nums[i], odd);
      } else
        odd = max(odd + nums[i], even);
    }
    return max(even, odd);
  }
};

// even odd 分别记录偷even 和 odd 家的 max
// 值是会根据最大值的情况改变的,不是单独even家的和 odd 家的和
