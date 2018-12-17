/*
* @Author: Yuuoniy
* @Date:   2017-10-24 20:58:22
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-24 21:35:27
*/

class Solution {
 public:
  vector<string> findWords(vector<string>& words) {
    string str1 = "qwertyuiopQWERTYUIOP";
    string str2 = "asdfghjklASDFGHJKL";
    string str3 = "zxcvbnmZXCVBNM";
    int flag = 0;
    bool same = true;
    vector<string> res;
    for (auto str : words) {
      flag = 0;
      same = true;
      if (str1.find(str[0]) != string::npos)
        flag = 1;
      else if (str2.find(str[0]) != string::npos)
        flag = 2;
      else
        flag = 3;
      for (int i = 1; i < str.size(); ++i) {
        if (flag == 1) {
          if (str1.find(str[i]) == string::npos) {
            same = false;
            break;
          }
        } else if (flag == 2) {
          if (str2.find(str[i]) == string::npos) {
            same = false;
            break;
          }
        } else {
          if (str3.find(str[i]) == string::npos) {
            same = false;
            break;
          }
        }
      }

      if (same) res.push_back(str);
    }
    return res;
  }
};
