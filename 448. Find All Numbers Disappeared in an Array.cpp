/*
* @Author: Yuuoniy
* @Date:   2017-10-27 21:59:27
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-27 22:16:28
*/
class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int m = 0;
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
      m = abs(nums[i]) -
          1;  //就算一开始nums[i] 不可能为负 但是我们后面有对它取负
      nums[m] = nums[m] < 0 ? nums[m] : -nums[m];
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) res.push_back(i + 1);
    }
    return res;
  }
};
//遍历一遍把数字都变成负数
//没遍历到就说明该位置i对应的整数i+1遗漏了
//真真厉害
//利用数组下标和1-n的对应关系
