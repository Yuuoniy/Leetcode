/*
 * @Author: yuuoniy 
 * @Date: 2019-06-16 15:58:18 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-16 16:00:18
 */


#include <iostream>

using namespace std;

int main(){
  for (int i = 0; i <=9; i++)
  {
    for (int j = 0; j <=9; j++)
    {
      for (int k = 0; k <=9; k++)
      {
        if(i*100+j*10+k+j*100+k*10+k==532)
          cout << i << " " << j << " " << k << endl;
      }
      
    }
    
  }
  return 0;
  
}
