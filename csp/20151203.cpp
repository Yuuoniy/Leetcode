/*
 * @Author: yuuoniy 
 * @Date: 2019-05-03 13:46:54 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-09 13:28:54
 */
// 注意细节问题！
// 深度优先搜索或者广度优先搜索
// 分清 x 和 y!!
// 只有 90 分 ,一开始 fill 的 x 和 y 反了！所以错了，改过来就好了
#include <iostream>
#include <utility>
#include <stack>
#include <algorithm>

using namespace std;
typedef pair<int,int> P;

int m,n,q;
char ma[120][120];

void drawline(int x1,int y1,int x2,int y2){
  //水平和垂直
  if(y1==y2){
    if(x1>x2) swap(x1,x2);
    for (int i = x1; i <=x2; i++)
    {
      if(ma[y1][i]=='|'||ma[y1][i] == '+') ma[y1][i]='+';
      else ma[y1][i] = '-';
    }
  }else{
    if(y1>y2) swap(y1,y2);
    for (int i = y1; i <=y2; i++)
    {
     if(ma[i][x1]=='-'||ma[i][x1]=='+') ma[i][x1]='+';
     else  ma[i][x1]='|';
    } 
  }
}
//判断在边界内
bool isLegal(int x,int y){
  return x>=0&&x<m&&y>=0&&y<n; 
}

void fill(int x,int y,char c){
  int dx[4] = {0,0,1,-1};
  int dy[4] = {1,-1,0,0};
  stack<P> s;
  s.push(make_pair(x,y)); //起始位置
  ma[y][x] = c;
  while (!s.empty())
  {
    P p = s.top();
    s.pop();
    for (int i = 0; i < 4; i++)
    {
      P t = make_pair(p.first+dx[i],p.second+dy[i]);
      if(isLegal(t.first,t.second)&&ma[t.second][t.first]!='+'&&ma[t.second][t.first]!='-'&&ma[t.second][t.first]!='|'&&ma[t.second][t.first]!=c){
        
        ma[t.second][t.first]=c;
        s.push(t);
      }
    }
  }
  
}

//输出
void printmap(){
  for(int i =n-1; i>=0; i--)
  {
    for(int j = 0; j < m; j++)
    {
      cout << ma[i][j];
    }
    cout << endl;
  }
  
}

int main(){
  cin >> m >> n >> q;
  int op;
  int x1,x2,y1,y2;
  char c;
  for (int i = 0; i < 120; i++)
  {
    for (int j = 0; j < 120; j++)
    {
      ma[i][j]='.';
    }
    
  }
  
  for(int i = 0; i < q; i++)
  {
    cin >> op;
    if(op==0) //划线
    {
      cin >> x1 >> y1 >> x2 >> y2 ;
      drawline(x1,y1,x2 ,y2);
     
    }
    else{
      cin >> x1 >> y1 >> c;
      fill(x1, y1, c);
    }
  }

  printmap();
  return 0;
}
