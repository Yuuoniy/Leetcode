#include  <iostream>

using namespace std;
int n,ans;

int main(){
  cin >> n;
  int x,y;
  cin >> x;
  ans = 1;
  for(int i = 0; i < n-1; i++)
  {
    cin >> y;
    if(x==y) continue;
      ++ans;
      x = y;
  }
  cout << ans;
  return 0;

}
