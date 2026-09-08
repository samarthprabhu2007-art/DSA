/* Binary Tree Node Structure
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
    vector<int> preOrder(Node* root) {
        Node* temp=root;
        stack<Node*> st;
        vector<int> ans;
        st.push(root);
        while(st.empty()==false){
            temp=st.top();
            st.pop();
            ans.push_back(temp->data);
            if(temp->right!=nullptr) st.push(temp->right);
            if(temp->left !=nullptr) st.push(temp->left);
        }
        return ans;
    }
};