#include <iostream>

using namespace std;

const int MAX_N = 205;
const int M = 10001;
int T, x[MAX_N];


void solve(){
  for(int a = 0; a < M; a++)
  {
    for(int b = 0; b < M; b++)
    {
      bool c = 1;
      for(int i = 2; i <=T*2; i+=2)
      {
        x[i] = (a*x[i-1]+b)%M;
        if(i+1<=T*2&&x[i+1]!=(a*x[i]+b)%M)
        {
          c = 0;
          break;
        }
      }
      if(c) return; 
    }
  }
}

int main(){
  while(cin>>T){
    for(int i = 1; i <=T*2-1; i+=2)
    {
      cin >> x[i];
    }
    solve();
    for(int i = 2; i <=T*2; i+=2)
    {
      cout  << x[i] << endl;
    }    
  }
  return 0;
}
