/*
 * @Author: yuuoniy 
 * @Date: 2019-04-11 20:15:59 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-04-11 20:22:18
 */
// 求先序排列
// 思路：
// 1. 先找到根输出 2. 将中序，后序各分为左右两棵子树 3. 递归
#include <iostream>
#include <string>
using namespace std;


string inorder;
string postorder;

void print_pre(string in,string post){
  if(in.size()!=0){
    char root = post[post.size()-1];
    cout <<  root ;
    int k = in.find(root);
    print_pre(in.substr(0,k),post.substr(0,k));
    print_pre(in.substr(k+1),post.substr(k,in.size()-k-1));
  }
}

int main(){
  cin >> inorder >> postorder;
  print_pre(inorder,postorder);
  return 0;
}
