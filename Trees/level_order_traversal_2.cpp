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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> v;
        queue<TreeNode*> q;
        if(root==nullptr) return ans;
        q.push(root);
        q.push(nullptr);
        while(q.size()!=0){
            if(q.front()==nullptr){
                ans.push_back(v);
                v.clear();
                q.pop();
                if(q.size()==0) break;
                q.push(nullptr);
            }
            if(q.front()->left !=nullptr) q.push(q.front()->left);
            if(q.front()->right !=nullptr) q.push(q.front()->right);
            v.push_back(q.front()->val);
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};