#include <iostream>
using namespace std;

int main(){
  int k = 0;
  int sum = 0;
  cin >> k;
  for(int i=1;i<=k;i++){
    sum+=i*i*i;
  }
  cout << sum << endl;
  return 0;
}
