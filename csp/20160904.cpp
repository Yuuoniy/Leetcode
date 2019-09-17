#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

//https://blog.csdn.net/moilk_nepho/article/details/52950546 
// 本质上是最短路径，但是是记录花费
using namespace std;
const int inf = 0x3f3f3f3f;


struct edge{
  int v;
  int cost;
  edge(int x,int c):v(x),cost(c){};
  bool operator<(const edge& a)const{ return cost>a.cost;};
};
vector<edge> vg[10005];

int n,m;

int main(){
 cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int x,y,w;
    cin >> x >> y >> w;
    --x;
    --y;
    vg[x].push_back(edge(y,w));
    vg[y].push_back(edge(x,w));
  }
  
  priority_queue<edge> pq;
  vector<int> dist(n,inf);
  vector<int> cost(n,inf);
  vector<bool> visit(n,0);
  pq.push(edge(0,0));
  dist[0] = cost[0] = 0;
  while (!pq.empty())
  {
    edge t = pq.top();
    pq.pop();
    visit[t.v] = 1;
    for (int i = 0; i < vg[t.v].size(); i++)
    {
      edge e = vg[t.v][i];
      if(visit[e.v]) continue;
      if(dist[e.v]>dist[t.v]+e.cost){
        dist[e.v] = dist[t.v]+e.cost;
        cost[e.v] = e.cost;
        pq.push(edge(e.v,dist[e.v]));
      }else if(dist[e.v]==dist[t.v]+e.cost){
        cost[e.v] = min(cost[e.v],e.cost);
      }
    }
    
  }
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum+=cost[i];
  }
  printf("%d\n",sum);
  return 0;


}
