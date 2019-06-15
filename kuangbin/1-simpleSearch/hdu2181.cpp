/*
 * @Author: yuuoniy
 * @Date: 2019-06-14 14:35:44
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-14 14:49:06
 */

// 因为 要按字典序输出，直接用邻接矩阵存储。这样从0，n
// 扫描就可以了。而不是邻接表

#include <cstdio>
#include <vector>

using namespace std;

const int N = 25;
bool vis[N];
int path[N];
int ma[N][N];
int m; //从 m 出发
int no;//路径编号
void dfs(int source, int con) { 
  path[con] = source;
  if (con == 21&&source==m){
    printf("%d:  ",++no);
    for (int i = 1; i <= 21; i++)
    {
      printf("%d%c",path[i],i==21?'\n':' ');
    }
    return;
  }

  for (int i =1 ; i <=20; i++)
  {
    if(ma[source][i]&&!vis[i]){
      vis[i] = 1;
      dfs(i,con+1);
      vis[i] = 0;
    }
  }
  return;
 }
int main() {

  for (int i = 1; i <= 20; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    ma[i][x] = ma[i][y] = ma[i][z] = 1;
  }
  while (scanf("%d", &m) && m != 0) {
    dfs(m, 1);
  }
}
