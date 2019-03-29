/*
 * @Author: yuuoniy
 * @Date: 2019-03-21 18:58:51
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-03-21 22:03:12
 */
// 思路：
// 定义结构体：level,name,id
// level = dotCount/2
// 元素名称统一处理成小写
// 1. 处理输入：对于每行输入，转换为对应的结构体
// 2. 树的结构：对于每一个结点，找到前驱结点，即向上找到 level 为当前 level-1
// 的元素
// 3. 查询：如果只有一个单词，遍历结构体寻找，如果有多个的单词，从上往下找。
// 后代选择器：先找到所有满足最后一个选择器的元素列表，然后遍历这些元素，
// 如果存在父级元素满足条件则继续搜索，否则说明这个元素不匹配选择器，将其移除。最后剩下的元素就是答案。

// query 部分参考别人的题解，不过我觉得还是有问题的,因为没有考虑查询的顺序
// 可能要递归吧，有机会再改了.. 
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct Node {
  int level;
  string label;
  string id;
} nodes[105];

map<string, int> an,
    toQuery; // an表示各个祖先含有的标签，id属性等，query表示要查询的

// strs to struct
void process(string str, int idx) {
  int count = 0;
  while (count < str.length() && str[count] == '.') {
    ++count;
  }
  int level = count / 2;
  string label, id;
  int k = str.find(' ', count + 1);
  if (k == -1) { //说明后面没有 id
    label = str.substr(count, str.length() - count);
    id = "";
  } else {
    label = str.substr(count, k - count);
    id = str.substr(k + 1, str.length() - k - 1);
  }
  nodes[idx].level = level;
  nodes[idx].id = id;
  nodes[idx].label = label;
}

// process query string,split query string into parts by spaces

vector<string> split_query(string query) {

  int start = 0;
  int k = query.find(' ', start + 1);
  vector<string> res;
  while (start < query.length()) {
    if (k == -1) {
      k = query.length();
    }
    string tmp = query.substr(start, k - start);
    res.push_back(tmp);
    start = k + 1;
    k = query.find(' ', start + 1);
  }
  return res;
}

string to_lower(string str) {
  for (int i = 0; i < str.length(); i++) {
    str[i] = tolower(str[i]);
  }
  return str;
}

void queryElement(vector<string> &query, int n) {
  // cout<< "query element" << endl;
  vector<int> ans;
  if (query.size() == 1) { //不是后代选择器
    if (query[0][0] != '#') {
      query[0] = to_lower(query[0]);
    }
    //查找进行匹配
    for (int i = 0; i < n; i++) {
      if (query[0] == nodes[i].label || query[0] == nodes[i].id) {
        ans.push_back(i);
      }
    }
  } else {
    toQuery.clear();
    for (int i = 0; i < query.size(); i++) {
      if (query[i][0] != '#') {
        query[i] = to_lower(query[i]);
      }
      toQuery[query[i]]++;
    }
    string q = query.back(); //从后往前查询
    if (q[0] != '#') {
      q = to_lower(q);
    }
    for (int i = 0; i < n; i++) //遍历各个节点
    {
      if (q == nodes[i].label || q == nodes[i].id) {
        an.clear(); //清空之前的结果
        for (int j = i - 1; j >= 0 && nodes[j].level <= nodes[i].level;
             j--) { //往上查找指针
          if (nodes[j].level == nodes[i].level)
            continue;
          an[nodes[j].label]++;
          if (nodes[j].id != "")
            an[nodes[j].id]++;
        }
        bool flag = true;
        //遍历查询的所有id选择器和标签选择器
        for (map<string, int>::iterator it = toQuery.begin();
             it != toQuery.end(); it++) {
          if (an.count(it->first) == 0 || an[it->first] < it->second) {
            flag = false;
            break;
          }
          // cout << it->first << " " << it->second << endl;
        }
        if (flag) {
          ans.push_back(i);
        }
      }
    }
  }
  printf("%d", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf(" %d", ans[i] + 1); //从1开始记录行号的
  printf("\n");
}

int main() {
  int n, m;
  cin >> n >> m;
  string tmp;
  getchar(); //读取回车
  for (int i = 0; i < n; i++) {
    getline(cin, tmp);
    // cout << tmp << endl;
    process(tmp, i);
  }
  string query;
  vector<string> splitQuery;
  for (int i = 0; i < m; i++) {

    getline(cin, query);
    // cout << "query" << query << endl;
    splitQuery.clear();
    splitQuery = split_query(query);
    // cout << "query size" << splitQuery.size() << endl;
    // cout << "after split query "<< endl;
    queryElement(splitQuery, n);
  }
  return 0;
}
