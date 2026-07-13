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
    ListNode* swapNodes(ListNode* head, int k) {
       ListNode* node1=head;
       ListNode* node2=head;

       for(int i=1;i<k;i++){
        node1=node1->next;
       }
       
        int size=0;
        ListNode* temp=head;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }

       for(int j=1;j<size-k+1;j++){
            node2=node2->next;
       }

        swap(node1->val,node2->val);

       return head;
    }
};