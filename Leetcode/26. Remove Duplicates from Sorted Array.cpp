/*
* @Author: Yuuoniy
* @Date:   2017-11-06 08:51:12
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-06 09:07:15
*/
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int count = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1])
        ++count;
      else
        nums[i - count] = nums[i];
    }
    return nums.size() - count;
  }
};
//算每一位前面有多少个重复的数字 设个 n，则将每位往前移n位
//总数减去重复数即为最终长度
