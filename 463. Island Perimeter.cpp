/*
* @Author: Yuuoniy
* @Date:   2017-10-26 17:30:49
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-26 18:35:17
*/
class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int count = 0, repeat = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) {
          ++count;
          if (i > 0 && grid[i - 1][j] == 1)  //前提是i j处要为1 ！！这样才是相邻
            ++repeat;  //每一个只需要考虑左下 避免冲服(重复)
          if (j > 0 && grid[i][j - 1] == 1)
            ++repeat;  //也可以考虑右下保证i+1 j+1小于对应的size}
        }
      }
    }
      return (count * 4) - (repeat * 2);
    }
  };
