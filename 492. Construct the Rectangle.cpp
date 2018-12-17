/*
* @Author: Yuuoniy
* @Date:   2017-10-28 11:05:01
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-28 11:19:51
*/
// Solution 1:
class Solution {
 public:
  vector<int> constructRectangle(int area) {
    int width = sqrt(area), height = sqrt(area);
    while (width * height != area) {
      width* height < area ? ++height : --width;
    }
    return vector<int>({height, width});
  }
};

// 精简版：
class Solution {
 public:
  vector<int> constructRectangle(int area) {
    for (int mid = sqrt(area); mid > 0; --mid) {
      if (!(area % mid)) return {area / mid, mid};
    }
  }
};
