/*
* @Author: Yuuoniy
* @Date:   2017-10-27 09:51:45
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-27 10:05:30
*/

// Solution 1:
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    unordered_map<int, int> map;
    for (int i = 0; i < nums1.size(); i++) {
      ++map[nums1[i]];
    }
    for (int i = 0; i < nums2.size(); ++i) {
      if (map[nums2[i]] != 0) res.push_back(nums2[i]);
      map[nums2[i]] = 0;
    }
    return res;
  }
};

// Solution 2:
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> m(nums1.begin(), nums1.end());
    vector<int> res;
    for (auto n : nums2) {
      if (m.count(n)) {
        res.push_back(n);
        m.erase(n);
      }
    }
    return res;
  }
};
