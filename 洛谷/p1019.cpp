#include <bits/stdc++.h>

using namespace std;



int maxLen = 0;
int newLen = 0;
string strs[25];
int n;
int used[25]={0};
int link(string& str1,string& str2){
  if(str1.length()==1){
    if(str1[0]==str2[0]){
      return str2.length();
    }else {
      return 0;
    }
  }
  for(int i = 1; i < str1.length(); i++)
  {
    string substr1 = str1.substr(str1.length()-i);
    string substr2 = str2.substr(0,i);
    if(substr1==substr2)
      return str2.length()-i;
  }
  return 0;
}

void dfs(string &s){
  for(int i = 0; i < n; i++)
  {
    int 
  }
  
}
int main(){
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> strs[i];
  }
  string first;
  cin >> first;
  dfs(first);
  cout << maxLen << endl;
  return 0;
  
}
