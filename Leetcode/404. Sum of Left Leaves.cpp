/*
* @Author: Yuuoniy
* @Date:   2017-10-27 17:01:05
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-27 17:20:31
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
// Solution 1:
class Solution {
 public:
  int sumOfLeftLeaves(TreeNode* root) {
    int sum = 0;
    help(sum, root);
    return sum;
  }
  void help(int& sum, TreeNode* root) {
    if (root == NULL) return;
    if (root->left != NULL && root->left->left == NULL &&
        root->left->right == NULL)
      sum += root->left->val;
    help(sum, root->left);
    help(sum, root->right);
  }
};
//注意是左叶子结点

// Solution 2:
class Solution {
 public:
  int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;
    if (root->left && !(root->left->left) && !(root->left->right))
      return root->left->val +
             sumOfLeftLeaves(
                 root->right);  //因为root->left已经为叶子结点 不用再找下去
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
  }
};
