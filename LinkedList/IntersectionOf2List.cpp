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
    // int length(ListNode* head){
    //     ListNode* temp=head;
    //     int cnt=0;
    //     while(temp!=NULL){
    //         cnt++;
    //         temp=temp->next;
    //     }
    //     return cnt;
    // }
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     int d1=length(headA);
    //     int d2=length(headB);
    //     ListNode* l1;
    //     int d = abs(d1-d2);
    //     if(d2>d1){
    //         l1=headB;
    //     }
    //     else l1=headA;
    //     while(d--){
    //         l1 = l1->next;
    //     }
    //     return l1->next;
    // }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* ptr1=headA;
        ListNode* ptr2=headB;
        while(ptr1 != ptr2){
            if(ptr1==NULL) ptr1=headB;
            else ptr1 = ptr1->next;
            if(ptr2==NULL) ptr2=headA;
            else ptr2 = ptr2->next;
        }
        return ptr1;
	}
};