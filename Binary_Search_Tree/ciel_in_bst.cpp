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
    int findCeil(Node* root, int k) {
        int ans=INT_MAX;
        while(root!=nullptr){
            if(root->data == k) return k;
            else if(root->data < k) root=root->right;
            else {
                ans=min(ans,root->data);
                root=root->left;
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
