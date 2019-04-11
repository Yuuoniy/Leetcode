#include <iostream>

using namespace std;

int p[200005],d[200005];
int minCycle =200005 ;
int n;
int find(int x){
  if(p[x]!=x){
    int par = p[x];
    p[x] = find(p[x]);
    d[x] += d[par];
  }
  return p[x];
}

void unite(int x,int y){
  int p1 = find(x);
  int p2 = find(y);
  if(p1!=p2){
    p[p1] = p2;
    d[x] = d[y]+1;
  }else{
    minCycle = min(minCycle,d[x]+d[y]+1);
  }
}
int main(){
  int i,t;
  cin >> n;
  for(int i = 1; i <=n; i++)
  {
    p[i] = i;
  }
  int tmp;
  for(int i = 1; i <=n; i++)
  {
    scanf("%d",&tmp);
    unite(i,tmp);
  }
  cout << minCycle << endl;
  return 0;
  
}
