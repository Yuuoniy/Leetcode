/*
 * @Author: yuuoniy 
 * @Date: 2019-04-18 00:36:05 
 * @Last Modified by:   yuuoniy 
 * @Last Modified time: 2019-04-18 00:36:05 
 */

//怎么找闭合圈呢？？
#include <stdio.h>
#include <iostream>

using namespace std;

int n = 0;
int map[35][35];

int dx[5] = {0,1,-1,0,0};
int dy[5] = {0,0,0,-1,1};

void dfs(int x,int y){
  if(x<0||x>n+1||y<0||y>n+1||map[x][y]!=0) return;
  map[x][y] = -1;
  for(int i = 1; i <=4; i++)
  {
    dfs(x+dx[i],y+dy[i]);
  }
}

int main(){
  scanf("%d",&n);
  for(int i = 1; i <=n; i++)
  {
   for(int j = 1; j <= n; j++)
   {
    scanf("%d",&map[i][j]);
   }
  }
  // for(int i = 0; i<= n+1; i++)
  // {
  //   for(int j = 0; j <=n+1; j++)
  //   {
  //     printf("%d ",map[i][j]);
  //   }
    
  //   printf("\n");
  // }
  
  dfs(0,0);
  for(int i = 1; i <=n; i++)
  {
   for(int j = 1; j <=n; j++)
   {
     if(map[i][j]==0) printf("2 ");
     else if(map[i][j]==-1) printf("0 ");
     else printf("1 ");
   }
   printf("\n");
   
  }
  return 0;
}
