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
    void reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr!=nullptr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return ;
    }
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        ListNode* left;
        ListNode* right;
        ListNode* prevleft = nullptr;
        ListNode* temp = head;
        int cnt = 1;
        while(temp!=nullptr){
            if(l == cnt) left = temp;
            if(r == cnt){
                right = temp;
                break;
            }
            temp=temp->next;
            cnt++;
        }
        temp = head;
        while(temp!=left){
            prevleft = temp;
            temp=temp->next;
        }
        ListNode* rightnext = right->next;
        right->next = nullptr;
        reverse(left);
        left->next = rightnext;
        if(prevleft == nullptr) return right;
        else{
            prevleft->next = right;
        }
        return head;
    }
};