/*
 * @Author: yuuoniy
 * @Date: 2019-05-19 17:04:53
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-19 21:58:33
 */

//看到题解 差分约束+最短路，自己对于差分约束非常不熟，所以先从模仿别人的开始啦
//:D
// https://yymelo.com/poj-3169-layout-%E5%B7%AE%E5%88%86%E7%BA%A6%E6%9D%9F-%E6%9C%80%E7%9F%AD%E8%B7%AF/
// 根据题意，列出约束的情况。
/* 约束
1. d[i]<=d[i+1]
2. d[AL]+DL>=d[BL] 关系好的
3. d[AD]+DD<=d[BD] 关系不好的
*/
/* 对应图
1.从顶点i+1向顶点i连一条权值为0的边
2. 从顶点AL向顶点BL连一条权值为DL的边
3. 从顶点BD想顶点AD连一条权值为-DD的边
*/
//所求对应位顶点1到顶点N的距离，不能用 Dijkstra 了，
// 还要学一下 SPFA 和 BF
// 做完这道题就去写代码！！！！
// BF 每一次都要遍历所有的边！，实现还是很简单的，要理解

#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

#define INF 0X3F3F3F3F
using namespace std;
typedef pair<int, int> P;

struct node {
  int from;
  int to;
  int v;
  node(int _from,int _to, int _v) {
    from = _from;
    to = _to;
    v = _v;
  }
};

const int MAX_N = 1005;
vector<node> v;
int dis[MAX_N];
bool visited[MAX_N];
int n, ml, md;

// bf 算法
void solve() {
  // queue q;
  memset(dis,INF,sizeof(dis));
  dis[1] = 0;
  bool up = false;
  for (int i = 1; i <= n+1; i++) {
    up = false;
    for (int j = 0; j < v.size(); j++) {
      node cur = v[j];
      int update = dis[cur.from] + cur.v;
      if (update < dis[cur.to]) {
        dis[cur.to] = update;
        up = true;;
      }
    }
  }
  if(up)
    cout << "-1" << endl;
  else
    cout << ((dis[n]==INF)?-2:dis[n]) << endl;
}


int main() {
  cin >> n >> ml >> md;
  //根据差分约束添加边
  for (int i = 1; i < n; i++) {
    v.push_back(node(i+1,i, 0));
  }
  for (int i = 0; i < ml; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    v.push_back(node(x,y, z));
  }
  for (int i = 0; i < md; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    v.push_back(node(y,x, -z));
  }
  solve();
  return 0;
}
