/*
 * @Author: yuuoniy 
 * @Date: 2019-05-03 13:46:54 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-03 14:02:36
 */

#include <iostream>

using namespace std;
int m,n,q;
char ma[105][105];

void drawline(int x1,int y1,int x2,int y2){
  
}
void fill(int x1,int y1,char c){

}

//输出
void printmap(){
  for(int i = 0; i < n; i++)
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
