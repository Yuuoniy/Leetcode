/*
 * @Author: yuuoniy 
 * @Date: 2019-05-09 17:21:42 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-09 18:05:18
 */
//
// 树的直径，可以使用两次 BFS/DFS 来做
// 因为这里边权都是1，可以直接简化为最大的两个子树深度之和+2 用树形 DP 来解。。DP 好难 还不会树形的。。
// 注意边界
// 然后一开始 MAX_N 错了？？开到  20005 才可以。为什么呢。。因为 N ,M 加起来！！！

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;
const int MAX_N = 20005;
int n,m;
int C[MAX_N],S[MAX_N];
int dis[MAX_N];
bool vis[MAX_N];
int max_p;
vector<int> G[MAX_N];
void add_edge(int from, int to){
  G[from].push_back(to);
  G[to].push_back(from);
}


int bfs(int s){
  queue<int> que;;
  memset(dis,0,sizeof(dis));
  memset(vis,0,sizeof(vis)); //注意清空标记！
  que.push(s);
  vis[s] = true;
  int ans = 0;
  while (!que.empty())
  {
    int u = que.front();
    que.pop();
    for (int i = 0; i < G[u].size(); i++)
    {
      int v = G[u][i];
      if(!vis[v]){
        que.push(v);
        vis[v] = true;
        dis[v] = dis[u]+1;
        if(dis[v]>ans){
          ans = dis[v];
          max_p = v;
        }
      }
    } 
  }
  return ans;
}

int main(){
  cin >> n >> m;
  int t;
  //交换机
  for (int i = 2; i <=n; i++)
  {
   cin >> t;
   add_edge(t,i);
  }
  //电脑，变编号从 n+1 开始
  for(int i=1;i<=m;i++){
    cin >> t;
    add_edge(i+n,t);
  }

  bfs(1);
  int res = bfs(max_p);
  cout << res << endl;
  

}
