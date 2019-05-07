/*
 * @Author: yuuoniy 
 * @Date: 2019-05-07 13:52:01 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-07 14:06:04
 */
//栈

#include <cstdio>
#include <stack>
using namespace std;

const int MAX_N = 1005;
int n, target[MAX_N];

int main(){
  while(scanf("%d",&n)==1&&n){
    while(true){
      /* code */
      stack<int> s;
      int A = 1, B = 1;
      bool end = 0;
      for(int i = 1; i <=n; i++)
      {
        scanf("%d",&target[i]);
        if(!target[i]){
          end = 1;
          break;
        }
      }
      if(end) {
        printf("\n");
        break;
      }
      int ok = 1;
      while(B<=n){
        if(A==target[B]){
          ++A;
          ++B;
        }else if(!s.empty()&&s.top()==target[B]) {
          s.pop();
          B++;
        }else if(A<=n) s.push(A++);
        else{
          ok = 0;
          break;
        }
      }
      printf("%s\n",ok?"Yes":"No");
    }
    
  }
  return 0;
  
}
