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
    TreeNode* call(TreeNode* root,int mini,int maxi){
        if(root->val >= mini && root->val <=maxi) return root;
        if(root->val > maxi) return call(root->left,mini,maxi);
        return call(root->right,mini,maxi);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int mini = min(p->val,q->val);
        int maxi = max(p->val,q->val);
        return call(root,mini,maxi);
    }
};