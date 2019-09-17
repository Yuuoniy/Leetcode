#include <iostream>
#include <list>
#include <vector>

// https://www.cnblogs.com/meelo/p/7635746.html
// list 的使用
using namespace std;

int main(){
  int n,m;
  scanf("%d%d",&n,&m);
  list<int> lst;
  vector<list<int>::iterator> vec(n+1);
  for(int i=1;i<=n;i++){
    lst.push_back(i);
    vec[i] = --lst.end();
  }
  for (int i = 0; i < m; i++)
  {
    int p,q;
    scanf("%d%d",&p,&q);
    list<int>::iterator inpos = vec[p];
    if(q>0){
      q++;
      while (q)
      {
        inpos++;
        q--;
      }
      
    }else if(q<0){
      while (q)
      {
        inpos--;
        q++;
      } 
    }
    lst.splice(inpos,lst,vec[p]);
  }
  for(list<int>::iterator it=lst.begin();it!=lst.end();it++){
    printf("%d ",*it);
  }
  return 0;
  
}
