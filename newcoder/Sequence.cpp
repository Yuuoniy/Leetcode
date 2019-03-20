#include <iostream>

using namespace std;

int main(){
  int p,q,k;
  long long a[1000];
  cin >> a[0] >> a[1] >> p >> q >> k;
  for(int i =2;i<=k;i++){
    a[i] = p * a[i - 1] % 10000 + q * a[i - 2] % 10000;
  }
  cout << a[k]%10000 << endl;

}
