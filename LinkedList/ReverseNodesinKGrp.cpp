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
    ListNode* reverseK(ListNode* head,int k){
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL && len<k){
            len++;
            temp=temp->next;
        }
        if(len<k) return head;
        ListNode* nextiter=head;
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* nex;
        int x=k;
        while(x--){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        nextiter->next = reverseK(nex,k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head->next==NULL) return head;
        return reverseK(head,k);        
    }
};