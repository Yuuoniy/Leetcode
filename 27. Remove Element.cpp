/*
* @Author: Yuuoniy
* @Date:   2017-10-29 20:36:27
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-29 20:47:16
*/
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int ans = 0;
    for (vector<int>::iterator it = nums.begin(); it != nums.end();) {
      if (*it == val)
        it = nums.erase(it);
      else
        ++it;
    }
    return nums.size();
  }
};
//注意erase的使用方法
