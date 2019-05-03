#include <iostream>

using namespace std;
int n;

int main(){
  cin >> n;
  int ans = 0;
  for(int i = 1; i <= n; i++)
  {
   ans+=n/i;
  }
  cout << ans << endl;
  return 0;
  
}
