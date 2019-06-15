#include <cstdio>

const int MAX_N = 1005;

int c[MAX_N][MAX_N];
int f[MAX_N];

void init(){
  for(int i = 0; i <= 1000; i++)
  {
    c[i][0] = c[i][i] = 1;
    for(int j = 1; j < i; j++)
    {
      c[i][j] = (c[i-1][j]+c[i-1][j-1])%10056;
    }
  }
}

int main(){
  init();
  f[0] = 1;
  for(int i = 1; i <= 1000; i++)
  {
    f[i] = 0;
    for(int j = 1; j <=i; j++)
    {
      f[i] = (f[i]+c[i][j]*f[i-j])%10056;
    }
  }
  int T,n;
  scanf("%d",&T);
  for(int t = 0; t < T; t++)
  {
    scanf("%d",&n);
    printf("Case %d: %d\n",t+1,f[n]);
  }
  return 0;
  
}
