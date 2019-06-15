/*
 * @Author: yuuoniy 
 * @Date: 2019-05-16 10:41:00 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-16 11:13:33
 */

#include <iostream>
#include <queue>
using namespace std;
const int MAX_N = 1005;
int n,k;
struct node{
  int id;
  bool label;
  int time;
  bool operator <(const node& u) const{
    if(time>u.time) return true;
    if(time<u.time) return false;
    if(label>u.label) return true;
    if(label<u.label) return false;
    if(id>u.id) return true;
    return false;
  }
};

priority_queue<node> q;
int a[MAX_N];
int main(){
  cin >> n >> k;
  for (int i = 0; i <=n; i++)
  {
    a[i] = i;
  }
  
  for (int i = 0; i < k; i++)
  {
    int w,s,c;
    cin >> w >> s >> c;
    node x;
    x.id = w;
    x.label = 1;
    x.time = s;
    q.push(x);
    x.label = 0;
    x.time = s+c;
    q.push(x);
  }
  while (!q.empty())
  {
    node t = q.top();
    q.pop();
    if(t.label==0) {
      for (int i = 0; i <=n; i++)
      {
        if(a[i]==-1){ //放钥匙
          a[i] = t.id;
          break;
        }
      }
      
    }else {
      for (int i = 0; i <=n; i++)
      {
        if(a[i]==t.id){ //取钥匙
          a[i]= -1;
          break;
        }
      }
      
    }
  }
  for (int i = 1; i <=n; i++)
  {
    cout << a[i] << " ";
  }
  return 0; 
}
