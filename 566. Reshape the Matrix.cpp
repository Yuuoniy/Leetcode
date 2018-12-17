/*
* @Author: Yuuoniy
* @Date:   2017-10-23 22:23:25
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-24 09:18:10
*/
class Solution {
 public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    int m = nums.size(), n = nums[0].size(), o = m * n;
    if (o != r * c) return nums;
    vector<vector<int>> res(r, vector<int>(c, 0));
    for (int i = 0; i < o; ++i) {
      res[i / c][i % c] = nums[i / n][i % n];
    }
    return res;
  }
};
//学会定义并初始化二维vector
//利用/ 和%
// 搞清楚两个下标对应的意思！
