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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<int> zero;
        vector<vector<int>> left;
        vector<vector<int>> right;
        queue<pair<TreeNode *,int>> q;
        q.push({root,0});
        while(q.empty()==false){
            int n=q.size();
            vector<int> temp_zero;
            vector<vector<int>> temp_left(left.size());
            vector<vector<int>> temp_right(right.size());
            while(n--){
                TreeNode* temp = q.front().first;
                int x=q.front().second;
                q.pop();
                if(x==0){
                    temp_zero.push_back(temp->val);
                }
                else if(x>0){
                    if(x>temp_right.size()){
                        vector<int> temp2;
                        temp_right.push_back(temp2);
                    }
                    temp_right[x-1].push_back(temp->val);
                }
                else{
                    if(-x>temp_left.size()){
                        vector<int> temp2;
                        temp_left.push_back(temp2);
                    }
                    temp_left[-x-1].push_back(temp->val);
                }
                if(temp->right!=nullptr) q.push({temp->right,x+1});
                if(temp->left!=nullptr) q.push({temp->left,x-1});
            }
            //update values of temp to main after sort
            sort(temp_zero.begin(),temp_zero.end());
            for(int i=0;i<temp_right.size();i++){
                sort(temp_right[i].begin(),temp_right[i].end());
            }
            for(int i=0;i<temp_left.size();i++){
                sort(temp_left[i].begin(),temp_left[i].end());
            }
            //update vaues
            for(int i=0;i<temp_zero.size();i++){
                zero.push_back(temp_zero[i]);
            }
            for(int i=0;i<temp_right.size();i++){
                for(int j=0;j<temp_right[i].size();j++){
                    if(i>=right.size()){
                        vector<int> temp2;
                        right.push_back(temp2);
                    }
                    right[i].push_back(temp_right[i][j]);
                }
            }
            for(int i=0;i<temp_left.size();i++){
                for(int j=0;j<temp_left[i].size();j++){
                    if(i>=left.size()){
                        vector<int> temp2;
                        left.push_back(temp2);
                    }
                    left[i].push_back(temp_left[i][j]);
                }
            }
        }
        //ans
        reverse(left.begin(),left.end());
        left.push_back(zero);
        for(int i=0;i<right.size();i++){
            left.push_back(right[i]);
        }
        return left;
    }
};