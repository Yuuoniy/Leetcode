/*
 * @Author: yuuoniy 
 * @Date: 2019-05-16 17:40:38 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-16 17:51:39
 */

// 单调栈算法

#include <iostream>
#include <algorithm>
using namespace std;

int a[1005];
int s[1005];
int w[1005];
int p,n;
long long ans;
void solve(){
  a[n+1] = p = 0;
  for (int i = 1; i <=n+1; i++)
  {
    if (a[i]>s[p])
    {
      s[++p] = a[i];
      w[p] = 1;
    }else{
      int width = 0;
      while (s[p]>a[i])
      {
        width+=w[p];
        ans = max(ans,(long long)width*s[p]);
        --p;
      }
      s[++p] = a[i];
      w[p] = width+1;
    }
    
  }
  
}
int main(){
  cin >> n;
  for (int i = 1; i <=n; i++)
  {
    
    cin >> a[i];
  }

  solve();
  cout << ans;
  return 0;
}
