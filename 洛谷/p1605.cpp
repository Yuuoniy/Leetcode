// 注意：有些同学可能觉得就在地图map数组上打标记（自己走过的路）比较简单，走过的路和障碍可能引起混淆，如果只用map数组的话，可能只的得到80分；（贴主的惨痛经历）
#include <iostream>

using namespace std;

int n,m,t;
int count = 0;
int x1,y1,x2,y2;
int map[6][6]={0};
bool isvisited[6][6]={0};
int dx[4] = {0,0,1,-1};
int dy[4]={-1,1,0,0};
void dfs(int x,int y ){
 
  if(x==x2&&y==y2){
    ++count;
    return;
  }
  // if(x-1>=0&&map[x-1][y]!=-1) dfs(x-1,y);
  // if(y-1>=0&&map[x][y-1]!=-1) dfs(x,y-1);
  // if(y+1<m&&map[x][y+1]!=-1) dfs(x,y+1);
  // if(x+1<n&&map[x+1][y]!=-1) dfs(x+1,y);
  for(int i = 0; i <= 3; i++)
  {
    if(map[x+dx[i]][y+dy[i]]==1&& isvisited[x+dx[i]][y+dy[i]]==0){
      // cout << x+dx[i] << " 1" << y+dy[i] << endl;
        isvisited[x][y] = 1;
        dfs(x+dx[i],y+dy[i]);
        // map[x+dx[i]][y+dy[i]] = 1;
        isvisited[x][y] = 0;

    }
  }
  
}


int main(){
  cin >> n >> m>>t;
  cin >> x1 >> y1 >> x2 >> y2;
  for(int i=1;i<=n;i++){
    for(int j = 1; j <= m; j++)
    {
      map[i][j] = 1;
      isvisited[i][j]=0;
    }
  }
  int x,y;
  for(int i = 0; i < t; i++)
  {
    cin >> x >>y;;
    map[x][y]=-1; //障碍
  }
   dfs(x1,y1);
   cout << count << endl;
   return 0;
  
}
