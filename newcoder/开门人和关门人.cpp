/*
 * @Author: yuuoniy
 * @Date: 2019-06-17 21:09:00
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-17 21:16:47
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct student {
  string name;
  string come;
  string to;
};

bool cmp1(student a, student b) { return a.come < b.come; }

bool cmp2(student a, student b) { return a.to > b.to; }

int main() {
  int n;
  vector<student> v;
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      student a;
      cin >> a.name >> a.come >> a.to;
      v.push_back(a);
    }
    sort(v.begin(), v.end(), cmp1);
    cout << v[0].name;

    sort(v.begin(), v.end(), cmp2);
    cout << " " << v[0].name << endl;
  }
  return 0;
}
