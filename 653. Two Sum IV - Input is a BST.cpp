/*
* @Author: Yuuoniy
* @Date:   2017-10-27 11:11:26
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-27 12:46:55
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
  bool findTarget(TreeNode* root, int k) {
    unordered_set<int> set;
    return dfs(root, set, k);
  }
  bool dfs(TreeNode* root, unordered_set<int>& set, int k) {
    if (root == NULL) return false;
    if (set.count(k - root->val)) return true;
    set.insert(root->val);
    return dfs(root->left, set, k) || dfs(root->right, set, k);
  }
};
//建立哈希查找表
// set要按引用传！

// Solution 2:

class Solution {
 public:
  bool findTarget(TreeNode* root, int k) {
    vector<int> nums;
    inorder(root, nums);
    for (int i = 0, j = nums.size() - 1; i < j;) {
      if (nums[i] + nums[j] == k) return true;
      (nums[i] + nums[j] < k) ? ++i : --j;
    }
    return false;
  }
  void inorder(TreeNode* root, vector<int>& nums) {
    if (root == NULL) return;
    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
  }
};
//把树变成已排序的数组
//熟悉中序遍历
//三目运算符的运用 不一定是一个赋值运算
