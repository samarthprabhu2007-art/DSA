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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        q.push({root,1});
        long long ans=1;
        while(q.empty() == false){
            int n=q.size();
            long long st=-1;
            long long end=-1;
            bool is = false;
            if(q.front().second >= INT_MAX) is=true;
            while(n--){
                TreeNode* temp = q.front().first;
                long long y=q.front().second;
                if(is==true) y%=INT_MAX;
                q.pop();
                if(st==-1) st=y;
                end=y;
                if(temp->left!=nullptr) q.push({temp->left,2*y});
                if(temp->right!=nullptr) q.push({temp->right,2*y+1});
            }
            ans=max(ans,end-st+1);
        }
        return  ans;
    }
};