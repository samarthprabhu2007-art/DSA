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
        TreeNode* newnode = new TreeNode(val);
        if(root==nullptr) return newnode;
        TreeNode* temp=root;
        while(true){
            if(root->val > val){
                if(root->left == nullptr) {
                    root->left=newnode;
                    break;
                }
                root=root->left;
            }
            else{
                if(root->right == nullptr) {
                    root->right=newnode;
                    break;
                }
                root=root->right;
            }
        }
        return temp;
    }
};