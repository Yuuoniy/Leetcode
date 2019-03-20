/*
* @Author: Yuuoniy
* @Date:   2017-10-24 09:45:30
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-24 15:39:14
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
// solutions 1:
class Solution {
 public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) return NULL;
    int val = (t1 ? t1->val : 0) + (t2 ? t2->val : 0);
    TreeNode* addTo = new TreeNode(val);
    TreeNode* left1 = t1 ? t1->left : NULL;
    TreeNode* left2 = t2 ? t2->left : NULL;
    TreeNode* right1 = t1 ? t1->right : NULL;
    TreeNode* right2 = t2 ? t2->right : NULL;

    addTo->left = mergeTrees(left1, left2);
    addTo->right = mergeTrees(right1, right2);
    return addTo;
  }
};

// solutions 2:
class Solution {
 public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1) return t2;
    if (!t2) return t1;
    TreeNode* node = new TreeNode(t1->val + t2->val);
    node->left = mergeTrees(t1->left, t2->left);
    node->right = mergeTrees(t1->right, t2->right);
    return node;
  }
};
