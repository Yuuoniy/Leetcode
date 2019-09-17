/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if(leftHeight==rightHeight)
            return (1<<leftHeight)+countNodes(root->right);
        else
            return (1<<rightHeight) +countNodes(root->left);

    }
     int getHeight(TreeNode* root){
        int height = 0;
        while (root!=nullptr)
        {
            root = root->left;
            height++;
        }
        return height;
    }
};

