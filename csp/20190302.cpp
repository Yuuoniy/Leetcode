/*
 * @Author: yuuoniy 
 * @Date: 2019-05-07 21:43:59 
 * @Last Modified by:   yuuoniy 
 * @Last Modified time: 2019-05-07 21:43:59 
 */
//中缀表达式转后缀表达式
// 后缀表达式求值
#include <iostream>
#include <stack>

using namespace std;

int solve(string s){
  stack<int> t;
  for (int i = 0; i < s.length(); i++)
  {
    if(s[i]<='9'&&s[i]>'0'){
      t.push(s[i]-'0');
    }else{
      int x,y;
      x = t.top(),t.pop();
      y = t.top(),t.pop();
      if(s[i]=='+')
        y+=x;
      else if(s[i]=='-')
        y-=x;
      else if(s[i]=='x')
        y*=x;
      else {
        
        y/=x;
      }
      t.push(y);
    }
  }
  return t.top();
}

string trans_to_back(string s){
  stack<char> t;
  string ss;
  for (int i = 0; i < s.length(); i++)
  {
    if(s[i]<='9'&&s[i]>'0')
      ss+=s[i];
    else if(s[i]=='+'||s[i]=='-'){
      while (!t.empty())
      {
        ss +=t.top();
        t.pop();
      }
      t.push(s[i]);
    }else {
      while (!t.empty())
      {
        if(t.top()=='x'||t.top()=='/'){
           ss +=t.top();
          t.pop();
        }else{
          break;
        }
      }
      t.push(s[i]);
    }
  }
  while (!t.empty())
  {
    ss+=t.top();
    t.pop();
  }
  return ss;
}

int main(){
  int n;
  cin >> n;
  string s;
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    string back_s = trans_to_back(s); //中缀转后缀
    // cout << back_s << endl;
    int res = solve(back_s); //求解
    if(res==24) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
