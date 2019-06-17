/*
 * @Author: yuuoniy
 * @Date: 2019-06-16 15:15:22
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-16 15:26:33
 */

#include <iostream>
#include <map>
#include <string>

using namespace std;

struct stu {
  string no, name, sex;
  int age;
} students[1005];

map<string, stu> info;

int main() {
  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> students[i].no >> students[i].name >> students[i].sex >>
        students[i].age;
    info[students[i].no] = students[i];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    string str;
    cin >> str;
    if (info.find(str) == info.end())
      cout << "No Answer!" << endl;
    else {
      stu node = info[str];
      cout << node.no << " " << node.name << " " << node.sex << " " << node.age
           << endl;
    }
  }
  return 0;
}
