/*
* @Author: Yuuoniy
* @Date:   2017-11-09 19:21:01
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-09 19:46:30
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
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return head;
    ListNode* tmp = head;
    while (tmp && tmp->next) {
      while (tmp->next && (tmp->val == tmp->next->val)) {
        ListNode* del = tmp->next;
        tmp->next = tmp->next->next;
        delete del;
      }
      tmp = tmp->next;
    }
    return head;
  }
};
