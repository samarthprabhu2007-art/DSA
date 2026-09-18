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

 // Key point , for bst if u do inorder transversal , u get a sorted values
 // Note this can be also done for largest k just go right root and left 
class Solution {
public:
    void call(TreeNode* root,int& ans,int& k){
        if(k==0) return ;
        if(root==nullptr) return ;
        call(root->left,ans,k);
        k--;
        if(k==0){
            ans=root->val;
            return ;
        }
        call(root->right,ans,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        call(root,ans,k);
        return ans;
    }
};