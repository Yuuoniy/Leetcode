#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int nums[10]={0};
int minNum = 100000;
int n;
vector<int> q;

void dfs(vector<int>q,int times){
  cout << "back " << q.back() << endl;
  if(minNum==0) return;
  if(times==0) {
    int num = 0;
    for(int i = 0; i < q.size(); i++)
    {
     if(q[i]!=-1){
       cout << "is " << q[i] << endl;
       if(minNum>q[i])
      {
        minNum = q[i];
      }
      return;
     }
    }
  }
  else
  {
    for(int i = 0; i < q.size()-1; i++)
    {
      if(q[i]==-1) continue;
      for(int j = i+1; j < q.size(); j++)
      {
        if(q[j]==-1) continue;
        int x = q[i];
        int y = q[j];
        q[i]=q[j]=-1;
        int a1 = x+y;
       int a2 = abs(x-y);
       int a3 = x*y;
      vector<int> q1=q;
      vector<int> q2=q;
      vector<int> q3=q;
      q1.push_back(a1);
      q2.push_back(a2);
      q3.push_back(a3);
         dfs(q1,times-1);
    dfs(q2,times-1);
    dfs(q3,times-1);
      }
      
    }
    
   
 
  }
  
}


int main(){
  int t;
  scanf("%d",&t);
  int tmp;
  while(t--){
    scanf("%d",&n);
    minNum = 100000;
    q.clear();
    
    for(int i = 0; i < n; i++)
    {
      scanf("%d",&tmp);
      q.push_back(tmp);
    }
    dfs(q,n-1);
    if(t!=0)
      printf("%d\n",minNum);
    else
      printf("%d",minNum);

  }
  return 0; 
}
