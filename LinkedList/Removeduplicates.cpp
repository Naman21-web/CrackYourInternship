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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp=head;
        while(temp){
            ListNode* dup = temp->next;
            int value = temp->val;
            while(dup && dup->val==value) dup = dup->next;
            temp->next = dup;
            temp = temp->next;
        }
        return head;
    }
};