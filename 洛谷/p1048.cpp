#include <iostream>
#include <memory.h>
#include <stdio.h>
using namespace std;


int mem[105][1005];
int t,m;
int times[105],val[105];

int dfs(int pos, int left){
  if(mem[pos][left]!=-1) return mem[pos][left];
  if(pos==m)
    return mem[pos][left]=0;
  if(left>=times[pos])
    return mem[pos][left] = max(dfs(pos+1,left),dfs(pos+1,left-times[pos])+val[pos]);
  else 
    return mem[pos][left] = dfs(pos+1,left);
}


int main(){
  scanf("%d %d",&t,&m);
  for(int i = 0; i < m; i++)
  {
   scanf("%d %d",&times[i],&val[i]);
  }
  memset(mem,-1,sizeof(mem));

  printf("%d\n",dfs(0,t));
  
}
