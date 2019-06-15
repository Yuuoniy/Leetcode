/*
 * @Author: yuuoniy 
 * @Date: 2019-05-15 15:41:37 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-15 16:28:34
 */

//封锁阳光大学
// dfs 染色
// 每一条边都有且仅有一个被它所连接的点被选中。又因为我们要处理的是一个连通图。所以，对于这一个图的点的选法，可以考虑到相邻的点染成不同的颜色。

//于是，对于一个连通图，要不就只有两种选法（因为可以全部选染成一种色的，也可以全部选染成另一种色的），要不就是impossible！
// 所以，我们只需要找到每一个子连通图，对它进行黑白染色，然后取两种染色中的最小值，然后最后汇总，就可以了。

//另外，要判断impossible，只需要加一个used数组，记录已经遍历了哪些点。如果重复遍历一个点，且与上一次的颜色不同，则必然是impossible的
#include <iostream>

using namespace std;
int n,m;
const int MAX_N = 10005;
const int MAX_M = 100005;

struct EDGE{
  int t;
  int next;
}edge[MAX_M*2];
int head[MAX_N];
int cnt;
void add(int a,int b){
  ++cnt;
  edge[cnt].t = b;
  edge[cnt].next = head[a];
  head[a] = cnt;
}

bool used[MAX_N];
int col[MAX_M]; //每个点的染色
int count[2]; //两种染色各自的点数

bool dfs(int n,int color){
  if(used[n]){
    if(col[n]==color) return true;
    else return false;
  }
  used[n] = true;
  col[n] = color;
  count[color]++;
  bool tf = true;
  for (int i = head[n]; i&&tf; i=edge[i].next)
  {
    tf=dfs(edge[i].t,1-color);
  }
  return tf;
}

int main(){
  cin >> n >> m;
  while (m--)
  {
    int x,y;
    cin >> x >> y;
    add(x,y);
    add(y,x);
  }
  int ans = 0;
  for (int i = 1; i <=n; i++)
  {
    if(used[i]) continue;//已经遍历过了
    count[0]=count[1] = 0;
    if(!dfs(i,0)){
      cout << "Impossible" << endl;
      return 0;
    }
    ans+= min(count[0],count[1]);
  }
  cout << ans << endl;
  return 0;
  
}
