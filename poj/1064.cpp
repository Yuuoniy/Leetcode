// 二分搜索求解最大化问题
// 注意 double 类型 最大是100千米，千米！不是100米
#include <iostream>
#include <math.h>
using namespace std;
const int MAXN = 10005;
const double INF = 100000.0;
int n,k;
double l[MAXN];


//判断是否满足条件
bool C(double x){
  int num = 0;
  for(int i = 0; i < n; i++)
  {
    num+=(int)(l[i]/x);

  }
  // cout << x << endl;
  return num>=k;
  
}
void solve(){
  double lb = 0,ub = INF;
  for(int i = 0; i < 100; i++)
  {
    double mid = (lb+ub)/2;
    if(C(mid)) {lb = mid;
    // cout << mid << endl;
    }
    else 
      ub = mid;
  }
  if(ub<0.01) printf("0.00\n");
  else 
    printf("%.2f\n",floor(ub*100)/100);
}

int main(){
  cin >> n >> k;
  for(int i = 0; i < n; i++)
  {
    cin >> l[i];
  }

  solve();
}
