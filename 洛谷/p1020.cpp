#include <algorithm>
#include <stdio.h>

using namespace std;

int height[100005];
int mem[100005][50005];
int main() {

  int n = 0;
  while (scanf("%d", &height[n]) != EOF) {
    ++n;
  }
  int count = 0, preheight = 50005;
  memset(mem, -1, sizeof(mem));
  for (int i = 0; i < n; i++) {
    if (preheight >= height[i]) { //可以拦截当前的,也可以选择不拦截,状态转移方程是怎么样呢。。
      mem[i][height] = count+1;
      preheight = height[i];
      else 
        mem[i+1][height]
    }
  }
}
