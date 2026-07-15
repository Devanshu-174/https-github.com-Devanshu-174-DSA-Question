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

    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* newTail=head;
        ListNode* temp=head;
        int n=1;
        if(head==NULL || head->next==NULL ||k==0){
            return head;
        }

        while(temp->next!=NULL){
            temp=temp->next;
            n++;
        }
        k=k%n;

        for (int i = 0; i < n - k - 1; i++) {
            newTail = newTail->next;
        }

        temp->next=head;
        head=newTail->next;
        newTail->next=NULL;

        return head;
        
    }
};