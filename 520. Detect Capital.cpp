/*
* @Author: Yuuoniy
* @Date:   2017-10-25 21:22:24
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-25 21:57:04
*/
// Solution 1：
class Solution {
 public:
  bool detectCapitalUse(string word) {
    if (word.size() <= 1) return true;
    if (word[0] >= 'A' && word[0] <= 'Z') {    //第一个字母大写
      if (word[1] >= 'A' && word[1] <= 'Z') {  //第二个为大写
        for (int i = 2; i < word.size(); i++) {
          if (word[i] >= 'a' && word[i] <= 'z') return false;
        }
      } else {  //第二个为小写则后面的都应该为小写
        for (int i = 2; i < word.size(); i++) {
          if (word[i] >= 'A' && word[i] <= 'Z') return false;
        }
      }
    } else if (islower(word[0])) {  //第一个字母为小写
      for (int i = 1; i < word.size(); i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') return false;
      }
    }
    return true;
  }
};

// Solution 2:
class Solution {
 public:
  bool detectCapitalUse(string word) {
    int size = word.size(), count = 0;
    if (size <= 1) return true;
    for (int i = 1; i < size; ++i) {
      if (word[i] >= 'a' && word[i] <= 'z')
        count++;
      else
        count += 2;
    }
    if (count == size - 1) return true;
    if ((count == (size - 1) * 2) && word[0] >= 'A' && word[0] <= 'Z')
      return true;
    return false; 
  }
};

//分析两种情况的相同部分
