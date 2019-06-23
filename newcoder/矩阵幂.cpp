/*
 * @Author: yuuoniy
 * @Date: 2019-06-19 11:08:28
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-19 12:51:48
 */

#include <iostream>
#include <cstring>
#include <string>


using namespace std;

const int maxn = 20;

struct Mat {
  int mat[maxn][maxn];
  int row, col;
};

Mat mod_mul(Mat a, Mat b) {
  Mat ans;
  ans.row = a.row;
  ans.col = b.col;
  memset(ans.mat, 0, sizeof(ans.mat));
  for (int i = 0; i < ans.row; i++) {
    for (int j = 0; j < ans.col; j++) {
      for (int k = 0; k < a.col; k++) {
        ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
      }
    }
  }
  return ans;
}

Mat mod_pow(Mat a, int k) {
  Mat ans;
  ans.row = a.row;
  ans.col = a.col;
  for (int i = 0; i < a.row; i++) {
    for (int j = 0; j < a.col; j++) {
      ans.mat[i][j] = (i == j); //单位矩阵
    }
  }
  // 快速幂
  while (k) {
    if (k & 1)
      ans = mod_mul(ans, a);
    a = mod_mul(a, a);
    k >>= 1;
  }
  return ans;
}

int n, k;
int main() {
  Mat m;
  while (cin >> n >> k) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> m.mat[i][j];
      }
    }
    m.col = m.row = n;
    Mat ans = mod_pow(m, k);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if(j!=0) printf(" ");
        printf("%d",ans.mat[i][j]);
      }
      printf("\n");
      
    }
    
  }
  return 0;
}
