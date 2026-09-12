/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode(-1);
        ListNode* right = new ListNode(-1);
        ListNode* templeft=left;
        ListNode* tempright=right;
        ListNode* temp=head;
        while(temp!=nullptr){
            ListNode* temp2=temp->next;
            temp->next=nullptr;
            if(temp->val < x){
                templeft->next=temp;
                templeft=templeft->next;
            }
            else{
                tempright->next=temp;
                tempright=tempright->next;
            }
            temp=temp2;
        }
        left=left->next;
        right=right->next;
        if(left==nullptr) return right;
        templeft->next=right;
        return left;
    }
};