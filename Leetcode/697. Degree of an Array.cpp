/*
* @Author: Yuuoniy
* @Date:   2017-10-24 17:14:38
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-24 17:38:42
*/

// 利用哈希表
// 转换题意
class Solution {
 public:
  int findShortestSubArray(vector<int>& nums) {
    if (nums.size() < 2) return nums.size();
    int len = nums.size();
    int m = 0, fre = 0;
    unordered_map<int, int> startIndex, count;
    for (int i = 0; i < nums.size(); i++) {
      m = nums[i];
      if (startIndex.count(m) == 0) startIndex[m] = i;
      count[m]++;
      if (count[m] == fre) {
        len = min(i - startIndex[m] + 1, len);
      } else if (count[m] > fre) {
        len = i - startIndex[m] + 1;
        fre = count[m];
      }
    }
    return len;
  }
};
