/*
* @Author: Yuuoniy
* @Date:   2017-11-05 19:44:36
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-05 20:13:30
*/
// Solution 1:
class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    string str = to_string(x);
    // cout << str;
    int mid = (str.size() % 2 == 0) ? (str.size() / 2) : (str.size() / 2 + 1);
    for (int i = 0, j = str.size() - 1; i < mid; ++i, --j) {
      if (str[i] != str[j]) return false;
    }
    return true;
  }
};

// Solution 2:
class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0 || (x && x % 10 == 0)) return false;  //考虑特殊情况 如1210
    int sum = 0;
    while (x > sum) {
      sum = sum * 10 + x % 10;
      x = x / 10;
    }
    return (x == sum) || (x == sum / 10);
  }
};
