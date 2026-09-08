/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    vector<int> inOrder(Node* root) {
        stack<pair<Node*,int>> st;
        //if value is 0 ->go left
        //if value is 1 -> go right
        //if value is 2 -> add root and pop
        vector<int> ans;
        st.push({root,0});
        while(st.empty()==false){
            if(st.top().second == 0){
                st.top().second++;
                if(st.top().first->left!=nullptr){
                    st.push({(st.top()).first->left,0});
                }
            }
            else if(st.top().second==1){
                st.top().second++;
                ans.push_back(st.top().first->data);
                if(st.top().first->right!=nullptr){
                    st.push({st.top().first->right,0});
                }
            }
            else{
                st.pop();
            }
        }
        return ans;
    }
};