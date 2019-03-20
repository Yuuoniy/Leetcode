
/*
* @Author: Yuuoniy
* @Date:   2017-10-28 10:23:48
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-28 10:33:36
*/
// Solution 1:
class Solution {
 public:
  int distributeCandies(vector<int>& candies) {
    int res = 0;
    unordered_map<int, int> count;
    for (int i = 0; i < candies.size(); ++i) {
      ++count[candies[i]];
    }
    return count.size() >= candies.size() / 2 ? candies.size() / 2
                                              : count.size();
  }
};

// 改进：
class Solution {
 public:
  int distributeCandies(vector<int>& candies) {
    return min(unordered_set<int>(candies.begin(), candies.end()).size(),
               candies.size() / 2);
  }
};
