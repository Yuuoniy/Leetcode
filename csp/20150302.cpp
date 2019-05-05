#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct node{
  int num;
  int count;
}nodes[1005];
int n,t;
map<int,int> num_idx;

bool cmp(const node& a,const node& b){
  if(a.count==b.count)
    return a.num < b.num;
  else return a.count> b.count;
}
int main(){
  cin >> n;
  int c = 1;
  for(int i = 0; i < n; i++)
  {
    cin >> t;
    if(num_idx[t]==0) 
    {
      
      nodes[c].count = 1;
      nodes[c].num = t;
      num_idx[t] = c++;
    }else{
      ++nodes[num_idx[t]].count;
    }
  }
  sort(nodes+1,nodes+c,cmp);
  for(int i = 1; i < c; i++)
  {
      cout << nodes[i].num << " " << nodes[i].count << endl;
  }
  return 0;
  
}
