/*
* @Author: Yuuoniy
* @Date:   2017-12-31 20:58:18
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-12-31 22:06:09
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
  ListNode* insertionSortList(ListNode* head) {
    if (!head) return head;
    ListNode* helper = new ListNode(0);
    ListNode* p = head;
    ListNode* pre = helper;
    ListNode* next = NULL;
    while (p) {
      next = p->next;
      while (pre->next && pre->next->val < p->val) {
        //从前往后找该插入的位置
        pre = pre->next;
      }
      p->next = pre->next;
      pre->next = p;
      pre = helper;
      p = next;
    }
    return helper->next;
  }
};
