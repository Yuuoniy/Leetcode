/*
* @Author: Yuuoniy
* @Date:   2017-11-05 09:37:22
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-05 10:23:27
*/
// Solution 1:
class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == target || nums[i] > target) return i;
      while (nums[i] < target && i + 1 < nums.size() && nums[i + 1] < target) {
        ++i;
      }
      res = i + 1;
      break;
    }
    return res;
  }
};

// Solution 2:
class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] < target)
        low = mid + 1;
      else
        high = mid - 1;
    }
    return low;
  }
};
