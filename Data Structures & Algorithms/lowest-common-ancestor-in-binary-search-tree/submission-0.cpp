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
    bool find(TreeNode* root, TreeNode* ele){
        if(!root) return false;
        if(root==ele) return true;
        return find(root->left,ele) || find(root->right,ele);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root==p || root==q) return root;
        if((find(root->left,p) && find(root->right,q)) || (find(root->right,p) && find(root->left,q))) return root;
        if(find(root->left,p) && !find(root->right,q)) return lowestCommonAncestor(root->left,p,q);
        if(!find(root->left,p) && find(root->right,q)) return lowestCommonAncestor(root->right,p,q);
    }
};
