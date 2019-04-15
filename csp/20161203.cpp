// 因为使用了 map,map 中不存在的key值是0，可能会和等级冲突，因此0-9的等级，我用1-10表示。但是只有 50 分... 哭辽 原来是 if 没有把所有条件包含，改一下下就好了
// 这要是真的考试怎么办啊TAT
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct priviliage{
  string name;
  int highest_level;  
  bool isLevel;
}priviliages[105];

struct role{
  string name;
  int num;
  map<string,int> privis; //权限及其对应的等级，如果-1说明没有对应的权限。如果为0说明没有等级
}roles[105];

struct user{
  string name;
  map<string, int> privis;
  vector<string> roles;
}users[105];
int p_num,r_num,u_num,q_num;
map<string,int> role_idx;
map<string,int> user_idx;
map<string,int> privi_idx;

priviliage process_privi(string str){
    int pos = str.find(':');
    priviliage res;
    if(pos==string::npos){ //不分等级, level 我设为0
      res.name = str;
      res.highest_level = -2; //避免弄混，就标记为 -2 吧
      res.isLevel = false;
    }else{
      res.name = str.substr(0,pos);
      res.highest_level = stoi(str.substr(pos+1))+1;
      res.isLevel = true;
    }
    return res;
}

int main(){
  cin >> p_num;
  string tmp;
  //记录各个权限 其实我不明白这有什么用
  for(int i = 1; i <= p_num; i++)
  {
    cin >> tmp;
    priviliages[i] = process_privi(tmp);
    privi_idx[priviliages[i].name] =i;
  }
  
  cin >> r_num;
  string name;
  int num;
  priviliage pri;
  //存储角色的level
  for(int i = 1; i <= r_num; i++)
  {
    cin >> name >> num;
    roles[i].name = name;
    roles[i].num = num;
    role_idx[name] = i;
    for(int j = 0; j < num; j++)
    {
      cin >> tmp;
      pri = process_privi(tmp);
      if(roles[i].privis[pri.name]<pri.highest_level||roles[i].privis[pri.name]==0)
        roles[i].privis[pri.name] = pri.highest_level;
          // cout << " add privis for " << name << " " << pri.name << " " << pri.highest_level << endl;

    }
  }

  cin >> u_num;
  for(int i = 1; i <= u_num; i++)
  {
    cin >> name >> num;
    users[i].name = name;
    user_idx[name] = i;
    for(int j = 0; j < num; j++)
    {
      cin >> tmp; //role
      map<string,int> privis = roles[role_idx[tmp]].privis;
      for(map<string,int>::iterator it= privis.begin();it!=privis.end() ; ++it) //遍历该 role 的权限，添加到用户之中
      {
          // cout << " privis "  << " " << it->first << " " << it->second << endl;
          // cout << " privis " << name << " " << it->first << " " << "user is " << users[i].privis[it->first] << endl;   
        if(users[i].privis[it->first]<it->second||users[i].privis[it->first]==0){
          users[i].privis[it->first] = it->second;
          // cout << " add privis for " << name << " " << it->first << " " << it->second << endl;
        } //添加权限
      }
    }
  }
  cin >> q_num;
  for(int i = 0; i < q_num; i++)
  {
    cin >> name >>  tmp;
    priviliage priv = process_privi(tmp);
    int idx = user_idx[name];
    int idx2 = privi_idx[priv.name];
    if(idx==0||idx2==0){ //用户名或权限名没有出现过
      cout << "false" << endl;
      continue;
    }
    if(priviliages[privi_idx[priv.name]].isLevel==1&&priv.highest_level==-2){ //分等级权限的不带等级查询
      if(users[idx].privis[priv.name]==0){
      cout << "false" << endl;        
      }else{
        cout << users[idx].privis[priv.name]-1 << endl;
      }
    }
    else if(users[idx].privis[priv.name]!=0&&users[idx].privis[priv.name]>=priv.highest_level) //带等级查询 ps:不分等级都为-2，因此可以一起处理
    {
      cout << "true" << endl;
    }else { //没有这个权限，或者等级比较低
      cout << "false" << endl;
    }
  }
  return 0;
}
