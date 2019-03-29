#include <bits/stdc++.h>
#include <ctype.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
int daysofmonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string months[] = {"jan", "feb", "mar", "apr", "may", "jun",
                   "jul", "aug", "sep", "oct", "nov", "dec"};
string weeks[] = {"sun", "mon", "tue", "wed", "thu", "fri", "sat"};
int timeRange[5] = {60, 24, 31, 12, 7};
vector<pair<long long, int> > ans;
map<string, int> maps;  
int startYear, endYear; 

int init() {
  for (int i = 0; i < 12; i++) 
  {
    maps[months[i]] = i + 1;
  }
  for (int i = 0; i < 8; i++) {
    maps[weeks[i]] = i;
  }
}

int strToInt(string &str) {
  if (isalpha(str[0])) 
    return maps[str];
  int ans;
   stringstream ss(str);
     ss>>ans;
    return ans;
}


void handleMinus(set<long long> &validTime, string &cons) {
  for (int i = 0; i < cons.length(); i++) {
    cons[i] = tolower(cons[i]);
  }
  int k = cons.find('-');
  if (k == string::npos) {
    validTime.insert(strToInt(cons));
  } else {
    string start = cons.substr(0, k), end = cons.substr(k + 1);
    int startTime = strToInt(start), endTime = strToInt(end);
    for (int i = startTime; i <= endTime; i++) {
      validTime.insert(i);
    }
  }
}

//分析匹配的条件，生成符合的时间存入 set 中，自动去除重复了，j
//用来标记是哪个尺度的时间
void findValueByContraint(set<long long> &validTime, string &constraint,
                          int j) {
  if (constraint == "*")
  {
    for (int i = 0; i < timeRange[j]; i++) {
      if (j == 2 || j ==3) 
        validTime.insert(i + 1);
      else {
        validTime.insert(i);
      }
    }
  } else {
    int start = 0;
    int k = constraint.find(',');
    string str;
    while (start < constraint.length()) {
      if (k != -1) {
        str = constraint.substr(start, k - start);
        handleMinus(validTime, str);
      } else {
        str = constraint.substr(start);
        handleMinus(validTime, str);
        break;
      }

      start = k + 1;
      k = constraint.find(',', start);
    }
  }
}

//判断是否是闰年

bool isleapYear(int year) {
  return (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
}


int weekday(int year, int month, int day) {
   if(month==1||month==2) 
    {
        month+=12;
        year--;
    }
    int Week=(day+2*month+3*(month+1)/5+year+year/4-year/100+year/400)%7;
    return (Week+1)%7;
}

void fillVector(vector<vector<long long> > &v, vector<long long> &tmp, int j,
                long long factor) {
  if (j == 0) 
    v[j] = tmp;
  else {
    vector<long long> &pre = v[j - 1]; 
    if (j != 4) { 
      for (int k = 0; k < tmp.size(); k++) {
        for (int i = 0; i < pre.size(); i++) {
          v[j].push_back(tmp[k] * factor + pre[i]);
        }
      }
    } else { 
      int judge[7] = {0};
      for (int k = 0; k < tmp.size(); k++) { 
        judge[tmp[k]] = 1;
      }
      for (int l = 0; l < pre.size(); l++) {
        int month = pre[l] / 1000000, day = pre[l] / 10000 % 100;
        if (day > daysofmonth[month])
          continue;
        for (int year = startYear; year <= endYear; year++) {
          int dayofweek = weekday(year, month, day);
          if (judge[dayofweek]) {
            v[4].push_back(year * factor + pre[l]);
          }
        }
      }
    }
  }
}

int main() {
  int n=0;
  long long s=0, t=0;
  cin>>  n >> s >> t;

  startYear = s / 100000000, endYear = t / 100000000;
  vector<vector<string> > crontab(n, vector<string>(6));
  init();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 6; j++) {
      cin >> crontab[i][j];
    }
  }

  for (int i = 0; i < n; i++) {     //遍历每条 crontab 命令
    vector<vector<long long> > v(5); //存储推出来的时间
    long long factor = 1;
    for (int j = 0; j < 5; j++) 
    {
      set<long long> validTime;
      findValueByContraint(validTime, crontab[i][j], j);
      vector<long long> tmp; //存储本轮算出来的有效时间
      //  for(set<LL>::iterator it = valid.begin(); it != valid.end(); ++it){
      //               tmp.push_back(*it);
      //           }
      tmp.assign(validTime.begin(), validTime.end());
      fillVector(v, tmp, j, factor);
      factor *= 100;
    }

    for (int j = 0; j < v[4].size(); ++j) { //将生成时间添加用于最后判断和输出
      ans.push_back(make_pair(v[4][j], i));
    }
  }
  sort(ans.begin(),
      ans.end()); //这样第一个项相同的话，可以使用第二个项排序，也就是按顺序命令输出了
  for (vector<pair<long long, int> >::iterator it = ans.begin(); it != ans.end();
       ++it) {
    if (it->first >= s && it->first < t) {
      cout << it->first << " " << crontab[it->second][5] << endl;
    }
  }
  return 0;
}
