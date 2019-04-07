/*
 * @Author: yuuoniy 
 * @Date: 2019-03-20 10:06:18 
 * @Last Modified by:   yuuoniy 
 * @Last Modified time: 2019-03-20 10:06:18 
 */
#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include<iostream>
using namespace std;

int getlcm(int a,int b){
  if(a<b)
    return getlcm(b,a);
  int tmp = b;
  int max = a,min = b;
  while(max%min!=0){
    tmp = max%min;
    max = min;
    min = tmp;
  }
  tmp = a*b/tmp;
  // cout <<  a << " " << " " << tmp << endl;
  return tmp;
}
int getgcd(int a,int b){
  if(a<b)
    return getgcd(b,a);
  int tmp = 1;
  int max = a,min = b;
  while(max%min!=0){
    tmp = max%min;
    max = min;
    min = tmp;
  }
  // cout << min << endl;
  return min;
}


int main(){
  int n = 0;
  scanf("%d",&n);
  queue<pair<int,int>> nums;
  int firsta = 0,firstb = 0;
  int seconda = 0,second = 0;
  char tmp;
  for(int i = 0; i < n; i++)
  {
    scanf("%d%c%d",&firsta,&tmp,&firstb);
    nums.push(make_pair(firsta,firstb));
  }
  while(nums.size()>1){
    pair<int,int> first = nums.front();
    nums.pop();
    pair<int,int> second = nums.front();
    nums.pop();
    int lcm =  getlcm(first.second,second.second);
    int suma = lcm/first.second*first.first+lcm/second.second*second.first;
    int sumb = lcm;
    nums.push(make_pair(suma,sumb));
  }
  if(nums.front().first%nums.front().second==0)
    printf("%d",(nums.front().first)/(nums.front().second));
  else  {
    int gcd = getgcd(nums.front().first,nums.front().second);
    // cout << gcd << endl;
    printf("%d%c%d",nums.front().first/gcd,'/',nums.front().second/gcd);
  }
  return 0;
  
  
}
