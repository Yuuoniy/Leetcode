/*
 * @Author: yuuoniy
 * @Date: 2019-06-16 00:38:28
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-16 00:50:46
 */

//入栈时访问 = 前序， 出栈时访问 = 中序
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  string pre;
  while (cin >> pre) {
    stack<char> s;
    for (auto it : pre) {
      if (it != '#')
        s.push(it);
      else {
        if (!s.empty()) {
          cout << s.top() << ' ';
          s.pop();
        }
      }
    }
    cout << endl;
  }
}
