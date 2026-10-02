/**
class ListNode
{
 * Definition for doubly-linked list.
 *  public:
 *      int data;
 *      ListNode *prev;
 *      ListNode *next;
 *      ListNode() : data(0), prev(nullptr), next(nullptr) {}
 *      ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
 *      ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};
*/

class Solution
{
public:
    ListNode *arrayToDoublyLinkedList(vector<int> &arr) {
        ListNode* ans = new ListNode(-1); //dummy 
        ListNode* temp = ans;
        for(int i=0;i<arr.size();i++){
            ListNode* newnode = new ListNode(arr[i]);
            temp->next = newnode;
            newnode->prev=temp;
            temp=temp->next;
        }
        ListNode* finalans = ans->next;
        if(finalans == nullptr) return nullptr;
        finalans->prev = nullptr;
        delete ans;
        return finalans;
    }
};