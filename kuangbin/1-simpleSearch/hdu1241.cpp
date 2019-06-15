/*
 * @Author: yuuoniy 
 * @Date: 2019-06-14 08:39:04 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-14 08:39:27
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAX_N = 105;
char ma[MAX_N][MAX_N];
int dir[][2] = {{1,-1},{1,1},{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{-1,1}};
int n,m;
bool vis[MAX_N][MAX_N];
int tot;
int isValid(int x,int y){
  return x>=0&&x<m&&y>=0&&y<n;
}
void dfs(int i,int j){
  if(vis[i][j]) return;
  vis[i][j] = 1;
  for (int k = 0; k < 8; k++)
  {
    int xx = i+dir[k][0];
    int yy = j+dir[k][1];
    if(!isValid(xx,yy)) continue;
    if(ma[xx][yy]=='*') continue;
    dfs(xx,yy);
  }
  
}


int  main(){
  while (scanf("%d%d",&m,&n)&&m!=0&&n!=0)
  {
    memset(vis,0,sizeof(vis));
    tot = 0;
    gets(ma[0]);
    for (int i = 0; i < m; i++)
    {
      gets(ma[i]);
      
    }
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if(ma[i][j]=='@'&&vis[i][j]==0){
          ++tot;
          dfs(i,j);
        }
      }
    }
    
    printf("%d\n",tot);
  }
  return 0;
}
