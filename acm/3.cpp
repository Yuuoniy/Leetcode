#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
  int t;
  scanf("%d",&t);
  int fi,fj,ti,tj;
  long long sum = 0;
  long long rows,cols,fisrtbegin,firstend,endend,endbegin,firstsum,endsum;
  while(t--){
    scanf("%d%d%d%d",&fi,&fj,&ti,&tj);
     rows = ti-fi+1;
     cols = tj-fj+1;
     fisrtbegin = fi+fj;
     firstend = fisrtbegin+cols-1;
     endend = ti+tj;
     endbegin = endend-cols+1; 
     firstsum =cols*(fisrtbegin+firstend)/2;
     endsum = cols*(endbegin+endend)/2;
    if(rows==1) sum = firstsum;
    else{
      sum  = rows*(firstsum+endsum)/2;
    }
    if(t>0)
    printf("%lld\n",sum); 
    else 
    printf("%lld",sum);

  }
  return 0;

}
