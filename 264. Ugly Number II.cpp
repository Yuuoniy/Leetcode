/*
* @Author: Yuuoniy
* @Date:   2017-11-06 17:32:20
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-06 17:41:17
*/
class Solution {
 public:
  int nthUglyNumber(int n) {
    vector<int> resluts(1, 1);
    int i = 0, j = 0, k = 0;
    while (resluts.size() < n) {
      resluts.push_back(
          min(resluts[i] * 2, min(resluts[j] * 3, resluts[k] * 5)));
      if (resluts.back() == resluts[i] * 2) ++i;
      if (resluts.back() == resluts[j] * 3) ++j;
      if (resluts.back() == resluts[k] * 5) ++k;
    }
    return resluts.back();
  }
};
//相当于合并三个子列表 每次找最小的
