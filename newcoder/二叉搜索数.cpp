/*
 * @Author: yuuoniy
 * @Date: 2019-06-18 13:49:33
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-18 14:20:10
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

typedef struct TNode {
  char data;
  struct TNode *left, *right;
} * BiTree, TNode;

TNode T[200];
int loc;
int cnt;

BiTree create() {
  T[loc].left = T[loc].right = NULL;
  return &T[loc++];
}

BiTree Insert(BiTree T, char x) {
  if (!T) {
    T = create();
    T->data = x;
    return T;
  }
  if (x < T->data) {
    T->left = Insert(T->left, x);
  } else if (x > T->data) {
    T->right = Insert(T->right, x);
  }
  return T;
}

void PreOrder(BiTree T, string& res) {
  if (!T)
    return;
  res += T->data;
  PreOrder(T->left, res);
  PreOrder(T->right, res);
  return;
}

int main() {
  BiTree T1, T2;
  int n;
  while (scanf("%d", &n) != EOF && n != 0) {
    string str1, str2;
    cin >> str1;
    T1 = NULL;
    loc = 0;
    for (int i = 0; i < str1.length(); i++) {
      T1 = Insert(T1, str1[i]);
    }
    for (int i = 0; i < n; i++) {
      T2 = NULL;
      cin >> str2;
      for (int j = 0; j < str2.length(); j++) {
        T2 = Insert(T2, str2[j]);
      }
      string a, b;
      PreOrder(T1, a);
      PreOrder(T2, b);
      string ans = (a == b) ? "YES" : "NO";
      cout << ans << endl;
    }
  }
}
