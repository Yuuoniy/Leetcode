/*
* @Author: Yuuoniy
* @Date:   2017-11-07 17:31:20
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-07 17:43:27
*/
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, tar = m + n - 1;
    while (j >= 0) {
      nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    }
  }
};
//从后往前 思路巧妙
