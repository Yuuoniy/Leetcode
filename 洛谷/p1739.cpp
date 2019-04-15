#include <iostream>
#include <stack>

using namespace std;

int main(){
  char tmp;
  stack<char> ops;
  while(scanf("%c",&tmp)&&tmp!='@'){
    if(tmp=='('){
      ops.push('(');
      // cout << "push (" << endl;
  }else if(tmp==')'){
    if(ops.empty()){
      cout << "NO" << endl;
      return 0;
    }
      ops.pop();
      // cout << " pop ) " << endl;
    }
  }
  if(ops.empty())
    cout << "YES" << endl;
  else 
    cout << "NO" << endl;
  return 0;
}
