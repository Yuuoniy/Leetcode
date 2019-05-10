/*
 * @Author: yuuoniy 
 * @Date: 2019-04-15 14:11:57 
 * @Last Modified by:   yuuoniy 
 * @Last Modified time: 2019-04-15 14:11:57 
 */
// json 查询

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int n,m;
map<string,string> mp;


void format(string &s){
  for(int i = 0; i < s.size(); i++)
  {
    if(s[i]=='\\'){
        s.erase(s.begin()+i);
    }
  }
  
}

void process(string& json,string& t){
  string k,v;
  for(int i = 0; i < json.size(); i++)
  {
    if(json[i]=='"'){
      int j = json.find(":",i+1);
      k = json.substr(i+1,j-i-2);
      if(t!="")
        k = t+"."+k;//多层处理
      if(json[j+1]=='"')//value 字符串而不是对象
      {
        if(json.find(",",j+1)!=string::npos)
          i = json.find(",",j+1);
        else
          i = json.size()-1;//最后一个键值对
        v = json.substr(j+2,i-j-3);
        format(k);
        format(v);
      }else{ //value 是对象，要嵌套处理
        int c = 1;
        i = j+2;
        while(c!=0){
          if(json[i]=='{')
            ++c;
          else if(json[i]=='}'){
            --c;
          }
          ++i;
        }
        v = json.substr(j+1,i-j-1);
        process(v,k);
      }
    }
    mp[k] = v;
    // cout << "key: " << k << " value " << v << endl;
  }
  
}
int main(){
  // freopen("a.in","r",stdin);
  cin >> n  >> m;
  string s,json;
  getline(cin,s);
  for(int i = 0; i < n; i++)
  {
    getline(cin,s);
    for(string::iterator it = s.begin(); it!=s.end();)
    {
      if(*it==' '){
        it = s.erase(it);
      }else{
        ++it;
      }
    }
    json+=s;
  }
  
  // cout << json << endl;
  string t;
  process(json,t);
  for(int i = 0; i < m; i++)
  {
    cin >> s;
    if(mp.find(s)!=mp.end()){
      if(mp[s][0]=='{'){
        cout << "OBJECT" << endl;
      }else {
        cout << "STRING " << mp[s] <<  endl;
      }
    }else{
      cout << "NOTEXIST" << endl;
    }
  }
  
}
