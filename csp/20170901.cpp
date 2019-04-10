#include <iostream>
using namespace  std;

int main(){
  int n;
  cin >> n;
  int num = n/10;
  int a = num/5*2;
  int b = (num%5)/3;
  cout << num+a+b ;
  return 0;
}
