/*
 * @Author: yuuoniy 
 * @Date: 2019-05-09 14:53:01 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-09 17:04:39
 */

// 计算强连通分量
// tarjan 算法
// 注意括号！
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;
const int N = 10010,M =1000010;
int ver[M],Next[M],head[N],dfn[N],low[N];
int stack[N],ins[N],c[N];
vector<int> scc[N];
int n,m,tot,num,top,cnt;
int r;

void add(int x, int y){
  ver[++tot] = y;
  Next[tot] = head[x];
  head[x] = tot;
}


void tarjan(int x){
  dfn[x] = low[x] = ++num;
  stack[++top] = x;
  ins[x] = 1;
  for (int i = head[x]; i ; i=Next[i])
  {
    if(!dfn[ver[i]]){
      tarjan(ver[i]);
      low[x] = min(low[x],low[ver[i]]);
    }else if(ins[ver[i]]){
      low[x] = min(low[x],dfn[ver[i]]);
    }
  }
  //  int count = 0;
    if(dfn[x]==low[x]){
      cnt++;
      int y;
      do{
        y = stack[top--];
        ins[y] = 0;
        c[y] = cnt;
        scc[cnt].push_back(y);
        // ++count;
      }while (x!=y);
      // if(count>1){
      //   // r = r+count*(count-1)/2;
      // }
      
    }
  
}
int main(){
  cin >> n >> m;

  for (size_t i = 1; i <=m; i++)
  {
    int x,y;
    cin >> x >> y;
    add(x,y);
  }
  for (int i = 1; i <=n; i++)
  {
    if(!dfn[i]) tarjan(i);
  }

  int res = 0;
  // cout << cnt << endl;
  for (int i = 1; i <= cnt; i++)
  {
    // cout << scc[i].size() << endl;
    if(scc[i].size()>1)
      res+=(scc[i].size()*(scc[i].size()-1))/2;
  }
  cout << res << endl;
  // cout << r<< endl;
  return 0;
}
