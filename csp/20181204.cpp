/*
 * @Author: yuuoniy 
 * @Date: 2019-05-09 18:16:39 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-09 18:48:44
 */
// 树的传输时间 = 树的最大边
// 转化题意 很重要
// 最后变成求最小生成树的最大边
// 一定要注意！数组的大小开够啊！！ edge 是 2*MAX_N！！注意啊！！
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 50005;

struct e{
  int x,y,z;
}edge[2*MAX_N];

int fa[MAX_N]; //并查集
int n,m,t;
int res =-1;

bool operator<(e a,e b){
  return a.z < b.z ;
}

int get(int x){
  if(x==fa[x]) return x;
  else return fa[x]=get(fa[x]);//不断往前寻找祖先
}


int main(){
  cin >> n >> m >> t;
  for (int i = 0; i < m; i++)
  {
    cin >> edge[i].x >> edge[i].y >> edge[i].z ;
  }
  sort(edge,edge+m);
  for (int i = 1; i <= n; i++)
  {
    fa[i] = i;
  }
  //求最小生成树
  for (int i = 0; i <m; i++)
  {
    int x = get(edge[i].x);
    int y = get(edge[i].y);
    // cout << edge[i].z << endl;
    if(x==y) continue;
    fa[x] =y;
    res = max(res,edge[i].z) ;
  }
   cout << res << endl;
}
