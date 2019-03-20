/*
* @Author: Yuuoniy
* @Date:   2018-01-02 19:26:42
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2018-01-02 19:49:13
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
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    help(root, res);
    return res;
  }
  void help(TreeNode* root, vector<int>& res) {
    if (!root) return;
    help(root->left, res);
    res.push_back(root->val);
    help(root->right, res);
  }
};

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> nodes;
    TreeNode* pcurrent = root;
    while (!nodes.empty() || pcurrent) {
      if (pcurrent) {
        nodes.push(pcurrent);
        pcurrent = pcurrent->left;
      } else {
        TreeNode* top = nodes.top();
        res.push_back(top->val);
        nodes.pop();
        pcurrent = top->right;
      }
    }
    return res;
  }
};
