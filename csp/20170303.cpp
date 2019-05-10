/*
 * @Author: yuuoniy 
 * @Date: 2019-05-10 21:57:43 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-11 00:38:29
 */
//markdown
// 分割区块，处理行内结构
// 注意可以嵌套
// 分情况处理就好了！分模块！
// find 函数的参数，第一个是字符,不要弄反了！！

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string parseLink(string text, string link){
  string res;
  res = "<a href=\"" + link + "\">"+text+"</a>";
  return res;
}

string parseBold(string text){
  string res;
  res = "<em>"+text+"</em>";
  return res;
}

string parseLine(string line){
  int i = 0;
  string res;
  while (i<line.size())
  {
    if(line[i]=='['){
      string text,link;
      int j = i+1;
      j = line.find(']',j);
      text = line.substr(i+1,j-i-1);
      i = j+1;
      j = line.find(')',i);
      link = line.substr(i+1,j-i-1);
      //注意！
      text = parseLine(text);
      link = parseLine(link);
      res += parseLink(text,link);
      i = j+1;
    }else if(line[i]=='_'){
      string text;
      int j = line.find('_',i+1);
      text = line.substr(i+1,j-i-1);
      text = parseLine(text);
      res+= parseBold(text);
      i = j+1;
    }else{
      res += line[i];
      ++i;
    }
  }
  return res;
}




string parsePar(vector<string> &contents){
  string res = "<p>";
  for (int i = 0; i < contents.size(); i++)
  {
    res += parseLine(contents[i]);
    if (i!=contents.size()-1){
      res+="\n";
    }    
  }
  res += "</p>\n";
  return res;
}

string parseHead(vector<string> &contents){
  int level,i = 0;
  string heading = parseLine(contents[0]);
  while (heading[i]=='#') i++;
  level = i;
  while (heading[i]==' ') i++;
  string res = "<h" + to_string(level) + ">" + heading.substr(i,-1) + "</h" + to_string(level)+">\n";
  return res;
}

string parseList(vector<string> &contents){
  string res = "<ul>\n";
  int j;
  for (int i = 0; i < contents.size(); i++)
  {
    res +="<li>";
    j = 1;
    while (contents[i][j]==' ')
    {
      j++;
    }
    res += parseLine(contents[i].substr(j,-1));
    res += "</li>\n";
  }
  res += "</ul>\n";
  return res;
}


int main(){
  string line;
  vector<string> contents;
  int blockType;
  string res;
  // freopen("a.in","r",stdin);
  while (getline(cin,line)||contents.size()>0) //一直读到空行就处理这一区块
  {
    if(line.empty()){
      if(blockType!=0)//分情况处理
      {
        switch(blockType){
          case 1:res+= parsePar(contents); break;
          case 2:res+= parseHead(contents); break;
          case 3:res+= parseList(contents); break;
        }
        contents.resize(0);
        blockType = 0;
      }
    }else if(line[0]=='#') //判断是不是区块的头
    {
      contents.push_back(line);
      blockType = 2;
    }else if(line[0]=='*'){
      contents.push_back(line);
      blockType = 3;
    }else{
      contents.push_back(line);
      blockType = 1;
    }
  
    line = "";
  }
  cout << res ;
  return 0;
  
}
