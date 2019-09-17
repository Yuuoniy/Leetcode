/*
 * @Author: yuuoniy 
 * @Date: 2019-05-10 09:14:42 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-08-23 12:54:06
 */
// 最优配餐
// 每个顾客广度优先搜索，找到最近的店铺就好了吧。。 不要单独，要一起搜索！
// 不过要注意的是，这个题目不是单单从一个结点出发进行搜索，而是从所有的分店同时开始搜索，这样就确保了代码运行过程中不会超时
// 注意！
// 定义好结构体，记录深度，这样才能算花费
#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <queue>

using namespace std;
typedef pair<int,int> P;
const int MAX_N = 1005;
const int MAX_M =  MAX_N*MAX_N;

int dist[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int width,numStore,numClient,numHole;

struct Pos{
  int x,y,val;
  Pos(int _x,int _y):x(_x),y(_y){}
  Pos(){}
};

bool legal(int x,int y){
  return x>=1&&y>=1&&x<=width&&y<=width;
}

Pos dir[4]={{0,1},{0,-1},{1,0},{-1,0}};

int main(){
  cin >> width >> numStore >> numClient >> numHole;
  queue<Pos> stores;
  vector<Pos> holes,clients;
  Pos p;
  // 商店
  for (int i = 0; i < numStore; i++)
  {
    cin >> p.x >> p.y;
    stores.push(p);
    dist[p.x][p.y] = 0;
    visited[p.x][p.y] = true;
  }
  // 客户
  for (int i = 0; i < numClient; i++)
  {
    cin >> p.x >> p.y >> p.val;
    clients.push_back(p);
  }
  for (int i = 0; i < numHole; i++)
  {
    cin >> p.x >> p.y;
    dist[p.x][p.y] = -1;
    visited[p.x][p.y] = true;
  }
  while (!stores.empty())
  {
    Pos p = stores.front();
    stores.pop();
    for (int i = 0; i < 4; i++)
    {
      Pos np(p.x+dir[i].x,p.y+dir[i].y);
      if(!visited[np.x][np.y]&&legal(np.x,np.y)){
        visited[np.x][np.y] = true;
        dist[np.x][np.y] = dist[p.x][p.y]+1;
        stores.push(np);
      }
    }
    
  }
  long long cost = 0;
  for (int i = 0; i < numClient; i++)
  {
    cost+= dist[clients[i].x][clients[i].y]*clients[i].val;
  }
  cout << cost;
  
  
  return 0;
  


  
}
