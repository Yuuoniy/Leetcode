#include <stdio.h>

const int MAXN = 30005;
int par[MAXN];

void init(int n){
  for(int i = 0; i < n; i++)
  {
    par[i] = i;
  }
}

int find(int x){
  return x==par[x]?x:par[x]=find(par[x]);
}

void unite(int x,int y){
  x = find(x);
  y = find(y);
  if(x==y)
    return;
  else 
    par[x] = y;
}

int main(){
  int n,m;
  while(scanf("%d%d",&n,&m)!=EOF){
    if (n==0&&m==0) {
      break;
    }
    init(n);
    int groupNum,x,y;
    for(int i = 0; i < m; i++)
    {
      scanf("%d%d",&groupNum,&x);
      for(int j = 0; j < groupNum-1; j++)
      {
        scanf("%d",&y);
        unite(x,y);
      }
      
    }
    int ans = 1; //编号为 0 的学生
    for(int k = 1; k < n; k++)
    {
      if(find(k)==find(0)) ++ans;
    }
    printf("%d\n",ans);
     
  }
  return 0;
  
}
