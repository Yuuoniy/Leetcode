/*
 * @Author: yuuoniy 
 * @Date: 2019-05-11 17:22:26 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-11 19:28:59
 */
// 注意有空格，要用 getline
// find 可以查找字符串，返回初始位置
// map 的使用
// replace 函数的使用
// getline ,getchar 三目表达式
// 只有80分，哪里错了。。 因为替换 "" 的话，长度变了！！，然后会找不到下一个 email.. 所以位置的值更新时要注意，但是越改越错是怎么回事。。
// 原来是 pre = pos1+xx 写成 pre+= pos1+xx 了
// 啊。。debug 日益艰难
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
const int MAX_N = 105;

using namespace std;


int m,n;

string text[MAX_N];
map<string,string> varible;

int main(){
  // freopen("a.in","r",stdin);
  cin >> m >> n;
  string res;
  string t;
  getchar();
  for (int i = 0; i < m; i++)
  {
   getline(cin,text[i]);
  }
  //处理变量
  for (int i = 0; i < n; i++)
  {
    getline(cin,t); 
    int pos = t.find('"');
    string key = t.substr(0,pos-1);
    string value = t.substr(pos+1,t.length()-pos-2);
    varible[key] = value;
  }
  //逐行替换变量
  for (int i = 0; i < m; i++)
  {
    int pos1,pos2,pre = 0;
    while (pre<text[i].size())
    {
      pos1 = text[i].find("{{",pre);
      pos2 = text[i].find("}}",pos1);
      if(pos1==string::npos||pos2==string::npos) break;
      t = text[i].substr(pos1+3,pos2-pos1-4);
      text[i].replace(pos1,t.length()+6,varible.count(t)?varible[t]:"");

      pre=pos1+(varible.count(t)?varible[t].length():0);
    }
    cout << text[i] << endl;
  }
  
  return 0;
}
