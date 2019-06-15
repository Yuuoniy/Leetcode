#include <iostream>
#include <algorithm>
using namespace std;
struct edge{
  int u,v,cost;
};

bool cmp(const edge& e1,const edge& e2){
  return e1.cost < e2.cost;
}
const int MAX_M = 200005;
const int MAX_N = 5005;
edge es[MAX_M];
int V,E;
int par[MAX_N];

void init_union_find(int n){
  for(int i = 0; i < n; i++)
  {
    par[i] = i;
  }
}

int find(int x){
  if(par[x]==x) return x;
  else {
    return par[x] = find(par[x]);
  }
}

bool same(int x,int y){
  return find(x)==find(y);
}

void unite(int x,int y){
  x = find(x);
  y = find(y);
  if(x==y) return ;
  else par[x] = y;
}



int kruskal(){
    sort(es,es+E,cmp);
    init_union_find(V);
    int res = 0;
    for(int i = 0; i < E; i++)
    {
      edge e = es[i];
      if(!same(e.u,e.v)){
        unite(e.u,e.v);
        res+=e.cost;
      }
    }
    return res;
}

int main(){
  cin >> V >> E ;
  for(int i = 0; i < E; i++)
  {
      cin >> es[i].u >> es[i].v >> es[i].cost;
  }
  
  int res = kruskal();
  cout << res << endl;
  return  0;
  
}
