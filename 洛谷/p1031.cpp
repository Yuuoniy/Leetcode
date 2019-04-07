#include <iostream>

using namespace std;

int num[105];
int main(){
  int  n;
  cin >> n;
  int sum = 0;
  int count = 0;
  for(int i = 0; i < n; i++)
  {
    cin >> num[i];
    sum += num[i];
  }
  int per = sum/n;
  int tmp;
  if(num[0]!=per){
    ++count;
    if(num[0]>per){
      tmp =num[0]-per;
      num[0]-=tmp;
      num[1]+=tmp;
      }
    else{
      tmp =per-num[0];
      num[0]+=tmp;
      num[1]-=tmp;

      }
  }
  if(n>2&&num[n-1]!=per){
    ++count;
    if(num[n-1]>per){
      tmp = num[n-1]-per;
      num[n-1]-=tmp;
      num[n-2]+=tmp;

      }
    else{
      tmp = per-num[n-1];
      num[n-1]+=tmp;
      num[n-2]-=tmp;
    }
  }
  for(int i = 1; i < n-1; i++)
  {
    if(num[i]!=per){
      // cout << i << num[i]  << " "<< endl;
    ++count;
    if(num[i]>per){
      tmp = num[i]-per;
      num[i]-=tmp;
      num[i+1]+=tmp;

      }
    else{
      tmp = per-num[i];
      num[i]+=tmp;
      num[i+1]-=tmp;
    }
  }
  }
  cout << count ;
  return 0;

}
