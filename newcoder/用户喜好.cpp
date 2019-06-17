
/*
 * @Author: yuuoniy 
 * @Date: 2019-06-16 10:48:00 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-16 10:58:29
 */


#include <iostream>

using namespace std;

int num[300005];

int main(){
  int n;
  scanf("%d",&n);
  for (int i = 1; i <=n; i++)
  {
    scanf("%d",&num[i]);
  }
  int m;
  scanf("%d",&m);
  for (int i = 0; i < m; i++)
  {
    int x,y,k;
    scanf("%d%d%d",&x,&y,&k);
    int cnt = 0; 
    for (size_t i = x; i <=y; i++)
    {
      if(num[i]==k) ++cnt;
    }
    printf("%d\n",cnt);
    
  }
  return 0;
  
  
}

