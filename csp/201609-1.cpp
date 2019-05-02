#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
  int res;
  int x,y,c;
  int n;
  cin >> n;
  cin >> x >> y;
  res = abs(y-x);
  for(int i = 2; i < n; i++)
  {
    cin >> c;
    res = max(res,abs(y-c));
    y = c;
  }
  printf("%d\n",res);
  return 0;
}
