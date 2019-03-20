/*
* @Author: Yuuoniy
* @Date:   2017-10-24 15:48:49
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-24 16:00:52
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val < root->val && q->val < root->val)
      return lowestCommonAncestor(root->left, p, q);
    if (p->val > root->val && q->val > root->val)
      return lowestCommonAncestor(root->right, p, q);
    return root;
  }
};
