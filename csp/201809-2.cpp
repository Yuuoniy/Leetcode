/*
 * @Author: yuuoniy 
 * @Date: 2019-03-21 10:34:36 
 * @Last Modified by:   yuuoniy 
 * @Last Modified time: 2019-03-21 10:34:36 
 */
#include <iostream>

using namespace std;

int main(){
  bool h[1000005]={0},w[1000005]={0};
  int n = 0;
  cin >> n;
  int start = 0,end = 0;
  int hmax = 0,wmax;
  for(int i = 0; i < n; i++)
  {
    cin >> start >> end;
    for(int j = start; j < end; j++)
    {
      h[j] = true;
    }
    if(end>hmax)
      hmax = end;
  }
  for(int i = 0; i < n; i++)
  {
    cin >> start >> end;
    for(int j = start; j < end; j++)
    {
      w[j] = true;
    }
    if(end>wmax)
      wmax = end;
  }
  int minMax = hmax> wmax?wmax:hmax;
  int count = 0;
  for(int i = 1; i < minMax; i++)
  {
    if(h[i]&&w[i])
      ++count;
  }
  cout << count;
  return 0;
}
