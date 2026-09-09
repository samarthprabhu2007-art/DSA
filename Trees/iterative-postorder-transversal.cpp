/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> postOrder(Node* root) {
        stack<pair<Node*,int>> st;
        //0 -> go left
        //1 -> go right
        //2  -> take root and pop
        vector<int> ans;
        st.push({root,0});
        while(st.empty()==false){
            if(st.top().second == 0){
                st.top().second=1;
                if(st.top().first->left != nullptr){
                    st.push({st.top().first->left,0});
                }
            }
            else if(st.top().second == 1){
                st.top().second=2;
                if(st.top().first->right != nullptr){
                    st.push({st.top().first->right,0});
                }
            }
            else{
                ans.push_back(st.top().first->data);
                st.pop();
            }
        }
        return ans;
    }
};