/*
 * @Author: yuuoniy 
 * @Date: 2019-07-10 23:26:07 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-07-10 23:30:55
 */

#include <iostream>
#include <algorithm>

using namespace std;

int m[105][105];

int par[105];
int n;

struct edge{
  int u,v,cost;
};

bool cmp(const edge& e1,const edge& e2){
  return e1.cost < e2.cost;
}

edge E[100*100/2];

void init(int n){
  for (int i = 0; i <=n; i++)
  {
    par[i] = i;
  }
  
}

int find(int n){
  return par[n]==n?n:find(par[n]);
}

void unite(int x,int y){
  x = find(x);
  y = find(y);
  par[y] = x;
}

int solve(){
  sort(E,E+n*(n-1)/2,cmp);
  init(n);
  int res = 0;
  for (int i = 0; i < n*(n-1)/2; i++)
  {
    edge e= E[i];
    if(find(e.u)!=find(e.v)){
      unite(e.u,e.v);
      res+= e.cost;
    }
  }
  return res;
}

int main(){
  while (scanf("%d",&n)&&n!=0)
  {
    for (int i = 0; i < n*(n-1)/2; i++)
    {
      scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].cost);
    }
    printf("%d\n",solve());
  }
  return 0;
}
