/*
* @Author: Yuuoniy
* @Date:   2017-11-23 10:32:55
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-23 11:40:01
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
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> ss;
    stack<TreeNode*> nodes;
    if (!root) return ss;
    ss.push_back(root->val);
    nodes.push(root);
    help(nodes, ss);
    return ss;
  }
  void help(stack<TreeNode*>& nodes, vector<double>& ss) {
    if (nodes.empty()) return;
    long i = 0, count = 0;
    stack<TreeNode*> child;
    while (nodes.size()) {
      TreeNode* root = nodes.top();
      nodes.pop();
      i += (long)(root->left ? root->left->val : 0) +
           (root->right ? root->right->val : 0);
      // count += (root->left ? 1 : 0) + (root->right ? 1 : 0);
      if (root->left) child.push(root->left);
      if (root->right) child.push(root->right);
    }
    // cout << i << '|' << child.size() << endl;
    if (child.size() != 0) ss.push_back((double)i / child.size());
    help(child, ss);
  }
};
