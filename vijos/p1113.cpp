/*
 * @Author: yuuoniy 
 * @Date: 2019-06-14 10:50:02 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-14 10:55:09
 */


#include <iostream>

using namespace std;

int main(){
  bool happy = true;
  int tot = -1;
  int ans = 0;
  for (int i = 0; i < 7; i++)
  {
    int x,y ;
    scanf("%d%d",&x,&y);
    if(x+y>8) {
      happy = false;
      if(x+y>tot){
        ans = i+1;
        tot = x+y;
      }
    }
  }
  if(happy) cout << 0 << endl;
  else cout << ans << endl;
  return 0;

}
