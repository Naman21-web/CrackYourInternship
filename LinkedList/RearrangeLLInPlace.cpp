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
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* dummy = new ListNode(-1);
        ListNode* l3=dummy;
        while(l1!=NULL && l2!=NULL){
            l3->next=l1;
            l3=l3->next;
            l1=l1->next;
            if(l2!=NULL)l3->next=l2;
            l3=l3->next;
            l2=l2->next;
        }
        if(l1!=NULL) l3->next=l1;
        return dummy->next;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nex;
        while(curr!=NULL){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;          
        }
        fast=slow->next;
        slow->next=NULL;
        fast=reverse(fast);
        ListNode* l=head;
        while(l!=NULL){
            cout<<l->val;
            l=l->next;
        }
        head= merge(head,fast);
    }
};