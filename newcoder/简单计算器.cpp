/*
 * @Author: yuuoniy
 * @Date: 2019-06-18 14:31:15
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-18 14:52:19
 */
// 很巧妙，一般要中缀表达式转后缀表达式

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int tmp;
  char ch;
  freopen("in.txt","r",stdin);
  while (scanf("%d%c", &tmp, &ch) != EOF&&tmp!=0) {
    if (tmp == 0 && ch == '\n')
      continue;
    double ans[210] = {0}, sum = 0;
    ans[0] = tmp;
    int size = 0;
    while (scanf("%c", &ch) != EOF) {
      scanf("%d", &tmp);
      switch (ch) {
      case '+':
        ans[++size] = tmp;
        break;
      case '-':
        ans[++size] -= tmp;
        break;
      case '*':
        ans[size] *= tmp;
        break;
      case '/':
        ans[size] /= tmp;
        break;
      default:
        break;
      }
      char c = cin.get(); //关键
      if(c=='\n') break;
    }
    for (int i = 0; i <= size; i++) {
      sum += ans[i];
    }

    printf("%.2lf\n", sum);
  }
  return 0;
}
