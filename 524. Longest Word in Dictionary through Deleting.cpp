
class Solution {
 public:
  string findLongestWord(string s, vector<string>& d) {
    string ans;
    for (auto str : d) {
      int i = 0, k = 0;
      while (i < s.size() && k < str.size()) {
        if (s[i] == str[k]) {
          ++i;
          ++k;
        } else
          ++i;
      }
      if (k == str.size() &&
          ((ans.size() == str.size() && ans > str) || ans.size() < str.size()))
        ans = str;
    }
    return ans;
  }
};
