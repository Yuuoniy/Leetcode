/*
* @Author: Yuuoniy
* @Date:   2018-01-02 20:37:45
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2018-01-02 20:46:00
*/
class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> dict;
    vector<int> res;
    for (int i = 0; i < nums1.size(); ++i) {
      dict[nums1[i]]++;
    }
    for (int i = 0; i < nums2.size(); ++i)  //注意同个数字出现多次的情况
    {
      if (--dict[nums2[i]] >= 0) res.push_back(nums2[i]);
    }
    return res;

  }
};
