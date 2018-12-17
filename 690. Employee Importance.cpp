/*
* @Author: Yuuoniy
* @Date:   2017-10-26 22:04:44
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-26 22:24:59
*/
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
 public:
  int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int, Employee*> map;
    for (const auto element : employees) {
      map[element->id] = element;
    }
    return help(map, id);
  }

  int help(unordered_map<int, Employee*>& map, const int id) {
    auto sum = map[id]->importance;
    for (const auto element : map[id]->subordinates) {
      sum += help(map, element);
    }
    return sum;
  }
};
//使用递归
