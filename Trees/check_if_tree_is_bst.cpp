/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool call(Node* root,int left,int right){
        if(root==nullptr) return true;
        int x=root->data;
        if(x>left && x<right){
            bool l = call(root->left,left,min(x,right));
            bool r = call(root->right,max(x,left),right);
            return l && r ;
        }
        return false;
    }
    bool isBST(Node* root) {
        int left = 0;
        int right = INT_MAX;
        return call(root,left,right);
    }
};