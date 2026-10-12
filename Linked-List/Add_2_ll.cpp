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
public:/**
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode(0,nullptr);
        int s = l1->val+l2->val;
        ans->val=s%10;
        int c=s/10;
        ListNode* temp=ans;
        //represent wether ll is empty or not 
        l1=l1->next;
        l2=l2->next;
        while(true){
            if(l1==nullptr && l2==nullptr) {
                if(c!=0){
                    ListNode* temp1=new ListNode(c,nullptr);
                    temp->next=temp1;
                }
                break;
            }
            int x=0;
            int y=0;
            if(l1!=nullptr) {
                x=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr) {
                y=l2->val;
                l2=l2->next;
            }
            s=x+y;
            s+=c;
            c=s/10;
            ListNode* temp1=new ListNode(s%10,nullptr);
            temp->next=temp1;
            temp=temp1;
        }
        return ans;
    }
};
    ListNode* reverse(ListNode*& head){
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* temp;
        while(curr!=nullptr){
            temp=curr->next;
            curr->next = prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        int c=0;
        int s=0;
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        while(temp1!=nullptr && temp2!=nullptr){
            s=temp1->val+temp2->val+c;
            c=s/10;
            s%=10;
            ListNode* newnode= new ListNode(s);
            temp->next=newnode;
            temp=temp->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=nullptr){
            s=temp1->val+c;
            c=s/10;
            s%=10;
            ListNode* newnode= new ListNode(s);
            temp->next=newnode;
            temp=temp->next;
            temp1=temp1->next;
        }
        while(temp2!=nullptr){
            s=temp2->val+c;
            c=s/10;
            s%=10;
            ListNode* newnode= new ListNode(s);
            temp->next=newnode;
            temp=temp->next;
            temp2=temp2->next;
        }
        if(c!=0){
            ListNode* newnode= new ListNode(c);
            temp->next=newnode;
            temp=temp->next;
        }
        temp=ans->next;
        delete ans;
        temp=reverse(temp);
        return temp;
    }
};