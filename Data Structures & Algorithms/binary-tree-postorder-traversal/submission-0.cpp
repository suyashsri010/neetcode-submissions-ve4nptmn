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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr){
            if(curr->right==NULL){
                ans.push_back(curr->val);
                curr = curr->left;
            }
            else{
                TreeNode* rightchild = curr->right;
                while(rightchild->left!=NULL && rightchild->left!=curr){
                    rightchild = rightchild->left;
                }
                if(!rightchild->left){
                    ans.push_back(curr->val);
                    rightchild->left=curr;
                    curr=curr->right;
                }
                else{
                    rightchild->left=NULL;
                    curr=curr->left;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};