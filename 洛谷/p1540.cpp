#include <iostream>
#include <stdio.h>

using namespace std;

int n,m;
int a[1005]={0}; //记录某单词是否在内存中
int b[1005]={0};// 记录对应时间存入的单词
int count;//记录已有的单词
int main(){
  cin >> m >> n;
  int w;
  int left = 0;
  int count = 0;
  int in = 0; //直接 
  //先初始化第一单词
  cin >> w;
  if(m>=1){
    b[left] = w;
    a[w] = 1;
    ++count;
  }
  for(int i = 1; i < n; i++)
  {
    cin >> w;
    if(a[w]==1){
      ++in;
      continue;
    } 
    if(a[w]==0){
      if(count<m){
        a[w] = 1;
        b[left+count] = w;
        ++count;
      }else if(count==m){
        a[b[left]]=0;
        a[w] = 1;
        b[left+count] = w;
        ++left;
      }
    }
  }
  cout << n-in ;
  return 0;
}
