/*
 * @Author: yuuoniy 
 * @Date: 2019-05-07 14:10:20 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-07 14:51:33
 */

//栈解析表达式

#include <cstdio>
#include <stack>
#include <iostream>
#include <string>

using namespace std;

struct matrix
{
  int a,b;
  matrix(int a=0,int b=0):a(a),b(b){}
}m[26];


stack<matrix> s;

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    string name;
    cin >> name;
    int k = name[0]-'A';
    cin >> m[k].a >> m[k].b;
  }
  string expr;
  while(cin >> expr){
    int len = expr.size();
    bool ok = true;
    int ans = 0;
    for(int i = 0; i < len; i++)
    {
      if(isalpha(expr[i])) s.push(m[expr[i]-'A']);
      else if(expr[i]==')'){
        matrix m2 = s.top();s.pop();
        matrix m1 = s.top();s.pop();
        if(m1.b!=m2.a){
          ok = false;
          break;
        }
        ans += m1.a*m1.b*m2.b;
        s.push(matrix(m1.a,m2.b));
      }
    }
    if(ok)
      printf("%d\n",ans);
    else
      printf("error\n");
    
  }
  return 0;
  
  
}
