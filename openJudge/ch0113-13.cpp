/*
 * @Author: yuuoniy 
 * @Date: 2019-03-20 10:06:13 
 * @Last Modified by:   yuuoniy 
 * @Last Modified time: 2019-03-20 10:06:13 
 */
#include <stdio.h>

int main(){
  int num[6] = {0};
  int sum = 0;
  scanf("%d",&sum);
  num[0] = sum/100;
  sum = sum%100;
  num[1] = sum/50;
  sum = sum%50;
  num[2] = sum/20;
  sum = sum%20;
  num[3] = sum/10;
  sum = sum%10;
  num[4] = sum/5;
  sum = sum%5;
  num[5] = sum/1;
  sum = sum%1;
  for(int i = 0; i < 5; i++)
  {
    printf("%d\n", num[i]);
  }
  printf("%d",num[5]);
  return 0;
}
