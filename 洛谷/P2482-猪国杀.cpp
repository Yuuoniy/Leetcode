#include <stdio.h>

struct pig
{
  int front,next;
  int id;
  int show_id;
  bool alive;
  int hp;
  char card[20005];
  bool is_used[2005];
  bool z;//是否装备诸葛连弩
}pigs[15];

int alive_num = 0;//存活猪的数量
int res = -1;//游戏结果
int n,m;
void init_info(int )

int main(){
  scanf("%d%d",&n,&m);
  for(int i = i; i <=n; i++)
  {
    init_info(i);
  }
  get_current_card();//获取当前牌堆的情况
  while(res==-1){
    for(int i = 1; i <= n; i=pigs.next)//轮流出牌
    {
      get_card();
      int use_kill_num = 0;
      //从左到右扫描可以使用的牌
      for(int j = 1; j <=pigs[i].used_card; j++)   {
        if(!pigs[i].is_used[j]){
          bool is_used = false;
          char curren_card = pigs[i].card[j];
          if(curren_card=='P') is_used = use_peach(i);//桃
          else if(curren_card=='K'){
            if(use_kill_num==0||pigs[i].zb) is_used = use_kill(i);//第一次或者有诸葛连弩可以连续使用杀
            if(is_used) //使用成功
              ++use_kill_num;//记录使用K的数量
          }else if(curren_card=='F') is_used = use_fight(i);
        }
      }
      
    }
    
  }
}
