/*
 * @Author: yuuoniy 
 * @Date: 2019-03-20 10:06:00 
 * @Last Modified by:   yuuoniy 
 * @Last Modified time: 2019-03-20 10:06:00 
 */
// 不吉利的日期
// 思路：计算每个月的 13 距离 1 月 1 号有几天，根据天数判断是星期几
#include <stdio.h>

int main(){
  int days[12] ={31,28,31,30,31,30,31,31,30,31,30,31};
  int whichday = 0;
  scanf("%d",&whichday);
  int theReslut[12] = {0};
  int count = 0;//count how many months
  int theDaytoFigure = 13-1;
  for(int i = 1; i < 13; i++)
  {
    if((theDaytoFigure+whichday)%7==5){
      theReslut[count++] = i;
    }
    theDaytoFigure+=days[i-1];
  }
  for(int i = 0; i < count-1; i++)
  {
    printf("%d\n",theReslut[i]);
  }
  printf("%d",theReslut[count-1]);
  return 0;
  
}
