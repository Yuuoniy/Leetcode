#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
  string str;
  cin >> str;
  int sum = 0;

  for(int i = 0; i < str.size(); i++)
  {

  }
  sum+=(str[0]-'0')*1;
  sum+=(str[2]-'0')*2;
  sum+=(str[3]-'0')*3;
  sum+=(str[4]-'0')*4;

  sum+=(str[6]-'0')*5;
  sum+=(str[7]-'0')*6;
  sum+=(str[8]-'0')*7;
  sum+=(str[9]-'0')*8;
  sum+=(str[10]-'0')*9;
  
  if(sum%11==str[12]-'0'||sum%11==10&&str[12]=='X')
    cout <<"Right";
  else 
  {
    if(sum%11==10)
      str[12] = 'X';
    else 
      str[12] =sum%11+'0';
    cout<< str;
  }
  return 0;
}

