/*
* @Author: Yuuoniy
* @Date:   2017-10-29 20:00:48
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-29 20:36:14
*/
class Solution {
 public:
  vector<string> findRelativeRanks(vector<int>& nums) {
    map<int, int> mp;
    vector<string> ans(nums.size(), "");
    for (int i = 0; i < nums.size(); ++i) {
      mp[nums[i]] = i;
    }
    int cnt = 1;
    for (map<int, int>::reverse_iterator it = mp.rbegin(); it != mp.rend();
         ++it, ++cnt) {
      if (cnt == 1)
        ans[it->second] = "Gold Medal";
      else if (cnt == 2)
        ans[it->second] = "Silver Medal";
      else if (cnt == 3)
        ans[it->second] = "Bronze Medal";
      else
        ans[it->second] = to_string(cnt);
    }
    return ans;
  }
};

//使用map
//反向迭代器
