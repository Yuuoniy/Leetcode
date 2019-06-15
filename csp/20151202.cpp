/*
 * @Author: yuuoniy 
 * @Date: 2019-05-15 17:54:06 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-15 19:39:38
 */
//消除类游戏
//肯定是一条线上的，不要想太麻烦！
#include <iostream>
#include <stdio.h>
using namespace std;
const int MAX_N = 35;
int ma[MAX_N][MAX_N];
int n,m;
int used[MAX_N][MAX_N];


int main(){
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> ma[i][j];
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if(j<m-2){
      if(ma[i][j]==ma[i][j+1]&&ma[i][j+1]==ma[i][j+2]){
        used[i][j]= used[i][j+1] = used[i][j+2] = 1;
      }
      }
      if(i<n-2){
      if(ma[i][j]==ma[i+1][j]&&ma[i+1][j]==ma[i+2][j]){
        used[i][j]=used[i+1][j]=used[i+2][j] = 1;
      }
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      printf("%d ",used[i][j]?0:ma[i][j]);
    }
    printf("\n");
    
  }
  
  return 0;
  


  
}
