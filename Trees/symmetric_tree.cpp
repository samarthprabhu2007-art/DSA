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
    bool call(TreeNode* x,TreeNode* y){
        if(x==nullptr || y==nullptr) return x==y;
        bool curr = (x->val==y->val);
        bool left = call(x->right,y->left);
        bool right = call(x->left,y->right);
        return ((curr && right) && left);
    }
    bool isSymmetric(TreeNode* root) {
        return call(root->left,root->right);
    }
};