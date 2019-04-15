#include <iostream>

using namespace std;

int main(){
  int n;
  scanf("%d",&n);
  int cur = 0,tmp=0;
  scanf("%d",&cur);
  int ans = cur;
  if(cur>0)  tmp = cur;
  for(int i = 1; i < n; i++)
  {
    scanf("%d",&cur);
    tmp+=cur;
    if(tmp>ans) ans = tmp;
    if(tmp <0) tmp = 0;
  }
  
  printf("%d",ans);
  return 0;
}
