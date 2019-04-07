/*
 * @Author: yuuoniy 
 * @Date: 2019-03-20 14:33:34 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-03-20 21:55:26
 */
// 15:求序列中的众数
// 思路：对输入的数字进行标准化处理，对于每个数字，将其与之后的所有数字比较，计数
// 正常思路就好了
// 注意字符串后面的\0,如果用了 strncpy 是不会自动加 \0 的，会影响结果！还有 strncmp 后面不一样的不会管，如果是真的要比较是否完全相等就不能用！


#include <stdio.h>
#include <map>
#include <cstring>

struct strCount{
  int count;
  char str[10000];
}strcount[129];

void process(char *str){
  int start = 0,sign = 1;
  char tmp[1000];
  if(str[0]=='+'||str[0]=='-') ++start;
  if(str[0]=='-') sign = 0;
  while(str[start]=='0') ++start;
  int len= 0;
  if(sign==0){
    tmp[0]='-';
    ++len;
  }

  for(int i = start;str[i]!='\0';i++){
    tmp[len++] = str[i];

  }
  tmp[len] = '\0';
  if(strcmp(tmp,"-")==0||strcmp(tmp,"")==0)
    strcpy(tmp,"0");
  strcpy(str,tmp);
}

int main(){
  int n = 0;
  scanf("%d",&n);
  // char [10000];
  int currentNum = 0;
  for(int i = 0; i < n; i++)
  {
    char str[10000];
    scanf("%s",str);
    if(strlen(str)==0) continue;
    process(str);
    int j =0;
    for(j = 0; j < currentNum; j++)
    {
     if(strcmp(strcount[j].str,str)==0){
       strcount[j].count++;
       break;   
     }
    }
    if(j>=currentNum){ // not same with the previous
      strcpy(strcount[currentNum].str,str);
      strcount[currentNum].count=1;
      currentNum++;
    }
    
  }
  if(currentNum==1&&n>currentNum) printf("no\n");
  else{
    int max = 0;
    for(int i = 0; i < currentNum; i++)
    {
      if(strcount[i].count>strcount[max].count) 
        max = i;
    }
    printf("%s\n",strcount[max].str);
    return 0;
  }
}
