/*
* @Author: Yuuoniy
* @Date:   2017-11-06 11:15:32
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-06 15:15:16
*/
int guess(int num);

class Solution {
 public:
  int guessNumber(int n) {
    int left = 1, right = n;
    while (true) {
      int mid = (right - left) / 2 + left;
      int res = guess(mid);
      if (res == 0) {
        return mid;
      } else if (res == 1) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
};
