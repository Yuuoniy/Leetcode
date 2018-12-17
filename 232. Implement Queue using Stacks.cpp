/*
* @Author: Yuuoniy
* @Date:   2017-11-06 21:02:09
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-06 21:20:25
*/
class MyQueue {
 public:
  /** Initialize your data structure here. */
  stack<int> s;
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) { pushHelper(x); }
  void pushHelper(int x) {
    if (s.size() == 0) {
      s.push(x);
      return;
    }
    int data;
    data = s.top();
    s.pop();
    pushHelper(x);
    s.push(data);
    return;
  }
  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int res = s.top();
    s.pop();
    return res;
  }

  /** Get the front element. */
  int peek() { return s.top(); }

  /** Returns whether the queue is empty. */
  bool empty() { return !s.size(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
//每次push时先把栈全部清空 将元素添加到最尾端，然后利用递归一个个添加原来的元素
