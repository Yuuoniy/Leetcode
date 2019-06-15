#include <iostream>
#include <set>
#include <cstdio>
#include <string>
#include <cstring>
const int MAX_N  = 100005;

long long dp[MAX_N];

using namespace std;

set<string> dir;
int mod = 1000000007;

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
  printf("%d",mod);
  return 0;
}
