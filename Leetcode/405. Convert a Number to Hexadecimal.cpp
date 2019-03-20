/*
* @Author: Yuuoniy
* @Date:   2017-11-07 19:32:29
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-07 19:45:08
*/
string HEX = "0123456789abcdef";
class Solution {
 public:
  string toHex(int num) {
    if (!num) return "0";
    string res;
    int count = 0;
    while (num && count++ < 8) {
      res = HEX[(num & 0xf)] + res;
      num >>= 4;
    }
    return res;
  }
};

//利用数组
//一位十六进制相当于四位二进制
// num&0xf 会获取一个数对应的二进制的后四位
// count++ < 8 防止-1这样的情况？？
