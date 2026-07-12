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

    ListNode* splitAtmid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;

        while(fast!=NULL &&fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(prev!=NULL){
            prev->next=NULL;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;

        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;

            prev=curr;
            curr=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* righthead=splitAtmid(head);
        ListNode* Rrighthead=reverse(righthead); 
        ListNode* left=head;
        ListNode* right=Rrighthead;
        ListNode* tail;

        while(left!=NULL && right!=NULL){
            ListNode* nl=left->next;
            ListNode* nr=right->next;

            left->next=right;
            right->next=nl;
            tail=right;

            left=nl;
            right=nr;
        }
       tail->next=right;
    }
};