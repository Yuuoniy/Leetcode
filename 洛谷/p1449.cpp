/*
 * @Author: yuuoniy 
 * @Date: 2019-04-15 12:42:17 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-04-15 12:42:37
 */
//后缀表达式
#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
  string str;
  stack<int> nums;
  char tmp;
  int cur_num = 0;
  while(scanf("%c",&tmp)&&tmp!='@'){
    if(tmp>='0'&&tmp<='9'){
      cur_num*=10;
      cur_num+=tmp-'0';
    }else if(tmp=='.'){
      nums.push(cur_num);
      cur_num = 0;
    }else{
      int a;
      int b;
      b = nums.top();
      nums.pop();
      a = nums.top();
      nums.pop();
      switch (tmp)
      {
        case '+':
         nums.push(a+b);
          break;
        case '-':
          nums.push(a-b);
          break;
        case '*':
          nums.push(a*b);
          break;
        case '/':
          nums.push(a/b);
        default:
          break;
      }
    }
  }
  cout << nums.top() << endl;
  return 0;
}
