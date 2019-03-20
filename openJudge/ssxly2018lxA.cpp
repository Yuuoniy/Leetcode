#include <iostream>
#include <math.h>
using namespace std;

int main(){
  int min = 0,max = 0;
  cin >> min >> max;
  if(min>max){
    int tmp = min;
    min = max;
    max = tmp;
  }
  int count = 0;
  for(int i=min;i<=max;i++){
    int flag = 1;
    for(int j=2;j<=sqrt(i);j++){
      if (i%j==0) {
        flag = 0;
        break;
      }
    }
      if(i!=1&&flag){
        count++;
      }
  }
  cout << count;
  return 0;
}
// 注意是 <= max
