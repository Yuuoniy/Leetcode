/*
 * @Author: yuuoniy 
 * @Date: 2019-05-09 09:31:32 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-09 10:24:58
 */
// 炉石传说
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;


struct role{
  int attack;
  int health;
  role(int _attack=0,int _health=30){
    attack = _attack;
    health = _health;
  }
};

//用 vector 存储，方便 Insert 和 erase，下标就是位置，很方便!
vector<role> P1;
vector<role> P2;



//玩家的操作
void add_follwer(int player){
  int pos,att,health; 
  cin >> pos >> att >> health;
  role r(att,health);
  if(player==0) P1.insert(P1.begin()+pos,r);
  else P2.insert(P2.begin()+pos,r);
}

void follower_attack(int player){
  int att,def;
  cin >> att >> def;
  if(player==0){
    P1[att].health-=P2[def].attack;
    P2[def].health-=P1[att].attack;
    if(P1[att].health<=0) P1.erase(P1.begin()+att);
    //不移除英雄！
    if(P2[def].health<=0&&def>0) P2.erase(P2.begin()+def);
  }else{
     P2[att].health-=P1[def].attack;
    P1[def].health-=P2[att].attack;
    if(P2[att].health<=0) P2.erase(P2.begin()+att);
    //不移除英雄！
    if(P1[def].health<=0&&def>0) P1.erase(P1.begin()+def);
  }
}

void print_res(){
  if(P1[0].health<=0&&P2[0].health>0) cout << "-1" << endl;
  else if(P2[0].health<=0&&P1[0].health>0) cout << "1" << endl;
  else cout << "0" << endl;
  //先手的信息
  cout << P1[0].health << endl;
  cout << P1.size()-1 << " ";
  for (int i = 1; i < P1.size(); i++)
  {
    cout << P1[i].health<< " ";
  }
  cout << endl;

  cout << P2[0].health << endl;
  cout << P2.size()-1 << " ";
  for (int i = 1; i < P2.size(); i++)
  {
    cout << P2[i].health<< " ";
  }
}

int main(){
  cin >> n;
  string op;
  bool player = 0;//标记当前操作的玩家
  //初始化两个英雄
  role r(0,30);
  P1.push_back(r);
  P2.push_back(r);
  //还要保证游戏没有结束
  while (n--&&P1[0].health>0&&P2[0].health>0)
  {
    cin >> op;
    if(op=="summon"){
      add_follwer(player);
    }else if(op=="attack"){
      follower_attack(player);
    }else{
      player = !player;
    }
  }
  print_res();
  return 0;
}
