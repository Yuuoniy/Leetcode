#include <cmath>
#include <iostream>
using namespace std;


int divide(int& n,int d){
  int x = 1;
  while(n%d==0){
    n/=d;
    x*=d;
  }
  return x;
}



long long solve(int n){
  if(n==1) return 2;
  int m = floor(sqrt(n)+0.5);
  long long ans = 0;
  int c = 0; //质因子个数
  for(int i = 2; i < m; i++)
  {
    if(n%i==0){
      ++c;
      ans+=divide(n,i);
    }
  }
  if(n>1) {
    ++c;
    ans+=n;
  }
  if(c<=1) ++ans;
  return ans;
}

int main(){
  int n,t = 0;
  while(cin>> n&&n){
    cout << "Case " << ++t << ": " << solve(n) << endl;
  }
  return 0;
  
}
