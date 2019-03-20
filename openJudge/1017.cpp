#include <iostream>
#include <vector>
using namespace std;

int main(){
  int input[6];
  int countZero = 0;
  int boxNum = 0;
  int area[2]={0};
  // vector<pair<int,int>>area;
  while(1){
    for(int i=0;i<6;i++){
      cin >> input[i];
      if(input[i]==0)
      ++countZero; 
    }
    if(countZero==6){
      break;
    } 
    boxNum +=input[5];
    boxNum +=input[4];
    area[0] += input[4] * 9;
    boxNum +=input[3];
    area[1] += input[3] * 10; 
    
    boxNum +=input[2]/4+input[2]%4;
    if(input[2]%4==1)
    {
      area[1]+=10;
      area[0]+=7;

    }else if(input[2]%4==2){
      area[1]+=3;
      area[0]+=6;
    }else if(input[2]%4==3){
      area[1] += 1;
      area[0]+=5;
    }
    if(input[1]<area[1]){
      area[1]-=input[1];
    }else{
      int restBox = input[1]-area[];
    }


  }
  return 0;
}
