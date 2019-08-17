/*
 * @Author: yuuoniy 
 * @Date: 2019-07-10 22:30:45 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-07-10 22:45:17
 */

#include <iostream>
#include <string>

using namespace std;

const int MAX_N = 105;
string ma[MAX_N];

int n,m;
int dx[8] = {1,-1,0,0,1,1,-1,-1};
int dy[8] = {0,0,1,-1,1,-1,1,-1};

void dfs(int x,int y){
  ma[x][y] = '.';
  for (int i = 0; i < 8; i++)
  {
    int xx = x+dx[i];
    int yy = y+dy[i];
     if(xx>=0&&xx<n&&yy>=0&&yy<m&&ma[xx][yy]=='W')
        dfs(xx,yy);
  }
}
int main(){
  cin >> n>>m; 
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> ma[i];
  }
  
   for (int i = 0; i <n; i++)
  {
    for (int j = 0; j <m; j++)
    {
      if(ma[i][j]=='W'){
          dfs(i,j);
          ++cnt;

      }
    }
  }
  cout << cnt << endl;
  return 0;
  
}
