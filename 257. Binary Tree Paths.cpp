
/*
* @Author: Yuuoniy
* @Date:   2017-11-02 20:09:36
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-02 20:45:17
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
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if (root == NULL) return res;
    string str1 = to_string(root->val);
    if (root->left != NULL) help(res, str1, root->left);
    if (root->right != NULL) help(res, str1, root->right);
    if (!root->left && !root->right) res.push_back(str1);
    return res;
  }
  void help(vector<string>& res, string prev, TreeNode* root) {
    prev += "->";
    prev += to_string(root->val);
    if (root->left != NULL) help(res, prev, root->left);
    if (root->right != NULL) help(res, prev, root->right);
    if (!root->left && !root->right) res.push_back(prev);
  }
};

// 改进版：
class Solution {
 public:
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if (!root) return res;
    findPaths(res, root, to_string(root->val));
    return res;
  }
  void findPaths(vector<string>& res, TreeNode* root, string t) {
    if (!root->left && !root->right) {
      res.push_back(t);
      return;
    }
    if (root->left)
      findPaths(res, root->left, t + "->" + to_string(root->left->val));
    if (root->right)
      findPaths(res, root->right, t + "->" + to_string(root->right->val));
  }
};
