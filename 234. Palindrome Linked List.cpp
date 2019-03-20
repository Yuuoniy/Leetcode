/*
* @Author: Yuuoniy
* @Date:   2017-11-05 20:13:45
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-05 20:38:17
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* temp;
  bool isPalindrome(ListNode* head) {
    temp = head;
    return check(head);
  }
  bool check(ListNode* p) {
    if (!p) return true;
    bool isPal = check(p->next) && (temp->val == p->val);
    temp = temp->next;
    return isPal;
  }
};
// p首先遍历到链表尾端 temp从头开始
//利用递归 p 不断往前移 temp 往后移
//每一位都比较 不用考虑奇偶性
