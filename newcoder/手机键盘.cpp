/*
 * @Author: yuuoniy 
 * @Date: 2019-06-17 12:47:52 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-17 12:51:20
 */
// 思路很巧妙

#include  <iostream>
#include <string>

using namespace std;

int main(){
    int key[26] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
    string str;
    while (cin>>str)
    {
      int count = key[str[0]-'a'];
      for (int i = 1; i < str.size(); i++)
      {
        count+= key[str[i]-'a'];
        if(key[str[i]-'a']-key[str[i-1]-'a']==str[i]-str[i-1])
          count+=2;
      }
      cout << count << endl;
    }
    return 0;
}
