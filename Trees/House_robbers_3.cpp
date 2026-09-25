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
    int call(TreeNode* root,unordered_map<TreeNode*,int>& dp){
        if(root == nullptr) return 0;
        if(dp.count(root) == true) return dp[root];
        int skip = call(root->left,dp) + call(root->right,dp);
        int not_skip = root->val;
        if(root->left != nullptr) not_skip+= call(root->left->left,dp) + call(root->left->right,dp);
        if(root->right != nullptr) not_skip+= call(root->right->left,dp) + call(root->right->right,dp);
        return dp[root] = max(skip,not_skip);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> dp;
        return call(root,dp);
    }
};