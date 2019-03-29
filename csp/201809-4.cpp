/*
 * @Author: yuuoniy 
 * @Date: 2019-03-21 10:35:06 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-03-21 10:45:54
 */
// 思路：目前我不会做.. 所以只能参考别人的博客 https://blog.csdn.net/u014390156/article/details/82775736
// 典型的最短路解差分约束
// 思考如何建立差分系统，引入中间变量si=x0+x1+…+xi
// 这里要求最小的字典序，全部转化成大于等于的形式，sj-si≥k，i到j建立一条权值为k的单向边，然后spfa最长路，在spfa之前记得将所有点加入队列，并且dist置0
// 因为差分约束系统不保证图是连通的，所以要先建立一个虚拟节点
// 使用邻接表存储
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 305;

int dist[305],inq[305];
int n,m,first[MAXN],vis[MAXN], nums[MAXN];
int current;

struct Edge{
  int to,w,next;
}edge[MAXN*MAXN];

void spfa(){
  queue<int> que;
  //init
  for(int i = 0; i <=n; i++)
  {
    que.push(i);
    dist[i] = 0,inq[i] = 1,vis[i] = 1; //dist[i] = 0,虚拟结点
  }
  while(!que.empty()){
    int now = que.front();
    // cout << "insade spfa" << endl;
    que.pop();
    inq[now]++;
    vis[now] = 0;
    if(inq[now]>n){
      cout<<"not largest path"<<endl;
      return;
    }
    for(int i = first[now];i!=-1 ; i = edge[i].next) //first 为头
    {
      int to = edge[i].to,w = edge[i].w;
      if(dist[to]<dist[now]+w){ //最长路
        dist[to] = dist[now]+w;
        if(!vis[to]){
          que.push(to);
          vis[to] = 1;
        }
      }
    }
  }
  return;
}

void add_edge (int x,int y,int value){ //新的边添加在列表的首部，fisrt[x] 可以访问到，然后不断 next 获取，直到 -1
  edge[current].to = y;
  edge[current].w = value;
  edge[current].next = first[x];
  first[x] = current++;
}
int main(){
  cin >> n;
  for(int i = 1; i <=n; i++)
  {
    scanf("%d",&nums[i]);
  }
  // init
  for(int i=0;i<=n;i++)
    first[i] = -1;
  current = 0;
  for(int i = 0; i <n-2; i++)
  {
    add_edge(i+3,i,-(nums[i+2]*3+2));
    add_edge(i,i+3,nums[i+2]*3);
  }
  add_edge(2,0,-(nums[1]*2+1));
  add_edge(0,2,nums[1]*2);
  add_edge(n,n-2,-(nums[n]*2+1));
  add_edge(n-2,n,nums[n]*2);

  //每个要大于1
  for(int i = 1; i <=n; i++)
  {
    add_edge(i-1,i,1);
  }

  spfa();
  nums[1] = dist[1];
  for(int i = 2; i <=n; i++)
  {
    nums[i] = dist[i]-dist[i-1];
  }
  for(int i=1;i<=n;i++){
    if(i==n)
      printf("%d\n",nums[i]);
    else 
      printf("%d ",nums[i]);
  }
  
  return 0;
}
