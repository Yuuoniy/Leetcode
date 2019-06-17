#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
 int num = 0,tmp = 0;
//  vector<int> nums;
 int y = 2,count = 2;
 while (cin>>num)
 {
 for(int i = 0; i < num; i++)
 {
   cin >> tmp;
   int ans = 0;
   for(y=1;y*y<tmp;y++){
     if(tmp%y==0) ans+= 2;
   }
   if(y*y==tmp) ans+=1;
   cout << ans << endl;
 }
  
 }
 
return 0;
 
}
