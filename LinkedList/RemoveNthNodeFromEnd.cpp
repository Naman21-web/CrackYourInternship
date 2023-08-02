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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL)return NULL;
        ListNode* right=head;
        ListNode* left=head;
        while(n--){
            left=left->next;
        }
        if(left==NULL) return right->next;
        while(left->next!=NULL){
            right=right->next;
            left=left->next;
        }
        right->next=right->next->next;
        return head;
    }
};