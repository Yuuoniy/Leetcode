/*
 * @Author: yuuoniy
 * @Date: 2019-06-17 23:37:58
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-17 23:48:12
 */

// 跟计算后缀表达式一样的
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n, i, a, b, t;
  stack<int> ret;
  while (cin >> n && n != 0) {
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    for (int i = n - 1; i >= 0; i--) {
      if (v[i].compare("+") == 0) {
        a = ret.top();
        ret.pop();
        b = ret.top();
        ret.pop();
        ret.push(a + b);
      } else if (v[i].compare("-") == 0) {
        a = ret.top();
        ret.pop();
        b = ret.top();
        ret.pop();
        ret.push(a - b);
      } else if (v[i].compare("/") == 0) {
        a = ret.top();
        ret.pop();
        b = ret.top();
        ret.pop();
        ret.push(a / b);
      } else if (v[i].compare("*") == 0) {
        a = ret.top();
        ret.pop();
        b = ret.top();
        ret.pop();
        ret.push(a * b);
      }
      else {
        ret.push(atoi(v[i].c_str()));
      }
    }
    cout << ret.top() << endl;
    v.clear();
    while (!ret.empty()) {
      ret.pop();
    }
  }
  return 0;
}
