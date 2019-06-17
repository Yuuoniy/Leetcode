/*
 * @Author: yuuoniy 
 * @Date: 2019-06-17 12:51:51 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-06-17 13:01:37
 */


#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
  int n,grade;
  bool operator<(const node other) const{
    return grade<other.grade||(grade==other.grade&&n<other.n);
  }
}students[105];


int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> students[i].n >> students[i].grade;
  }
  sort(students,students+n);
  for (int i = 0; i < n; i++)
  {
    cout << students[i].n << " " << students[i].grade << endl;
  }
  return 0;
  
  
}
