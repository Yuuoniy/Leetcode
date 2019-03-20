/*
 * @Author: yuuoniy 
 * @Date: 2019-03-20 10:06:08 
 * @Last Modified by:   yuuoniy 
 * @Last Modified time: 2019-03-20 10:06:08 
 */
#include <stdio.h>
#include <string.h>


int main(){
  char num[105];
  scanf("%s",num);
  char quotient[105]={0};
  int count = 0;
  int reminder = num[0]-'0';
  int current = 0;
  if(strlen(num)<2){
    quotient[0] = '0';
    count = 1;
  }
  for(int i = 1; i < strlen(num); i++)
  {
    current = reminder*10+(num[i]-'0');
    // if(current>=13)
    quotient[count++] = current/13+'0';
    reminder = current%13;
  }
  if(quotient[0]!='0'||count==1)
    printf("%c",quotient[0]);
  for(int i = 1; i < count; i++)
  {
    printf("%c",quotient[i]);
  }
  
  printf("\n%d",reminder);
  return 0;
}

// 注意开头的 零
// 注意一位数的情况
