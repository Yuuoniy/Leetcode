/*
* @Author: Yuuoniy
* @Date:   2017-10-26 22:52:44
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-26 23:33:17
*/
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int j = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != 0) nums[j++] = nums[i];
    }
    for (; j < nums.size(); ++j) {
      nums[j] = 0;
    }
  }
};
//先吧非0的元素全部向前移 剩下的位置全部赋值0
//还是类似快慢指针吧
//已经知道那个数字固定了0了呀
//
