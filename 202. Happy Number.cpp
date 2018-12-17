/*
* @Author: Yuuoniy
* @Date:   2017-10-27 10:27:36
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-27 10:49:10
*/
// Floyd 判圈算法 (Floyd Cycle Detection Algorithm) 快慢指针
/* 如果不是happy number 后面一定会有一个环的 因为循环步数可以无限
 但是和一定是确定的数 因此一定成环*/
class Solution {
 public:
  bool isHappy(int n) {
    int slow = n, fast = n;
    do {
      slow = digitSquareSum(slow);
      fast = digitSquareSum(fast);  //快指针一次移动两步
      fast = digitSquareSum(fast);
    } while (slow != fast);
    return slow == 1;
  }
  int digitSquareSum(int n) {
    int sum = 0, tmp;
    while(n){
      tmp = n%10;
      sum+=tmp*tmp;
      n = n/10;
    }
    return sum;
  }
};
