#include <stdio.h>
#include <queue>
using namespace std;
typedef long long ll;
const int MAXN = 20005;
int n;
int l[MAXN];


void solve(){
  ll ans = 0;
  priority_queue<int, vector<int>, greater<int> >que;
  for(int i = 0; i < n; i++)
  {
    que.push(l[i]);
  }
  while(que.size()>1){
    int l1,l2;
    l1 = que.top();
    que.pop();
    l2 = que.top();
    que.pop();
    ans+=l1+l2;
    que.push(l1+l2);
  }
  printf("%lld\n",ans);
}

int main(){
  scanf("%d",&n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d",&l[i]);
  }
  solve();
}
