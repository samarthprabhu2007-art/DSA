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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev=nullptr;
        int x=101;
        ListNode* temp=head;
        while(temp!=nullptr){
            if(temp->val==x){
                ListNode* temp2=temp;
                temp=temp->next;
                delete temp2;
            }
            else{
                if(prev!=nullptr){
                    prev->next=temp;
                    prev=temp;
                    x=temp->val;
                    temp=temp->next;
                }
                else{
                    x=temp->val;
                    prev=temp;
                    temp=temp->next;
                }
            }
        }
        if(prev!=nullptr) prev->next=temp;
        return head;
    }
};