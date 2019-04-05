// 思路：先存储所有的地毯数据，根据坐标从后往前模拟

#include <iostream>
using namespace std;

int n;
int map[10001][4];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 4; ++j) {
      cin >> map[i][j];
    }
  }
  int x, y;
  cin >> x >> y;
  for (int i = n; i > 0; i--) {
    // cout << x << " " << y << " " << map[i][0] << " " << map[i][0] + map[i][2]
        //  << " " << map[i][1] << " " << map[i][3] + map[i][1] << " " << endl;
    if (map[i][0] <= x && (map[i][0] + map[i][2]) >= x && map[i][1] <= y &&
        (map[i][3] + map[i][1]) >= y) {
      cout << i;
      return 0;
    }
  }
  cout << "-1";
  return 0;
}

// 简单粗暴的方法，直接模拟，但是不能AC,所以要考虑优化
// #include <iostream>
// #include <memory.h>
// using namespace std;

// int map[10005][10005];
// int n;
// int main(){
//   cin >>n;
//   int a,b,g,k;
//   memset(map,-1,sizeof(map));
//   for(int i = 1; i <= n; i++)
//   {
//     cin >> a >> b >>g >>k;
//     for(int j = 0; j<k; j++)
//     {
//       for(int l = 0; l < g; l++)
//       {
//         map[a+j][b+l] = i;
//       }

//     }

//   }

//   int x,y;
//   cin >> x >> y;
//   cout << map[x][y];
//   return 0;

// }
