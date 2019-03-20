/*
* @Author: Yuuoniy
* @Date:   2017-10-23 14:33:21
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-24 09:34:19
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode preHead(0), *p = &preHead;
    int carry = 0;
    while (l1 || l2 || carry) {
      int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
      carry = sum / 10;
      p->next = new ListNode(sum % 10);
      p = p->next;
      l1 = l1 ? l1->next : l1;  //到尾了就不用往后移了
      l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
  }
};
//用prehead 辅助（真厉害...
//别漏掉carry尤其是while条件中
//灵活利用三目运算符
//区分-> 和 .
