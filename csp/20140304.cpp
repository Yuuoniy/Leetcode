/*
 * @Author: yuuoniy 
 * @Date: 2019-05-16 16:07:16 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-16 17:04:48
 */

//无线网络

/*解析：
路由器构成了一个图，如果两个路由器的距离小于r则存在边。
求解的是最短路径。图所有边的权重均为1，因此可以用广度优先搜索解决。
搜索的时候需要记录路径上所经过的增设路由器的个数，并确保不会超过k。
使用广度优先搜索的层次遍历，可以方便地得到第1个路由器与第2个路由器之间的距离。
出处：https://www.cnblogs.com/meelo/p/7677599.html
*/
// 要学会转化题意！！
// 离散化
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>



using namespace std;

int n,m,k,r;
const int MAX_N = 210;
bool graph[MAX_N][MAX_N];
int pos[MAX_N][2];

struct node{
  int idx;
  int count;
  int step;
};

int count_k;
bool inRange(int a,int b,int r){
  return sqrt(pow(pos[a][0]-pos[b][0],2)+pow(pos[a][1]-pos[b][1],2))<=r;
}
int bfs(int s,int t){
  vector<bool> visited(m+n);
  queue<node> q;
  node a;
  a.idx = s;
  a.count = 0;
  a.step = 0;
  q.push(a);
  visited[s] = true;
  int len = 1,newLen,level=1;
  while (!q.empty())
  {
    node w = q.front();
    q.pop();
    if(w.idx==t) return w.step-1;
    for (int i = 0; i < n; i++)
    {
      if(graph[w.idx][i]&&!visited[i]){
        a.idx = i;
        a.step = w.step+1;
        q.push(a);
        visited[i] = true;
      }
    }
    for (int i = n; i <n+m; i++)
    {
      if(graph[w.idx][i]&&!visited[i]&&w.count<k){
        a.idx = i;
        a.count = w.count+1;
        a.step = w.step+1;
        q.push(a);
        visited[i] = true;
      }
    }
  }
}

int main(){
  cin >> n >> m >> k >> r;
  for (int i = 0; i < n+m; i++)
  {
    cin >> pos[i][0] >> pos[i][1];
  }
  for (int i = 0; i < n+m; i++)
  {
    for (int j = i+1; j < n+m; j++)
    {
      graph[i][j] = graph[j][i] = inRange(i,j,r); 
    }
    
  }
  cout << bfs(0,1);
  return 0;
}
