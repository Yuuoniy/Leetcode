/*
 * @Author: yuuoniy
 * @Date: 2019-08-21 20:24:51
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-08-21 20:26:47
 */
/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */
class Solution {
public:
  int maxArea = 0;
  int ans = 0;
  int n = 0;
  int m = 0;
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    if (grid.size() == 0)
      return 0;
    n = grid.size();
    m = grid[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          ans = 0;
          dfs(i, j, grid);
          maxArea = max(ans, maxArea);
        }
      }
    }
    return maxArea;
  }

  void dfs(int x, int y, vector<vector<int>> &grid) {
    if (grid[x][y] == 0)
      return;
    grid[x][y] = 0;
    ans++;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] == 1)
        dfs(xx, yy, grid);
    }
  }
};
