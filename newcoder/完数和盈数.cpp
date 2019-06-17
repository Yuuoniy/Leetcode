/*
 * @Author: yuuoniy 
 * @Date: 2019-06-16 09:36:48 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-16 09:47:05
 */


#include<iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
  vector<int> v1,v2;
  v2.push_back(2);

  for (int i = 2; i <=60; i++)
  {
    int tmp = i;
    for (int j = 1; j <i; j++)
    {
      if(i%j==0){
        tmp-=j;
      }
    }
      // cout << tmp << endl;
    if(tmp==0) {
      v1.push_back(i);
    }else if(tmp<0){
      v2.push_back(i);
    }
    
  }
  cout << "E: ";
  for (auto i:v1)
  {
    printf("%d ",i);
  }
  
  cout << "G: ";
  for (auto i:v2)
  {
    printf("%d ",i);
  }

  
}
