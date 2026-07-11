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

    ListNode* merge(ListNode* left, ListNode* right) {

    ListNode dummy(-1);
    ListNode* tail = &dummy;

    while (left && right) {

        if (left->val <= right->val) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }

        tail = tail->next;
    }

    if (left)
        tail->next = left;
    else
        tail->next = right;

    return dummy.next;
}

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

    ListNode* mergeSort(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* rightHead=splitAtmid(head);

        ListNode* left=mergeSort(head);//left head
        ListNode* right=mergeSort(rightHead);//right head

        return merge(left,right);//head of sorted ll
    }

    ListNode* sortList(ListNode* head) {
        head=mergeSort(head);
        return head;
    }
};