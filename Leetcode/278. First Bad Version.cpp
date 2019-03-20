/*
* @Author: Yuuoniy
* @Date:   2017-11-06 15:29:28
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-06 15:35:52
*/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    int left = 1, right = n;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (!isBadVersion(mid))
        left = mid + 1;
      else
        right = mid;
    }
    return left;
  }
};
