/*
* @Author: Yuuoniy
* @Date:   2018-01-02 20:55:08
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2018-01-02 21:11:20
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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
  }
  TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
    int _size = end - start;
    if (_size < 0) return NULL;
    if (_size == 0) return new TreeNode(nums[start]);
    int mid = (end + start) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);
    return root;
  }
};
