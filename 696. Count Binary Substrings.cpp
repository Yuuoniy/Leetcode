/*
* @Author: Yuuoniy
* @Date:   2017-10-25 19:50:35
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-25 20:17:28
*/
class Solution {
 public:
  int countBinarySubstrings(string s) {
    vector<int> rec;
    int count = 1, res = 0;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == s[i - 1]) {
        ++count;
      } else {
        rec.push_back(count);
        count = 1;  //重新计数
      }
    }
    rec.push_back(count);  // push末尾的数列

    for (int i = 1; i < rec.size(); ++i) {
      res += min(rec[i], rec[i - 1]);
    }
    return res;
  }
};

//先统计同一字符连续出现的个数
// 转化题意
//不要忽略最后的部分
