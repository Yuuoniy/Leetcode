#include <iostream>
#include <cmath>

using namespace std;
int x,y;

int gcd(int x,int y){
  if(y==0) return x;
  return gcd(y,x%y);
}

int main(){
  int ans = 0;
  cin >> x >>y;
  for(int i = 1; i <=sqrt(x*y); i++)
  {
    if((x*y)%i==0&&gcd(i,(x*y)/i)==x) ++ans;
  }
  cout << ans*2;

  return 0;
}
