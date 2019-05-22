/*
 * @Author: yuuoniy 
 * @Date: 2019-05-16 15:26:52 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-16 15:30:31
 */
#include <iostream>

using namespace std;
const int MAX_N = 10005;
int n;
int a[MAX_N];
int main(){
    cin >> n;
    int t;
    for (int i = 0; i < n; i++)
    {
      cin >> t;
      a[t] = 1;
    }
    int ans = 0;
    for (int i = 0; i < MAX_N-1; i++)
    {
      if(a[i]&&a[i+1])
        ++ans;
    }
    
    cout << ans << endl;
    return 0;
}
