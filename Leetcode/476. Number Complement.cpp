/*
* @Author: Yuuoniy
* @Date:   2017-10-25 19:38:02
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-25 19:46:08
*/
class Solution {
 public:
  int findComplement(int num) {
    unsigned mask = ~0;
    while (num & mask) mask <<= 1;
    return ~mask & ~num;
  }
};
//创建掩码
//移位
