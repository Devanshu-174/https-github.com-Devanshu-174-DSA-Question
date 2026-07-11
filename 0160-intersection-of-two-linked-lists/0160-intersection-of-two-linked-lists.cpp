/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        int D1=0,D2=0;

        while(tempA!=NULL){
            tempA=tempA->next;
            D1++;
        }

        while(tempB!=NULL){
            tempB=tempB->next;
            D2++;
        }
        tempA=headA;
        tempB=headB;

        if(D1>D2){
            int diff=D1-D2;
            while(diff--){
                tempA=tempA->next;
            }
        }
        else{
            int diff=D2-D1;
            while(diff--){
                tempB=tempB->next;
            }
        }

        while(tempA!=tempB){
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return tempA;
    }
};