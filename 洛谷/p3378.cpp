/*
 * @Author: yuuoniy 
 * @Date: 2019-04-19 10:11:29 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-04-19 10:14:17
 */
// priority_queue<int,vector<int>,greater<int> >q

#include <iostream>
#include <algorithm>

using namespace std;


int size = 0;
int heap[1000005]={0};


void print_top(){

  printf("%d\n",heap[0]);
}

void delete_top(){
  pop_heap(heap,heap+size,greater<int>());
  --size;
}

void add_num(int new_num){
  heap[size++] = new_num;
  push_heap(heap,heap+size,greater<int>());
  
}
int main(){
  int n,op,new_num;
  scanf("%d",&n);
  for(int i = 0; i < n; i++)
  {
   scanf("%d",&op);
    if(op==1){
      scanf("%d",&new_num);
      add_num(new_num);


    }else if(op==2){
      print_top();
    }else{
      delete_top();
    }
  }
  
  return 0;
}
