/*
 * @Author: yuuoniy 
 * @Date: 2019-05-15 19:47:40 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-15 20:06:01
 */
// 运动分为四个方向
// 在状态之间进行转化，而不是坐标！
// 向右，左下，向下，右上
#include <iostream>
using namespace std;
const int MAX_N = 505;
int num[505][505];
int n,i,j;
int main(){
  cin >> n;
  for (int i = 1; i <=n; i++)
  {
    for (int j = 1; j <=n; j++)
    {
      cin >> num[i][j];
    }
  }
  
  int d = 1;
  i = j =1;
  while (i+j<2*n)
  {
    switch(d){
      case 1:
        cout << num[i][j++] << " ";
        if(i==1)
          d = 2;
        else if(i==n)
          d = 4;
        break;
      case 2:
        cout << num[i++][j--]<< " ";
        if(j==1) d = 3;
        if(i==n) d = 1;
        break;
      case 3:
        cout << num[i++][j] << " ";
        if(j==1) d=4;
        else d = 2;
        break;
      case 4:
        cout << num[i--][j++] << " ";
        if(i==1&&j!=n){
          d = 1;
        }else if(j==n){
          d = 3;
        }
        break;
    }
  }
  cout << num[i][j];
  return 0;
  
  
  
}
