#include <cstdio>
#include <cstring>

const int MAX_N = 100005;
int last, cur ,next[MAX_N];

char s[MAX_N];

int main(){
  while(scanf("%s",s+1)==1){
    int n = strlen(s+1);
    last = cur = 0;
    next[0] = 0;//虚拟节点
    for(int i = 1; i <=n; i++)
    {
      char ch = s[i];
      if(ch=='[') cur = 0;
      else if(ch==']') cur = last;
      else{
        next[i] = next[cur];
        next[cur] = i;
        if(cur==last) last=i;
        cur = i;
      }
    }
    for(int i = next[0]; i; i=next[i])
    {
      printf("%c",s[i]);
    }
    printf("\n");
    
  }
  return 0;

}
