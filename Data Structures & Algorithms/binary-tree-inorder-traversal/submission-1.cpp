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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            } 
            else{
                TreeNode* leftchild = curr->left;
                while(leftchild->right){
                    leftchild=leftchild->right;
                }
                leftchild->right=curr;
                // curr ke left ko delete kr sakte ab (null mark)
                TreeNode* temp = curr;
                curr=curr->left;
                temp->left=NULL; // removed to avoid repeating again
            }
        }
        return ans;
    }
};