#include <iostream>
using namespace std;

char kind[4] = {'?','B','R','W'};
int getno(int q, int w) {
  int i;
  for (i = 1; i <= 3; i++)
    if (i != q && i != w)
      return i;
}
int a[1002], b[1002],num=0;
int k1[500005], k2[500005];char k[500005];
int main() {
  int n, m, i, j, l, c1, c2;
  char s;
  int eq = 0;
  // string s;
  int c;
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    cin >> c1 >> s >> c2;
    if (s == '>') {
      c = c2;
      c2 = c1;
      c1 = c;
      s = '<';
    }
    k1[i]=c1;
    k2[i]=c2;
    k[i]=s;
    if (s == '<') {
      if (b[c1] != 0) {
        if (b[c2] != 0)
          continue;
        if (b[c1] == 2)
          b[c2] = 3;
        if (b[c1] == 1) {
          if (a[c2] == 3)
            b[c2] = 2;
          else if (a[c2] == 2)
            b[c2] = 3;
          else
            a[c2] = 1;
        }
      } else {
        if (b[c2] != 0) {
          if (b[c2] == 2)
            b[c1] = 1;
          if (b[c2] == 3) {
            if (a[c1] == 1)
              b[c1] = 2;
            else if (a[c2] == 2)
              b[c1] = 1;
            else
              a[c1] = 3;
          }

        } else {
          cout<<c1<<c2<<a[1]<<endl;
          if (a[c1] == 1)
            b[c1] = 2;
          else if (a[c1] == 2)
            b[c1] = 1;
          else
            a[c1] = 3;

          if (a[c2] == 2)
            b[c2] = 3;
          else if (a[c2] == 3)
            b[c2] = 2;
          else
            a[c2] = 1;
        }
      }
    }
    if (s == '=') {
      if (b[c1] == 0 && b[c2] == 0) {
        if (a[c1] != a[c2]) {
          b[c1] = getno(c1, c2);
          b[c2] = b[c1];
        }
      } else {
        if (b[c1] == 0)
          b[c1] = b[c2];
        else
          b[c2] = b[c1];
      }
    }
  }
  num=0;
  for(i=1;i<=n;i++)
    if(b[i]!=0)
      num++;

 bool flag=true;
  while(flag==true)
{ cout<<"num"<<num<<endl;
   flag=false;
  for (i = 1; i <= m; i++) {
    
    
    c1=k1[i];
    c2=k2[i];
    s=k[i];
    if (s == '<') {
      if (b[c1] != 0) {
        if (b[c2] != 0)
          continue;
        if (b[c1] == 2)
          b[c2] = 3;
        if (b[c1] == 1) {
          if (a[c2] == 3)
            b[c2] = 2;
          else if (a[c2] == 2)
            b[c2] = 3;
          else
            a[c2] = 1;
        }
      } else {
        if (b[c2] != 0) {
            cout<<c1<<c2<<b[1]<<b[2]<<a[1]<<a[2]<<endl;
          if (b[c2] == 2)
            b[c1] = 1;
          if (b[c2] == 3) {
            if (a[c1] == 1)
              b[c1] = 2;
            else if (a[c2] == 2)
              b[c1] = 1;
            else
              a[c1] = 3;
          }

        } else {
          cout<<c1<<c2<<a[1]<<endl;
          if (a[c1] == 1)
            b[c1] = 2;
          else if (a[c1] == 2)
            b[c1] = 1;
          else
            a[c1] = 3;

          if (a[c2] == 2)
            b[c2] = 3;
          else if (a[c2] == 3)
            b[c2] = 2;
          else
            a[c2] = 1;
        }
      }
    }
    if (s == '=') {
      if (b[c1] == 0 && b[c2] == 0) {
        if (a[c1] != a[c2]) {
          b[c1] = getno(c1, c2);
          b[c2] = b[c1];
        }
      } else {
        if (b[c1] == 0)
          b[c1] = b[c2];
        else
          b[c2] = b[c1];
      }
    }
  }
  int index=0;
  for (i=1;i<=n;i++)
    if(b[i]!=0)
      index+=1;
  if(index==num)
    break;
  else
  {
     num=index;
     flag=true;
     continue;
  }
  
}


  for (i = 1; i <= n; i++) {
    
      cout << kind[b[i]];
  }
}
