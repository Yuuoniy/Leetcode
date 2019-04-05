#include <iostream>
#include <sstream>

#include <math.h>
using namespace std;
int n;
int a[105];
int main() {
  cin >> n;
  string str;

  stringstream ss;
  for (int i = n; i >= 0; --i) {
    cin >> a[i];
    if (i == n) {
      if (abs(a[i]) != 1)
        ss << a[i];
      else {
        if (a[i] < 0)
          ss << "-";
      }
      if (i == 1)
        ss << "x" ;
      else
        ss << "x^" << i;
    } else if (a[i] != 0 && i != 0) {
      if (a[i] > 0) {
        ss << "+";
        if (a[i] != 1)
          ss << a[i];
      } else {
        if (a[i] != -1)
          ss << a[i];
        else
          ss << "-";
      }
      if (i == 1)
        ss << "x" ;
      else
        ss << "x^" << i;
    } else if (a[i] != 0 && i == 0)
      if (a[i] >= 0)
        ss << "+" << a[i];
      else
        ss << a[i];
  }
  ss >> str;
  cout << str;
  return 0;
}
