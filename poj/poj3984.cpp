/*
 * @Author: yuuoniy 
 * @Date: 2019-07-10 22:55:49 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-07-10 23:08:44
 */


#include <iostream>
#include <map>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int,int> point;

int m[5][5];


queue<point> q;
vector<point> v;
map<point,point> pre;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++) {
      cin >> m[i][j];
    }
  }
  q.push(make_pair(0,0)); //初始结点入列
  pre[make_pair(0,0)] = make_pair(0,0);
  while (!q.empty())
  {
    point t = q.front();
    q.pop();
    if(t.first==4&&t.second==4)
      break;
    for (int i = 0; i < 4; i++)
    {
      int xx = t.first+dx[i];
      int yy = t.second+dy[i];
      if(xx<0||xx>=5||yy<0||yy>=5)
        continue;
      if(m[xx][yy]==0&&pre.find(make_pair(xx,yy))==pre.end()){
        q.push(make_pair(xx,yy));
        pre[make_pair(xx,yy)] = t;
      }
    }
    
  }
  v.push_back(make_pair(4,4));
  point h = make_pair(4,4);
  while (true)
  {
    point anc = pre[h];
    v.push_back(anc);
    if(anc.first==0&&anc.second==0)
      break;
    h = anc;
  }
  for (int i = v.size(); i >=0; i--)
  {
    cout << "(" << v[i].first << ", " << v[i].second << ")" << endl;
   
  }
  return 0;
  
  
  


  
}
