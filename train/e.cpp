#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

long long n, k;
const int MAX_N = 100005;
long long value[MAX_N];
int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  cin >> n >> k;
  long long max_node = 0;
  long long idx;
  long long total = 0;
  for (int i = 0; i < n; i++) {
    cin >> value[i];
    total += value[i];
    if (value[i] > max_node) {
      idx = i;
      max_node = value[i];
    }
  }
  long long lower = idx;
  long long upper = 0;
  for (int i = 0; i < idx; i++) {
    upper += value[i];
  }

  while (k > upper) {
    upper += total;
    lower += value[idx] + (n - 1);
  }
  if (k < lower) {
    cout << "KEK";
  } else if (k >= lower && k <= upper) {
    cout << "YES";
  }
  return 0;
}
