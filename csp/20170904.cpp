/*
 * @Author: yuuoniy 
 * @Date: 2019-05-10 08:26:46 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-10 08:57:02
 */
//传递闭包，看到别人说直接超时了，直接 dfs 就可以。。
// n 不是很大
//要对每个节点都进行 dfs
// 这种题 如果直接提交不评测完全摸不准。。多练练吧呜呜
// 注意 for 循环局部变量的作用范围
// 又运行错误。。发现是vis[x]=1 写成了 vis[x]？测试的时候怎么没发现。。
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
const int MAX_N = 1005;
int n,m;
bool ma[MAX_N][MAX_N];
bool vis[MAX_N];
vector<int> V[MAX_N]; 

void dfs(int x,int y){
  vis[x] = 1;
  ma[x][y] = ma[y][x] = 1;
  for (int i = 0; i < V[x].size(); i++)
  {
    if(!vis[V[x][i]]){
      dfs(V[x][i],y);
    }
  }
}


int main(){
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int x,y;
    cin >> x >> y;
    ma[x][y] = 1;
    V[x].push_back(y);
  }
  //注意每一遍都要清空 vis!
  for (int i = 1; i <= n; i++)
  {
    // fill(vis+1,vis+n+1,0);
    memset(vis,0,sizeof(vis));
    dfs(i,i);
  }
  int i,j,ans = 0;
  //计数
  for (i = 1; i <=n; i++)
  {
    for (j = 1; j <=n; j++)
    {
      if(!ma[i][j]){
        break;
      }
    }
    if(j==n+1) ++ans;
  }
  cout << ans << endl;
  return 0;
}
