/*
 * @Author: yuuoniy 
 * @Date: 2019-05-15 20:16:38 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-15 20:35:14
 */
// 窗口
// 问题：怎么维护层次
#include <iostream>
#include <vector>

using namespace std;
struct rect{
  int x1;
  int x2;
  int y1;
  int y2;
  int idx;
};

vector<rect> rectangles;



const int MAX_N = 15;
const int MAX_M = 15;
int ma[2600][1500];
int n,m;
int main(){
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    rect t;
    cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;
    t.idx = i;
    rectangles.push_back(t);
  }
  int x,y;
  int match = -1;
  while (m--)
  {
   cin >> x >> y;
   int i;
   for (i = n-1; i>=0; i--)
   {
    if(x>=rectangles[i].x1&&x<=rectangles[i].x2&&y>=rectangles[i].y1&&y<=rectangles[i].y2){
      // match = i;
      cout <<rectangles[i].idx << endl;
      break;
    }
   }
   if(i==-1) cout << "IGNORED" << endl;
   else{
     rect t = rectangles[i];
    rectangles.erase(rectangles.begin()+i);
    rectangles.push_back(t);
   }
   
  }
  return 0;
}
