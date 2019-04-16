#include <stdio.h>

using namespace std;

int nums[100005];
int main(){
  int n,m;
  int sum = 0;
  scanf("%d %d",&n,&m);
  int count = 1;
  if(n==0) count = 0;
  for(int i = 0; i < n; i++)
  {
    scanf("%d",&nums[i]);
    if((sum+nums[i])<=m)
      sum+=nums[i];
    else{
      ++count;
      sum = nums[i];
    }
  }
  printf("%d",count);

  
}
