// Trie 树的每个节点上存储一个整数 cnt, 记录该节点是多少个字符串的末尾节点
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int SIZE = 100005;
int trie[SIZE][30], tot = 1,End[SIZE];

void insert(char* str){
  int len = strlen(str), p =1;
  for(int k = 0; k < len; k++)
  {
    int ch = str[k]-'0';
    if(trie[p][ch]==0) trie[p][ch] = ++tot;
    p = trie[p][ch];
  }
  End[p]++;
}


int search(char *str){
  int len = strlen(str), p = 1,num = 0;
  for(int k = 0; k < len; k++)
  {
    p = trie[p][str[k]-'0'];
    if(p==0)  return num;
    num+=End[p];
  }
  return  num;
}

int main(){
  int n,m;
  char str[1000100];
  cin >> n >> m;
  for(int i = 0; i < n; i++)
  {
    cin >> str;
    insert(str);
  }
  while(m--){
    cin >> str;
    cout << search(str) << endl;
  }
  
  return 0;
}
