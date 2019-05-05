#include <iostream>
using namespace std;

int n,m;
int ma[1005][1005];
int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++)
  {
    for(size_t j = 0; j < m; j++)
    {
      cin >> ma[i][j];
    }
  }


  for(int i = m-1; i>=0; i--)
  {
    for(int j = 0; j < n; j++)
    {
      cout << ma[j][i] << " ";
    }
    cout << endl;
  }
  return 0;
    
}
