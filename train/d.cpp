#include <iostream>
#include <set>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;
const int MAX_N  = 100005;
long long dp[MAX_N];
set<string> dir;
long long mod = 1000000007;

void init(){
  dir.insert("N");
  dir.insert("S");
  dir.insert("E");
  dir.insert("W");
  dir.insert("NE");
  dir.insert("SE");
  dir.insert("SW");
  dir.insert("NW");
}

int main(){
  string str;
  init();
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  cin >> str;
  dp[0] = dp[1] = 1;
  for (int i = 2; i <= str.size(); i++)
  {
    string tmp = str.substr(i-2,2);
    if(dir.count(tmp)!=0){
      dp[i] = (dp[i-1]+dp[i-2])%mod;
    }else{
      dp[i] = dp[i-1]%mod;
    }
  }

  printf("%d",dp[str.size()]);
  return 0;
}
