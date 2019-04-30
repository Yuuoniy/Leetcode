// 贪心+二分
#include<iostream>
#include <algorithm>
using namespace std;
const int MAXN  =  100005;

int n,c;
const int INF =1000000000;
long long l[MAXN];

//判断是否满足条件
bool C(int d){
  int last = 0;
  for(int i = 1; i < c; i++)
  {
    int crt = last+1;
    while(crt<n&&l[crt]-l[last]<d){
      crt++;
    }
    
    if(crt==n) return false;
    last = crt;
  }
  return true;
  
}


void solve(){
  // 排序
  sort(l,l+n);
  int lb = 0,ub = INF;
  while(ub-lb>1){
    int mid = (lb+ub)/2;
    if(C(mid)) lb = mid;
    else ub=mid;
  }
  printf("%d\n",lb);
  
}

int main(){
  scanf("%d %d",&n,&c);
  for(int i = 0; i < n; i++)
  {
    scanf("%d",&l[i]);
  }
  
  solve();

}
