#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int nums[10]={0};
int minNum = 100000;
queue<int> q;

void dfs(queue<int>q){
  if(q.size()==1) {
    if(minNum >q.front())
    minNum = q.front();
    return;
  }
  else
  {
    int x = q.front();q.pop();
    int y = q.front();q.pop();
    int a1 = x+y;
    int a2 = abs(x-y);
    int a3 = x*y;
    queue<int> q1=q;
    queue<int> q2=q;
    queue<int> q3=q;
    q1.push(a1);
    q2.push(a2);
    q3.push(a3);
    dfs(q1);
    dfs(q2);
    dfs(q3);
  }
  
}


int main(){
  int t;
  int n;
  scanf("%d",&t);
  int tmp;
  while(t--){
    scanf("%d",&n);
    minNum = 100000;
    for(int i = 0; i < n; i++)
    {
      scanf("%d",&tmp);
      q.push(tmp);
    }
    dfs(q);
    if(t!=0)
    printf("%d\n",minNum);
else
    printf("%d",minNum);

  }
  return 0;
}
