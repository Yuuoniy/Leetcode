#include <iostream>
#include <map>
#include <string>



using namespace std;


int main(){
  int n;
  while (cin>>n)
  {
    map<char,long long>m;
    set<char> f;
    for (int i = 0; i < n; i++)
    {
      string s;
      cin >> s;
      long long weight = 1;
      for (string::reverse_iterator i = s.rbegin(); i < s.rend; i++)
      {
        m[*i]  += weight;
        weight *= 10;
      }
      f.insert(s[0]);
    }
    vector<pair<char,long long>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);
    
  }
  

}
