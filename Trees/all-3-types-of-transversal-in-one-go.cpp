/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:
		vector<vector<int>> treeTraversal(TreeNode* root){
			vector<vector<int>> ans;
            vector<int> pre;
            vector<int> post;
            vector<int> inorder;
            stack<pair<TreeNode*,int>> st;
            st.push({root,0});
            while(st.empty()==false){
                int x=st.top().second;
                TreeNode* temp=st.top().first;
                if(x==0){
                    st.top().second++;
                    pre.push_back(temp->data);
                    if(temp->left!=nullptr) st.push({temp->left,0});
                }
                else if(x==1){
                    st.top().second++;
                    inorder.push_back(temp->data);
                    if(temp->right!=nullptr) st.push({temp->right,0});
                }
                else{
                    post.push_back(temp->data);
                    st.pop();
                }
            }
            ans.push_back(inorder);
            ans.push_back(pre);
            ans.push_back(post);
            return ans;
		}
};