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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        queue<TreeNode*> q1,q2;
        q1.push(p),q2.push(q);
        while(!q1.empty() || !q2.empty()){
            TreeNode* ele1 = q1.front(), *ele2 = q2.front();
            q1.pop(),q2.pop();
            if(ele1->val != ele2->val) return false;
            if(ele1->left && ele2->left) q1.push(ele1->left),q2.push(ele2->left);
            else if(ele1->left || ele2->left)return false;
            if(ele1->right && ele2->right) q1.push(ele1->right),q2.push(ele2->right);
            else if(ele1->right || ele2->right)return false;
        }
        if(q1.empty() && q2.empty()) return true;
        return false;
    }
};
