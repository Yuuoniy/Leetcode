// 如果是path，应该可以匹配后面的全部内容吧??
// 注意 /，/<str>/ /xxx 是无法匹配成功的！，这个问题改正后 40->70
// 只有 70 分，不知道还有什么问题...
#include <iostream>
#include <vector>
using namespace std;

struct match {
  vector<string> path;
  string resource;
} existPath[105];

vector<string> process_path(string path) {
  int start = 1;
  int pos = 0;
  vector<string> splits;
  while (start < path.length()) {
    pos = path.find('/', start);
    string sub;
    if (pos != -1) {
      sub = path.substr(start, pos - start + 1);
      start = pos + 1;
    } else {
      sub = path.substr(start, path.length() - start);
      start = path.length();
      // 获取最后一部分
    }
    // cout << "split part: " << sub << " ";
    splits.push_back(sub);
  }

  return splits;
}

void query_path(vector<string> &split_query, int n) {
  //规则从上到下进行匹配
  vector<string> params;
  string tmp_params;
  for (int i = 0; i < n; i++) {
    params.clear();
    bool match_flag = false;
    bool isPath = false;
    if (existPath[i].path.size() > split_query.size())
      continue;
    // if(existPath[i].path.size()<split_query.size()&&existPath[i].path[existPath[i].path.size()-1]!="<path>")
    //   continue;
    for (int j = 0; j < split_query.size(); j++) // 对于每个查询部分逐个匹配
    {
      match_flag = false;
      string a, b;
      if (existPath[i].path.size() <= j)
        break;
      a = existPath[i].path[j];
      b = split_query[j];
      if (a == b)
        match_flag = true;
      else if (a == "<str>" || a == "<str>/") {
        if (a[a.length() - 1] == '/') {
          if (b[b.length() - 1] != '/')
            break;
          else
            b = b.substr(0, b.length() - 1);
        }
        if (b.size() == 0) //空字符串
          break;
        params.push_back(b);
        match_flag = true;
      } else if (a == "<int>" || a == "<int>/") {
        //判断是否为 int,并且参数要去掉前导0
        if (a[a.length() - 1] == '/') {
          if (b[b.length() - 1] != '/')
            break;
          else
            b = b.substr(0, b.length() - 1);
        }
        if (b.size() == 0) //空字符串
          break;
        bool isInt = true;
        for (int i = 0; i < b.length(); i++) {
          if (b[i] < '0' || b[i] > '9') //如果有不是整数的
          {
            isInt = false;
            break;
          }
        }
        if (!isInt)
          break;
        //是整数
        match_flag = true;
        int pos = 0;
        while (b[pos] == '0' && pos < b.length()) {
          ++pos;
        }
        if (pos < b.length())
          tmp_params = b.substr(pos, b.length() - pos);
        else
          tmp_params = "0";
        params.push_back(tmp_params);
      } else if (a == "<path>") {
        isPath = true;
        match_flag = true;
        tmp_params =b;
        for (int k = j + 1; k < split_query.size() - 1; k++) {
          tmp_params += split_query[k];
        }
        if (j != split_query.size() - 1) {
          tmp_params += split_query[split_query.size() - 1];
        }
        params.push_back(tmp_params);
      }
      //匹配错误或者最后一个是 path，退出
      if (!match_flag || isPath)
        break;
    }
    //说明匹配成功
    if (match_flag) {
      cout << existPath[i].resource;
      for (int j = 0; j < params.size(); ++j) {
        cout << " " << params[j];
      }
      cout << endl;
      return;
    }
  }
  //
  cout << "404" << endl;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> paths;
  vector<string> resourses;
  string a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    vector<string> path_split = process_path(a);
    existPath[i].path = path_split;
    existPath[i].resource = b;
  }

  // query
  string queryStr;
  for (int i = 0; i < m; i++) {
    cin >> queryStr;
    vector<string> splits = process_path(queryStr);
    query_path(splits, n);
  }
  return 0;
}
