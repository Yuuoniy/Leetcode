/*
* @Author: Yuuoniy
* @Date:   2017-10-24 08:37:37
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-24 09:34:23
*/
//使用标记
//四个方向遍历 使用递归 注意条件

class Solution {
 public:
  vector<vector<bool>> seen;
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0, n = grid.size(), m = grid[0].size();
    vector<vector<int>> seen(n, vector<int>(m, 0));
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        maxArea = max(maxArea, area(seen, grid, i, j));
      }
    }
    return maxArea;
  }
  int area(vector<vector<int>>& seen, vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
        seen[i][j] || grid[i][j] == 0)
      return 0;
    seen[i][j] = true;
    return (1 + area(seen, grid, i - 1, j) + area(seen, grid, i + 1, j) +
            area(seen, grid, i, j - 1) + area(seen, grid, i, j + 1));
  }
};
