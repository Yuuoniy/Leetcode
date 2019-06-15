// list 使用 sort 函数
// sscanf 函数使用，返回值 %[] 
// mask 移位等处理
// 用 int 存储而不是 string
#include <cstdio>
#include <cstring>
#include <string>
#include <list>
#include <iostream>
using namespace std;

struct IP{
  int prefix;
  unsigned int ip;
  IP():prefix(-1){}
};


bool cmp(const IP& a, const IP& b){
  if(a.ip!=b.ip){
    return a.ip < b.ip;
  }else if(a.prefix!=b.prefix){
    return (a.prefix)< (b.prefix);
  }else{
    return false;
  }
}

//计算子网掩码

unsigned int get_mask(int prefix){
  if(prefix==0) return 0;
  if(prefix==32) return 0xffffffff;
  unsigned int mask = 0;
  for(int i = 0; i < prefix; i++)
  {
    mask = (mask<<1)+1;
  }
  return mask<< (32-prefix);
}

void format(char str[20],list<IP> &ip_list){
  unsigned int dec[4] = {0};
  char ip_str[20];
  IP tmp;
  //sscanf 格式化
  sscanf(str,"%[^/]/%d",ip_str,&tmp.prefix);
  //sscanf 返回了成功读到几个数
  int cnt = sscanf(ip_str,"%u.%u.%u.%u",&dec[0],&dec[1],&dec[2],&dec[3]);
  if(tmp.prefix==-1) tmp.prefix = cnt*8;
  tmp.ip = (dec[0]<<24)^(dec[1]<<16)^(dec[2]<<8)^dec[3];
  ip_list.push_back(tmp);
}

void print_ip(IP ip){
  unsigned int dec[4] = {0xff000000,0x00ff0000,0x0000ff00,0x000000ff};
  printf("%u.%u.%u.%u/%d\n",(ip.ip&dec[0])>>24,(ip.ip&dec[1])>>16,(ip.ip&dec[2])>>8,(ip.ip&dec[3]),ip.prefix);
}

void print_list(list<IP> &ip_list){
  for(list<IP>::iterator it = ip_list.begin(); it!= ip_list.end(); it++)
  {
   print_ip(*it);
  }
}

//合并子集包含的网段
void merge1(list<IP> &ip_list){
  list<IP>::iterator itL;
  list<IP>::iterator itR = ip_list.begin();
  itR++;
  for( itL = ip_list.begin(); itL!=ip_list.end();)
  {
    unsigned int mask = get_mask((*itL).prefix);
    if(((*itL).ip&mask)==((*itR).ip&mask)){ //注意括号。。
      ip_list.erase(itR++);
    }else{
      itL++;
      itR++;
    }
  }
  
}

void merge2(list<IP> &ip_list){
  list<IP>::iterator itL;
  list<IP>::iterator itR = ip_list.begin();
  itR++;
  for(itL  = ip_list.begin(); itL!=ip_list.end();)
  {
    unsigned int mask = get_mask((*itL).prefix-1); //合并后的掩码
  
    if((*itL).prefix==(*itR).prefix && ((*itL).ip&mask)==((*itR).ip&mask)){
      (*itL).prefix--; //合并
      ip_list.erase(itR++);
      if(itL!=ip_list.begin()){
        itL--;
        itR--;
      }
    }else{
      itL++;
      itR++;
    }
  }
  
}

int main(){
  list<IP> ip_list;
  int n,i;
  char str[20];
  scanf("%d",&n);
  getchar();
  for(int i = 0; i < n; i++)
  {
    scanf("%s",str);
    format(str,ip_list);
  }
   ip_list.sort(cmp);
   merge1(ip_list);
   merge2(ip_list);
   print_list(ip_list);
   return 0;

}
