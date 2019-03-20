/*
* @Author: Yuuoniy
* @Date:   2017-10-23 14:58:45
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-24 09:17:38
*/
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      auto p = map.find(target - nums[i]);
      if (p != map.end()) return {p->second, i};
      map[nums[i]] = i;
    }
  }
};

//利用unordered_map
//巧妙地使用map中的find
// auto
// p->second是比较小的,因为从0开始添加到map
