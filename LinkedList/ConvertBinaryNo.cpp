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
    ListNode* reverse(ListNode* head){
        ListNode* nextptr;
        ListNode* currptr = head;
        ListNode* prevptr = NULL;
        while(currptr){
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        return prevptr;
    }
    int getDecimalValue(ListNode* head) {
        head=reverse(head);
        ListNode* temp = head;
        int pow=1;
        int no=0;
        while(temp!=NULL){
            no += pow*(temp->val);
            pow *= 2;
            temp = temp->next;
        }
        return no;
    }
};