/*
 * @Author: yuuoniy 
 * @Date: 2019-06-16 00:30:51 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-16 00:36:43
 */

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
  int x1,x2,y1,y2,z1,z2;
  while (cin>>x1>>y1>>z1>>x2>>y2>>z2)
  {
    double dis = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
    double area = (4.0/3)*acos(-1)*dis*dis*dis;
    printf("%.3f %.3f\n",dis,area);
  }
  return 0;
  
}
