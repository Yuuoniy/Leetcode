#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
const int MAXN = 25;
struct node{
  int id;
  string count;
}nodes[25];


bool cmp(node& a,node& b){
  if(a.count.length()>b.count.length())
    return true;
  else if(a.count.length()<b.count.length())
    return false;
  else
    return a.count > b.count;
}

int main(){
  cin >> n;
  for(int i = 1; i <= n; i++)
  {
    nodes[i].id = i;
    cin >> nodes[i].count;
  }
  sort(nodes+1,nodes+n+1,cmp);
  // for(int i = 1; i <= n; i++)
  // {
  //   cout << nodes[i].count << endl;
  // }
  
  cout << nodes[1].id << "\n" << nodes[1].count << endl;
  return 0;
  
}
