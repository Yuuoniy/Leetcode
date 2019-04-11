/*
 * @Author: yuuoniy 
 * @Date: 2019-04-11 02:22:56 
 * @Last Modified by:   yuuoniy 
 * @Last Modified time: 2019-04-11 02:22:56 
 */
#include <iostream>
#include <stdio.h>
using namespace std;
#define INT_MAX 10000005
int num[1005];
int copynum[1005];
// int tmp[1005];
int n;
int findMin(){
  int min = INT_MAX;
  int idx = -1;
  for(int i = 0; i < n; i++)
  {
    if(num[i]!=-1&&num[i]<min){
      min = num[i];
      idx = i;
    }
  }
  num[idx] = -1;
  return idx;
}

int main(){
  cin >> n;
  int tmp;
  for(int i = 0; i < n; i++)
  {
    cin >> tmp;
    num[i] = tmp;
    copynum[i] = tmp;
  }
  // int tmp=num;
  int count=0;
  for(int i = 0; i < n; i++)
  {
    int idx = findMin();
    cout << idx+1 << " ";
    count+=copynum[idx]*(n-i-1);
  }
  cout << endl;
  printf("%.2f",(float)count/n);
  return 0;

  
}
