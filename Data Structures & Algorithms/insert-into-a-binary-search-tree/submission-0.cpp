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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* ele = new TreeNode(val);
        if(!root) return ele;
        TreeNode* temp = root;
        while(temp){
            if(temp->val<val){
                if(temp->right) temp = temp->right;
                else {
                    temp->right = ele;
                    break;
                }
            }
            else if(temp->val>val){
                if(temp->left) temp = temp->left;
                else {
                    temp->left = ele;
                    break;
                }
            }
        }
        return root;
    }
};