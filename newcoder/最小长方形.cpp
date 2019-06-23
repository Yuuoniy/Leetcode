/*
 * @Author: yuuoniy
 * @Date: 2019-06-21 23:54:17
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-22 00:08:45
 */

#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  int x, y;
  int min_x, max_x, min_y, max_y;
  while (scanf("%d %d", &x, &y)) {
    if (x == 0 && y == 0)
      break;
     max_x =x;
      min_x = x;
      max_y = y;
      min_y = y; 
    while (scanf("%d %d", &x, &y) != EOF) {
        if(x==0&&y==0) break;
      max_x = max(max_x, x);
      min_x = min(min_x, x);
      max_y = max(max_y, y);
      min_y = min(min_y, y);
    }
    printf("%d %d %d %d\n",min_x,min_y,max_x,max_y);
  }
  return 0;
}
