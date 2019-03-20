/*
* @Author: Yuuoniy
* @Date:   2018-01-02 21:16:55
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2018-01-02 21:19:37
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
  void deleteNode(ListNode* node) {
    auto next = node->next;
    *node = *next;
    delete next;
  }
};
