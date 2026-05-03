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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> vec;
            for(int i=0;i<sz;i++){
                TreeNode* ele = q.front();
                vec.push_back(ele->val);
                q.pop();
                if(ele->left) q.push(ele->left);
                if(ele->right) q.push(ele->right);
            }
            ans.push_back(vec);
        }
        return ans;
    }
};
