#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN =4005; 
int A[4005],B[4005],C[4005],D[4005];
int n;
int CD[MAXN*MAXN];
void solve(){
  for(int  i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      CD[i*n+j] = C[i]+D[j];
    }
  }

  sort(CD,CD+n*n);

  long long res = 0;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      int cd = -(A[i]+B[j]);
      res += upper_bound(CD,CD+n*n,cd)-lower_bound(CD,CD+n*n,cd);
    }
    
  }
  printf("%lld\n",res);
  
  
}
int main(){
  scanf("%d",&n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d %d %d",&A[i],&B[i],&C[i],&D[i]);

  }
  
  solve();
  return 0;

}
