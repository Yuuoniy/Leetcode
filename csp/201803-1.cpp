#include <iostream>
using namespace std;
int main(){
  int tmp = 0;
  int count = 0, j =0,sum = 0;
  while(~scanf("%d",&tmp)&&tmp!=0){
    if(tmp==1){
      sum+=tmp;
      j = 0 ;
    }else{
      j++;
      sum+=2*j;
    }
  }
  cout << sum;
  return 0;
}
