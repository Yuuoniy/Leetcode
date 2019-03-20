/*
* @Author: Yuuoniy
* @Date:   2017-11-07 21:26:25
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-07 21:58:06
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
  int findTilt(TreeNode* root) {
    if (!root)
      return 0;
    else
      return abs(treesum(root->left) - treesum(root->right)) +
             findTilt(root->left) + findTilt(root->right);
  }
  int treesum(TreeNode* root) {
    if (!root)
      return 0;
    else
      return root->val + treesum(root->left) + treesum(root->right);
  }
};
//两部分需要用到递归
