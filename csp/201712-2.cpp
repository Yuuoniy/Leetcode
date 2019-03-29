
//相当于每轮淘汰x/k 这么多人，但是末位数是k的也会被淘汰，不知道怎么处理..
//不用想太复杂，直接循环模拟就好了！
// 第一次提交90分，漏了什么情况呢.. k=1的情况！这样每一个mode k 都是 0,所以 for 循环的边界条件加上 out<n-1
#include <iostream>

using namespace std;
bool isOut[1005];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    isOut[i] = false;
  }
  int current = 0; //当前报数
  int out = 0;
  while (out < n - 1) {
    for (int i = 1; i <= n&&out<n-1; i++) {
      if (!isOut[i]) {
        ++current;
        if (current % k == 0 || current % 10 == k) {
          isOut[i] = true;
          ++out;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (isOut[i] == false) {
      cout << i << endl;
    }
  }
  return 0;
}
