/*
 * @Author: yuuoniy
 * @Date: 2019-06-16 15:32:01
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-16 15:37:44
 */

#include <iostream>
#include <map>

using namespace std;

const int MAX_N = 205;
map<int, int> info;
int num[MAX_N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    num[i] = x;
    info[x]++;
  }

  for (int i = 0; i < n; i++) {
    if (info[num[i]] == 1)
      cout << "BeiJu" << endl;
    else
      cout << info[num[i]] - 1 << endl;
  }

  return 0;
}
