/*
* @Author: Yuuoniy
* @Date:   2017-11-09 19:46:35
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-09 19:59:21
*/
class Solution {
 public:
  string reverseVowels(string s) {
    if (s.size() == 0) return s;
    string vowels = "aeiouAEIOU";
    string res(s);
    int front = 0, back = s.size() - 1;
    while (front < back) {
      while (front < back && vowels.find(s[front]) == string::npos) {
        ++front;
      }
      while (front < back && vowels.find(s[back]) == string::npos) {
        --back;
      }
      char tmp = res[front];
      res[front] = res[back];
      res[back] = tmp;
      ++front;
      --back;
    }
    return res;
  }
};
//双指针
//分清楚++和--
