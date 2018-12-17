/*
* @Author: Yuuoniy
* @Date:   2017-10-27 21:31:23
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-27 21:57:37
*/
// 1:
class Solution {
 public:
  vector<string> fizzBuzz(int n) {
    vector<string> res;
    stringstream ss;
    for (int i = 1; i <= n; ++i) {
      if (!(i % 3) && !(i % 5))
        res.push_back("FizzBuzz");
      else if (!(i % 3))
        res.push_back("Fizz");
      else if (!(i % 5))
        res.push_back("Buzz");
      else {
        ss.str("");
        ss << i;
        res.push_back(ss.str());
      }
    }
    return res;
  }
};
// 改进版：
class Solution {
 public:
  vector<string> fizzBuzz(int n) {
    vector<string> res(n);
    for (int i = 1; i <= n; ++i) {
      if (i % 3 == 0) res[i - 1] += "Fizz";
      if (i % 5 == 0) res[i - 1] += "Buzz";
      if (res[i - 1].empty()) res[i - 1] += to_string(i);
    }
    return res;
  }
};
