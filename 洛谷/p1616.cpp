#include <iostream>
#include <algorithm>


using namespace std;

const int MAX_T = 100005;
const int  MAX_M =10005;

int dp[MAX_T];
int weight[MAX_T];
int value[MAX_T];


int main(){
  int t,m;
  cin >> t >> m;
  for (int i = 0; i < m; i++) {
    cin >> weight[i] >> value[i];
  }
  for (int i = 0; i < m; i++) {
    for (int j = weight[i]; j <= t; j++){
      dp[j] = max(dp[j-weight[i]]+value[i],dp[j]);
    }
  }
  cout << dp[t] << endl;
  return 0;
  
  
}
