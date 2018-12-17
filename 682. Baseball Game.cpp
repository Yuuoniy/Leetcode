/*
* @Author: Yuuoniy
* @Date:   2017-10-27 21:12:00
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-27 21:29:11
*/
class Solution {
 public:
  int calPoints(vector<string>& ops) {
    int sum = 0, tmp = 0, score;
    stringstream ss;
    vector<int> vaild;
    for (int i = 0; i < ops.size(); ++i) {
      switch (ops[i][0]) {
        case '+':
          tmp = vaild[vaild.size() - 1] + vaild[vaild.size() - 2];
          sum += tmp;
          vaild.push_back(tmp);
          break;
        case 'D':
          tmp = vaild[vaild.size() - 1] * 2;
          sum += tmp;
          vaild.push_back(tmp);
          break;
        case 'C':
          tmp = vaild[vaild.size() - 1];
          sum -= tmp;
          vaild.pop_back();
          break;
        default:
          ss << ops[i];
          ss >> score;
          ss.clear();
          sum += score;
          vaild.push_back(score);
      }
    }
    return sum;
  }
};
