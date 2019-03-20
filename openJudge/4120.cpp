#include <iostream>


using namespace std;
int kinds[10010];
int calc(int totalMoney,int value){
  if(totalMoney<0)
    return 0;
  else
  //总方法数减去含有这一枚面值为nowvalue的硬币的方法数目;
  //即减去总价值为allvalue - nowvalue,不含这枚硬币的方法数目;
    return kinds[totalMoney]-calc(totalMoney-value,value);
}
int main(){
  int values[210],coinCount = 0;
  int totalMoney;
  int finalCoin[210]; //记录最后的硬币种类
  int cntCoin = 0;
  cin >> coinCount >> totalMoney;
  
  kinds[0] = 1;//初始条件
  for(int i = 0; i < coinCount; i++)
  {
    cin >> values[i];
    for(int j = totalMoney; j>=values[i]; --j)
    {
      kinds[j]+=kinds[j-values[i]];
    }
  }
  //若总价值为x且不含这枚硬币的方法数目为0，则必须含有这枚硬币*/
  for(int i = 0; i < coinCount; i++)
  {
    if(calc(totalMoney,values[i])==0) //代表必须包含这种硬币
      finalCoin[cntCoin++] = values[i];
  }
  cout << cntCoin  << endl;
  if(!cntCoin)
    cout << endl;
  else{
    for(int i = 0; i < cntCoin; i++)
    {
      cout << finalCoin[i] << " ";
    }
  }
  return 0;
}
