#include <iostream>
using namespace std;

long long n;
int main(){
  cin >> n;
  int ans = 0;
  while(n){
    ans +=n%10;
    n/=10;
  }
  cout << ans;
  return 0;
}
