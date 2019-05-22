/*
 * @Author: yuuoniy
 * @Date: 2019-05-19 09:22:32
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-19 10:06:30
 */

// minimax distance  即为 ：两个石头之间的frog
// distance就是在这两个石头之间的所有路径中最大跳(necessary jump range)最小的。
// 看别人题解才理解题意 http://www.cnblogs.com/ZJUT-jiangnan/p/3937626.html
// 修改 dis 的松弛条件就好了！
// 可以视为与所有的结点都连接，所以每次都要遍历所有的进行更新。
//标记结点是否访问过,每个结点用一个下标表示就可以了,是是否求道这个点，而不是是否访问过，有可能更新很多次的，visited 的位置要写对！
// 两点间的距离最后再开根号求就好了
// 有点像动态规划
// 做完这道题就不做了！

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cstring>
// #include <memory.h>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define INF 0X3F3F3F3F


using namespace std;
typedef pair<int, int> P;


const int MAX_N = 205;
vector<P> v;
int dis[MAX_N]; //注意
bool visited[MAX_N];
int n;
int t;

//两点间的欧拉距离
int distance_point(pair<int, int> a, pair<int, int> b) {
  return (a.first - b.first) * (a.first - b.first) +
         (a.second - b.second) * (a.second - b.second);
}


void solve(){
  memset(visited,0,sizeof(visited));
  memset(dis,INF,sizeof(dis));
  priority_queue<P,vector<P>,greater<P> > q; //要小根堆
  dis[0] = 0;
  q.push(P(dis[0],0));
  // visited[0] = true;
  while (!q.empty())
  {
    P tmp = q.top();
    q.pop();
    if(visited[tmp.second] ) continue;
    visited[tmp.second] = 1;
    for (int i = 0; i < n; i++)
    {
      int update = max(tmp.first,distance_point(v[tmp.second],v[i]));
      if(dis[i]>update){
        dis[i] = update;
        q.push(P(dis[i],i));
      }
    }
    
  }
  cout << "Scenario #" << t << endl;
  float res = sqrt(dis[1]);
  cout <<"Frog Distance = " ;
  printf("%.3f\n\n",res);
  return;
  
}

int main() {
  while (cin >> n && n != 0) {
    t++; //用例
    v.clear();
    for (int i = 0; i < n; i++) {
      int x, y;
      P tmp_point;
      cin >> tmp_point.first >> tmp_point.second;
      v.push_back(tmp_point);
    }
    solve();
  }
  return 0;

}
