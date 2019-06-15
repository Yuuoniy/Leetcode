#include <iostream>
#include <algorithm>


using namespace std;
const int MAXN = 2505;
typedef pair<int,int> P;

P cows[MAXN],bot[MAXN];

int c,l;
int main(){
  scanf("%d %d",&c,&l);
  for(int i = 0; i < c; i++)
  {
    scanf("%d %d",&cows[i].first,&cows[i].second);
  }
  for(int i = 0; i < l; i++)
  {
    scanf("%d %d",&bot[i].first,&bot[i].second);
  }
  sort(cows,cows+c);
  sort(bot,bot+l);
  for(size_t i = 0; i < count; i++)
  {
    /* code */
  }
  
  
  
}
