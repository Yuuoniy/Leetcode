// 对顶堆

#include <queue>
#include <iostream>
#include <cstdio>
using namespace std;
int p,n,t;
priority_queue<int> big;
priority_queue<int,vector<int>,greater<int> > small;


int main(){
  cin >> p;
  for(int i = 0; i < p; i++)
  {
    //清空数组
    while(!big.empty()) big.pop();
    while(!small.empty()){
      small.pop();
    }
    int k = 0;
    scanf("%d %d",&t,&n);
    printf("%d %d\n",t,(n+1)/2);
    for(size_t j = 0; j < n; j++)
    {
      scanf("%d",&t);
      if(j==0)  //直接插入小根堆
        small.push(t);
      else{
        if(t<small.top()){
          big.push(t);
        }else{
          small.push(t);
        }
      }
      //维护性质
      while(small.size()-1>big.size()){
        big.push(small.top());
        small.pop();
      }
      while(big.size()>small.size()){
        small.push(big.top());
        big.pop();
      }
      //为奇数时输出
      if(j%2==0){
        printf("%d",small.top()); ++k;
        if(k!=10) printf(" ");
        else 
        {printf("\n");
         k =0;
        }
      }
    }
      if(i!=p-1)
        printf("\n");
  }
    return 0;
  

}
