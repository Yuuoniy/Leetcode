/*
 * @Author: yuuoniy 
 * @Date: 2019-05-10 09:14:42 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-05-10 16:20:02
 */
// 最优配餐
// 每个顾客广度优先搜索，找到最近的店铺就好了吧。。 不要单独，要一起搜索！
// 不过要注意的是，这个题目不是单单从一个结点出发进行搜索，而是从所有的分店同时开始搜索，这样就确保了代码运行过程中不会超时
// 注意！
// 定义好结构体，记录深度，这样才能算花费
#include <iostream>
#include <utility>
#include <vector>
#include <set>

using namespace std;
typedef pair<int,int> P;
const int MAX_N = 1005;
const int MAX_M =  MAX_N*MAX_N;

int n,m,k,d;
int ma[MAX_N][MAX_N];
vector<P> store;
set<P> customer;
int  ans;


int bfs(){

}
int main(){
  cin >> n >> m >> k >> d;
  //m 个 分店
  for (int i = 0; i < m; i++)
  {
    int x,y;
    cin >> x >> y;
    ma[y][x] = -1;
    store.push_back(make_pair(x,y));
  }
  // 客户的位置 订餐量
  for (int i = 0; i < k; i++)
  {
    int x,y,c;
    cin >> x >> y >> c;
    ma[y][x] +=c;
    customer.insert(make_pair(x,y));
  }
  //不能经过的地方
  for (int i = 0; i < d; i++)
  {
    int x,y;
    cin >> x >> y; 
    ma[y][x] =-2;
  }
  solve();
  return 0;
}
