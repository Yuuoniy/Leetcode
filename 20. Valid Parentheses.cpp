/*
* @Author: Yuuoniy
* @Date:   2017-11-23 10:08:57
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-23 10:31:29
*/
class Solution {
 public:
  bool isValid(string s) {
    stack<char> sta;
    for (char c : s) {
      switch (c) {
        case '(':
        case '{':
        case '[':
          sta.push(c);
          break;
        case ')':
          if (sta.empty() || sta.top() != '(')
            return false;
          else
            sta.pop();
          break;
        case '}':
          if (sta.empty() || sta.top() != '{')
            return false;
          else
            sta.pop();
          break;
        case ']':
          if (sta.empty() || sta.top() != '[')
            return false;
          else
            sta.pop();
          break;
      }
    }
    return sta.empty();
  }
};
