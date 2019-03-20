/*
 * @Author: yuuoniy 
 * @Date: 2019-03-13 16:37:14 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-03-19 00:01:58
 */
// 模拟题,主要是 map 的使用
// 使用 map, 将所有好插入 map 中，然后按照要求遍历输出
#include <cstdio>
#include <map>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
  int n = 0;
  scanf("%d",&n);
  int tmpNum;
  char s[80] ;
  map<int,int> numberMap; 
  for(int i = 0; i < n; i++)
  {
    tmpNum = 0;
    scanf("%s",&s);
    for(int j = 0; j < strlen(s); j++)
    {
      if(s[j]>='0'&&s[j]<='9'){
        tmpNum = tmpNum*10+(s[j]-'0');
      }else if(s[j]>='A'&&s[j]<='Z'){
        tmpNum =tmpNum*10+ ((s[j]-'A'-(s[j]>'Q'))/3+2);
      }
    }
    numberMap[tmpNum]++ ;  //统计出现的频率
  }
    int flag = 1;
    for(map<int,int>::iterator it = numberMap.begin(); it != numberMap.end(); it++)
    {
      if(it->second>=2){
        flag = 0;
        printf("%03d-%04d %d\n", it->first/10000, it->first%10000, it->second);
      }
    }
    if(flag){
      printf("No duplicates.\n");
    }
    return 0;
}

// 用 map string 超时了，改为用 int!
