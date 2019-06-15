// 坑点在于： i 匹配 *i* 是不对，需要匹配完整的单词。
// 大小写转化

#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string word;
  string str;
  // cin >> word;
  getline(cin, word);
  cin.clear();
  getline(cin, str);
  for (int i = 0; i < word.length(); i++) {
    word[i] = tolower(word[i]);
  }
  for (int i = 0; i < str.length(); i++) {
    str[i] = tolower(str[i]);
  }
  str += " ";
  int flag, pos = 0, total = 0, first = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == ' ') {
      flag = 1;
      for (int j = pos, k = 0; j < i, k < word.length(); j++, k++) {
        if (str[j] != word[k]) {
          flag = 0;
          break;
        }
      }
      if (flag)
        ++total;
      if (total == 1 && flag) {
        first = pos;
      }
      pos = i;
      ++pos;
    }
  }
  if (total == 0) {
    printf("-1");
  } else if (total >= 1) {
    printf("%d %d", total, first);
  }
  return 0;
}
