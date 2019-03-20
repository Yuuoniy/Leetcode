/*
* @Author: Yuuoniy
* @Date:   2017-10-28 11:20:00
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-28 11:34:14
*/
class Solution {
 public:
  vector<string> readBinaryWatch(int num) {
    vector<string> rs;
    for (int h = 0; h < 12; ++h) {
      for (int m = 0; m < 60; ++m) {
        if (bitset<10>(h << 6 | m).count() == num)
          rs.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
      }
    }
    return rs;
  }
};

//遍历每一种可能 然后  添加符合条件的情况
//将时针部分和分针部分分开 (通过移位) 才能正确地算出1的总数
//使用 emplace_back 代替 push_back
