/*
* @Author: Yuuoniy
* @Date:   2017-11-06 10:15:24
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-06 10:40:18
*/
class Solution {
 public:
  string reverseWords(string s) {
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != ' ') {
        int j = i;
        while (j < s.size() && s[j] != ' ') {  //找到空格处
          ++j;
        }
        reverse(s.begin() + i, s.begin() + j);
        i = j - 1;
      }
    }
    return s;
  }
};
//  Reverses the order of the elements in the range [first, last)
