/*
* @Author: Yuuoniy
* @Date:   2017-10-25 20:41:39
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-25 20:45:06
*/
class Solution {
 public:
  bool isPerfectSquare(int num) {
    return (int)sqrt(num) * (int)sqrt(num) == num;
  }
};
