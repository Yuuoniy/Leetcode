#include <stdio.h>
#include <iostream>
using namespace std;
const int MAXN = 2005;
int n;
char s[MAXN];
void solve(){
  int a = 0,b = n-1;
  int count = 0;
  while(a<=b){
    bool left = false;
    for(int i = 0; a+i<=b; i++)
    {
      if(s[a+i]<s[b-i]){
        left = true;
        break;
      }else if(s[a+i]>s[b-i]){
        left = false;
        break;
      }
    }
    if(left) putchar(s[a++]);
    else putchar(s[b--]);
    ++count;
    if((count)%80==0)
      putchar('\n');
  }
  putchar('\n');
  
}

int main(){
  scanf("%d",&n);
  for(int i = 0; i < n; i++)
  {
    getchar();
    scanf("%c",&s[i]);
  }
  
  solve();
  return 0;
}
