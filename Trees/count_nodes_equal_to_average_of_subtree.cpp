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
    // pair<sum , node> 
    pair<int,int> call(TreeNode* root,int& ans){
        if(root==nullptr) return {0,0};
        pair<int,int> left =call(root->left,ans);
        pair<int,int> right = call(root->right,ans);
        int sum = left.first + right.first + root->val;
        int nodes = left.second + right.second + 1;
        int avg=sum/nodes;
        ans+=(avg == root->val);
        return {sum,nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        int s=0;
        call(root,ans);
        return ans;
    }
};