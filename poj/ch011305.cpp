#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

bool isPrime(int n){
  for(int i=2;i<=sqrt(n);i++){
    if(n%i==0)
      return false;
  }
  return true;
}

bool isCycle(int n){
  stringstream ss;
  string str;
  ss << n;
  ss >> str;
  for(int i = 0; i < str.size()/2; i++)
  {
    if(str[i]!=str[str.size()-1-i]){
      return false;
    }
  }
  return true;
}

int main(){
  
  int n = 0,count = 0;
  cin >>  n;
  for(int i = 11; i < n; i++)
  {
    if(isPrime(i)&&isCycle(i)){
      cout << i << endl;
      ++count;
    }
  }
  cout << count;
  return 0;
  
}
