/*
* @Author: Yuuoniy
* @Date:   2017-10-29 21:04:39
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-29 21:12:29
*/
// Solution 1:
class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n) {
      ans += n & 1;
      n = n >> 1;
    }
    return ans;
  }
};

// Solution 2:
class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
      n &= (n - 1);
      ++count;
    }
    return count;
  }
};
//每一次 n&n-1 都消掉最低位的1
