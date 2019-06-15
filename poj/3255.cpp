//无向图 需要添加两遍！
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
struct edge{
  int to,cost;
};
typedef pair<int,int> P;
int N,R;
const int MAX_N = 5005;

vector<edge> G[MAX_N];
int dist[MAX_N];
int dist2[MAX_N];

void solve(){
  priority_queue<P,vector<P>,greater<P>> que;
  for(int i = 0; i < N; i++)
  {
    dist[i] = dist2[i] =2147483647;
  }
  dist[0] = 0;
  que.push(P(0,0));
  while(!que.empty()){
    P p = que.top();
    que.pop();
    int v = p.second,d = p.first;
    // cout << d << endl;
    if(dist2[v]<d) continue;
    for(int i = 0; i < G[v].size(); i++)
    {
      edge& e= G[v][i];
      int d2 = d+e.cost;
      if(dist[e.to]>d2){
        swap(dist[e.to],d2);
        que.push(P(dist[e.to],e.to));
        // cout << " bb " << endl; 
      }
      if(dist2[e.to]>d2&&dist[e.to]<d2){
        // cout << "aa " << endl;
        dist2[e.to] = d2;
        que.push(P(dist2[e.to],e.to));
      }
    }
  }
    printf("%d\n",dist2[N-1]);
  
}

int main(){
  scanf("%d %d",&N,&R);
  for(int i = 0; i < R; i++)
  {
    int s,t,c;
    scanf("%d %d %d",&s,&t,&c);
    edge e;
    e.to = t-1;
    e.cost = c;
    G[s-1].push_back(e);
    e.to = s-1;
    G[t-1].push_back(e);
  }
  solve();
  return 0;
}
