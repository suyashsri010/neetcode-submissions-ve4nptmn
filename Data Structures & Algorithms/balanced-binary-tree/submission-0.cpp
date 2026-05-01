/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool flag = true;
    int height(TreeNode* root){
        if(!root) return 0;
        int leftheight = 1+height(root->left);
        int rightheight = 1+height(root->right);
        if(abs(leftheight-rightheight)>1) flag = false;
        return max(leftheight,rightheight);
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        height(root);
        return flag;
    }
};
