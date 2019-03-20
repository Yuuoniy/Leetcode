/*
* @Author: Yuuoniy
* @Date:   2017-11-04 20:06:44
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-04 20:20:30
*/
class Solution {
 public:
  string countAndSay(int n) {
    if (!n) return "";
    string res = "1";
    while (--n) {
      string cur = "";
      for (int i = 0; i < res.size(); ++i) {
        int count = 1;
        while ((i + 1 < res.size()) && (res[i + 1] == res[i])) {
          ++count;
          ++i;
        }
        cur += to_string(count) + res[i];
      }
      res = cur;
    }
    return res;
  }
};
