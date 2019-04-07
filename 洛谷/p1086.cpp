// 贪心策略

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct 
{
  int x,y,w;
}Node;

Node nodes[405];
int maps[25][25];//地图

bool cmp(Node& a,Node& b){
  return a.w > b.w;
}

int main(){
  int m,n;
  int t;
  cin >> m >> n >> t;
  int count = 0;
  for(int i = 1; i <=m; i++)
  {
    for(int j = 1; j <=n; j++)
    {
      cin >> maps[i][j];
      if(maps[i][j]){
          nodes[count].x = i;
          nodes[count].y  = j;
          nodes[count].w = maps[i][j];
          ++count;
      }
    }
    
  }
  sort(nodes,nodes+count,cmp); //排序
  t--;
  int pos_x = 1;
  int have = 0;//记录目前采的是第几次
  int num = 0;
  int pos_y = nodes[have].y;//初始列，最高的那一个
  while(1){
    int cost = abs(pos_x-nodes[have].x)+abs(pos_y-nodes[have].y);
    t-= cost;
    --t;
    if(t<nodes[have].x) //说明无法返回
    {
      cout << num;
      return 0;
    }
    num += nodes[have].w;//采摘
    // cout << "have " << nodes[have].w << endl;
    pos_x = nodes[have].x;
    pos_y = nodes[have].y;
    ++have;
    if(have==count)
      break;
  }
  cout << num;
  return 0;
  

  
}
