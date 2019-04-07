#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int,vector<int>,greater<int> >q;
int main(){
  int n,tmp;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> tmp;
    q.push(tmp);
  }
  int ans = 0;
  while(q.size()>=2){
    int x  = q.top();
    q.pop();
    int y = q.top();
    q.pop();
    ans+=x+y;
    q.push(x+y);
  }
  cout << ans;
  return  0;
  
  

}
