/*
 * @Author: yuuoniy 
 * @Date: 2019-04-11 19:59:26 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-04-11 20:10:13
 */
// 记忆化搜索
#include <iostream>
#include <memory.h>
using namespace std;

int tree[35];
int p[35][35];
int root[35][35];
int n;

long long search(int l,int r){
  if(l>r) return 1;
  long long cur_num;
  if(p[l][r]==-1){
    for(int k = l; k <= r; k++)
    {
      cur_num = search(l,k-1)*search(k+1,r)+p[k][k];
      if(cur_num>p[l][r]){
        p[l][r] = cur_num;
        root[l][r] = k;
      }
    }
  }
  return p[l][r];
}

void print_pre(int l,int r){
  if(l>r) return;
  cout << root[l][r] << " ";
  print_pre(l,root[l][r]-1);
  print_pre(root[l][r]+1,r);
}

int main(){
  cin >> n;
  memset(p,-1,sizeof(p));
  for(int i = 1; i <= n; i++)
  {
    cin >> p[i][i];
    root[i][i] = i;
  }
  cout << search(1,n) << endl;
  print_pre(1,n);
  return 0;
  
}
