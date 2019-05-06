// fill_n lower_bound, end begin 的使用
// 素数间隔
#include <cstdio>
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;
const int MAX_N = 1299709+4;
vector<int> primes;
bool isprime[MAX_N];

void sieve(){
  isprime[2] = 1;
  fill_n(isprime, MAX_N, 1);
  for(int i = 2; i < MAX_N; i++)
  {
    if(isprime[i])
      primes.push_back(i);
    long long j = i;
    for(j *=i; j < MAX_N; j+=i)
    {
      isprime[j] = 0;
    }
    
  }
  
}


int solve(int n){
  if(isprime[n]) return 0;
  auto p = lower_bound(begin(primes),end(primes),n);
   assert(p != end(primes));
  assert(p != begin(primes));
  // cout << *p << " " << *(p-1) << endl;
  return *(p)-*(p-1);
}

int main(){
  sieve();
  int n;
  while(scanf("%d",&n)==1&&n){
    printf("%d\n",solve(n));
  }
  return 0;
  
}
