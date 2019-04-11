/*
 * @Author: yuuoniy 
 * @Date: 2019-04-11 20:26:45 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-04-11 20:40:18
 */
#include <iostream>
#include <string>
using namespace std;

string strs[30];

struct node{
  char l,r;
}nodes[130];

char r,root;
void print_pre(char r){
  if(r=='*') return;
  cout << r;
  print_pre(nodes[r].l);
  print_pre(nodes[r].r);
}

int main(){
  int n;
  cin >> n;
  cin >> root;
  cin >> nodes[root].l >> nodes[root].r;
  for(int i = 1; i < n; i++)
  {
    cin >> r;
    cin >> nodes[r].l >> nodes[r].r;
  }
  print_pre(root);
  return 0;
  
  
}
