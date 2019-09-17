/*
 * @Author: yuuoniy
 * @Date: 2019-08-23 12:22:57
 * @Last Modified by:   yuuoniy
 * @Last Modified time: 2019-08-23 12:22:57
 */
#include <cstdio>
#include <cstring>
#include <ctype.h>

const int MAX_N = 105;
char str[MAX_N][MAX_N];
char cpy[MAX_N][MAX_N];

int main() {
  int flag, n;
  while (scanf("%s", str[0]) != EOF) {
    scanf("%d %d", &flag, &n);
    for (int i = 1; i <= n; i++) {
      scanf("%s", str[i]);
      strcpy(cpy[i], str[i]);
    }
    if (!flag) {
      for (int i = 0; i <= n; i++) {
        strlwr(str[i]);
      }
    }
    for (int i = 1; i <= n; i++) {
      if (strstr(str[i], str[0])) {
        printf("%s\n", str[i]);
      }
    }
  }
  return 0;
}
