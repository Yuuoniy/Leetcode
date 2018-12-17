/*
* @Author: Yuuoniy
* @Date:   2018-01-02 19:50:18
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2018-01-02 20:17:23
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
  bool isValidBST(TreeNode* root) { return isValidBST(root, NULL, NULL); }
  bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if (!root) return true;
    if (minNode && root->val <= minNode->val ||
        maxNode && root->val >= maxNode->val) {
      return false;
    }
    return isValidBST(root->left, minNode, root) &&
           isValidBST(root->right, root, maxNode);
  }
};
