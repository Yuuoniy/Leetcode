/*
 * @Author: yuuoniy 
 * @Date: 2019-04-12 10:14:11 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-04-12 11:03:27
 */
// 搜索，问题在于如何标记呢
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int n;
char maps[105][105];

string str = "yizhong";
int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};
bool isWord[105][105]={0};
map<char,char> p;

bool dfs(int x,int y,int dir){
  if(maps[x][y]=='g'){
    isWord[x][y] = true;
    return true;
  }
  char a = maps[x][y];
  int cur_x = x+dx[dir];
  int cur_y = y+dy[dir];
  // cout << a << " next " << maps[cur_x][cur_y] <<  " map " << p[a] << " dir " << dir<<endl;
  // cout << " x :" <<cur_x << " y :" << cur_y << endl;
  if(cur_x>=0&&cur_y>=0&&maps[cur_x][cur_y]==p[a]) {
    if(dfs(cur_x,cur_y,dir)){
      // cout << "is a word" << endl;
      isWord[x][y]=1;
      return true;
    }
  }
  return false;
  
}

int main(){
  for(int i = 0; i < str.size()-1; i++) //初始化与他相连的字符
  {
    p[str[i]] = str[i+1];
  }
  
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> maps[i][j];
     
      
    }
  }

for(int i = 0; i < n; i++)
{
  for(int j = 0; j < n; j++)
  {
     if(maps[i][j]=='y'){
      //  cout << i << " " << j << endl;
       for(int k = 0; k < 8; k++)
       {
         if(dfs(i,j,k)) isWord[i][j]=1;
       }
  }
  
}
}


  for(int i = 0; i < n; i++)
  {
    for(size_t j = 0; j < n; j++)
    {
      if(isWord[i][j]) cout << maps[i][j];
      else cout << "*";
    }
    cout << endl;
    
  }
  
  return 0;
}
