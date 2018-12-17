/*
* @Author: Yuuoniy
* @Date:   2017-10-23 23:18:52
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-24 16:11:00
*/
class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int max = 0, second = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 1) {
        max = max > ++second ? max : second;  //很巧妙 实时更新max的值
      } else
        second = 0;
    }
    return max;
  }
};
//注意最长的出现在最后 如01101111 for循环中没有赋给max的情况
//目前解法不存在该问题
