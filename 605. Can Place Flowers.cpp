/*
* @Author: Yuuoniy
* @Date:   2017-11-07 18:37:31
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-07 18:37:31
*/
class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    for (int i = 0; i < flowerbed.size(); ++i) {
      if (!flowerbed[i] && (i == 0 || !flowerbed[i - 1]) &&
          (i + 1 == flowerbed.size() || !flowerbed[i + 1])) {
        --n;
        flowerbed[i] = 1;
      }
    }
    return n <= 0;
  }
};
