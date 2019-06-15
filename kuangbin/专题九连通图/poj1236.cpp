/*
 * @Author: yuuoniy
 * @Date: 2019-06-13 14:12:43
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-13 14:58:31
 */
// https://acm.taifua.com/archives/poj1236.html
/*
给定一个 n 点 m 边有向图，问：

至少选择多少个点才能从这些点到达其他所有点
至少添加几条边才能从任意一点到达其他所有点
 */
// 解：tarjan 求强连通分量，缩点。求max(入度为0，出度为0的个数)

#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX_N = 101;

vector<int> edge[MAX_N];
int tot,scc_cnt;
int dfn[MAX_N],low[MAX_N],sccno[MAX_N],indegree[MAX_N],outdegree[MAX_N];
bool vis[MAX_N];

int n;
stack<int> s;

void tarjan(int x){
  dfn[x] = low[x] = ++tot;
  s.push(x);
  vis[x] = true;
  for (int i = 0; i < edge[x].size(); i++)
  {
    int v = edge[x][i];
    if(!dfn[v]){
      tarjan(v);
      low[x] = min(low[x],low[v]);
    }else if(vis[v]){
      low[x] = min(low[x],dfn[v]);
    }
  }
  if(dfn[x]==low[x]){
    ++scc_cnt;
    while (1)  
    {
      int u = s.top();
      s.pop();
      vis[u] = 0;
      sccno[u] = scc_cnt;
      if(u==x)
        break;
    }
    
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x = 0;
    while (scanf("%d", &x) && x != 0) {
      edge[i].push_back(x);
    }
  }
  for (int i = 1; i <=n; i++)
  {
    if(!dfn[i]){
      tarjan(i);
    }
  }

  //缩点建图
  for (int i = 1; i <=n; i++)
  {
    for (int j = 0; j <edge[i].size(); j++)
    {
      int v = edge[i][j];
      if(sccno[v]!=sccno[i]){

        outdegree[sccno[i]]++;
        indegree[sccno[v]]++;
      }
    }
    
  }
  int in_cnt = 0,out_cnt = 0;

  for (int i = 1; i <=scc_cnt; i++)
  {
    if(indegree[i]==0) ++in_cnt;
    if(outdegree[i]==0) ++out_cnt;
    
  }
  //特判
  if(scc_cnt==1)
    printf("1\n0\n");
  else
    printf("%d\n%d\n",in_cnt,max(in_cnt,out_cnt));
  
  return 0;
}
