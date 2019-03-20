/*
* @Author: Yuuoniy
* @Date:   2018-01-02 21:20:27
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2018-01-02 21:57:02
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
  ListNode* removeElements(ListNode* head, int val) {
    if (!head) return NULL;
    head->next = removeElements(head->next, val);
    return head->val == val ? head->next : head;
  }
};
