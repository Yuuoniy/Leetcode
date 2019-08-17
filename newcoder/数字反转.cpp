/*
 * @Author: yuuoniy
 * @Date: 2019-07-07 15:35:34
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-07-07 15:39:14
 */

#include <iostream>

using namespace std;

int reverse(int num) {
  int res = 0;
  while (num) {

    res = res * 10 + num % 10;
    num /= 10;
  }
  return res;
}
int main() {

  int x,y;
  while (cin>>x>>y)
  {
    if(reverse(x)+reverse(y)==reverse(x+y)){
      cout << x+y << endl;
    }else
      cout << "NO" << endl;
  }
  return 0;


}
