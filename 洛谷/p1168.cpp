/*
 * @Author: yuuoniy 
 * @Date: 2019-05-17 10:16:06 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-17 10:46:54
 */

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main(){
  int n;
  cin >> n;
  priority_queue<int,vector<int>> q1;
  priority_queue<int,vector<int>,greater<int>> q2;
  int t;
  cin >> t;
  q1.push(t);
  cout << q1.top() << endl;
  for (int i = 2; i <=n; i++)
  {
    cin >> t;
    if(t>q1.top()) q2.push(t);
    else q1.push(t);
    
    while (q1.size()>q2.size()+1)
    {
     
        q2.push(q1.top());
        q1.pop();
     
        
      }
      while (q2.size()>q1.size())
      {
       q1.push(q2.top());
        q2.pop();
      }
      
    
    if(i%2) cout << q1.top() << endl;
    
  }
  return 0;
}
