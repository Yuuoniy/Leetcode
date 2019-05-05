#include <iostream>

using namespace std;


int month_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

bool is_leap_year(int y){
  return (y%4==0&&y%100!=0||y%400==0);
}


int main(){
  int y,d;
  cin >> y >> d;
  if(is_leap_year(y)){
    month_day[1] = 29;
  }
  int m,day,i=0;
  while(d>month_day[i]){
    d-=month_day[i++];
  }
  cout << i+1 << endl << d;
  return 0;
  
}
