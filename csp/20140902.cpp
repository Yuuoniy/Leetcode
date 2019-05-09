/*
 * @Author: yuuoniy 
 * @Date: 2019-05-09 14:36:12 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-09 18:50:34
 */
// 地图 填充
#include <iostream>

using namespace std;

char ma[105][105];
int n;

int main(){
  cin >> n;
  int x1,y1,x2,y2;
  for (int i = 0; i < 105; i++)
  {
    for (int j = 0; j < 105; j++)
    {
      ma[i][j] = '.';
    }
  }
  while(n--){
      cin >> x1 >> y1 >> x2 >> y2;
      //注意边界
  for (int i = y2; i >y1; i--)
  {
    for (int j = x1+1; j <=x2; j++)
    {
      ma[i][j] = '+';
    }
  }
  }

  int res = 0;

  for (int i = 0; i < 105; i++)
  {
    for (int j = 0; j < 105; j++)
    {
      if(ma[i][j] == '+'){
        ++res;
      }
    }
  }
  cout << res << endl;
  return 0;
}
