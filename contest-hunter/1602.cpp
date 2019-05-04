// 把每个整数看作长度为32的二进制01串，把每个串插入一棵 trie 树，遍历每一个整数
#include <iostream>

using namespace std;
const int MAX_N = 100005;
int trie[MAX_N*32][2];
int  cnt[MAX_N];
int a[MAX_N];
int n,m,idx;

void insert(int num){
  int p = 0;
  for(int i=30;~i;i--)
  {
    int ch = num >> i&1;
    int &c = trie[p][ch];
    if(!c) c = ++idx;
    p = c;
  }
}


int search(int num){
  int ret = 0,p = 0;
  for(int i = 30; ~i; i--)
  {
    int ch = num >> i&1;
    if(trie[p][!ch]){
      ret+= 1<< i;
      p = trie[p][!ch];
    }else{
      p = trie[p][ch];
    }
  }
  return ret;
  
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
    insert(a[i]);
  }
  int ans = 0;
  for(int i = 0; i < n; i++)
  {
    ans = max(ans,search(a[i]));
  }
  cout << ans << endl;
  
  return 0;
}
