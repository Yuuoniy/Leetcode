/*
* @Author: Yuuoniy
* @Date:   2017-10-28 16:11:07
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-28 16:14:27
*/
class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0;
    for (int j = 0; i < g.size() && j < s.size(); ++j) {
      if (g[i] <= s[j]) ++i;
    }
    return i;
  }
};

//贪心算法 先从最小的开始
