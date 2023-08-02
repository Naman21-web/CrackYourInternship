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
        ListNode* currnode=head;
        ListNode* prev=NULL;
        ListNode* nextptr;
        while(currnode){
            nextptr = currnode->next;
            currnode->next = prev;
            prev = currnode;
            currnode = nextptr;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        int carry = 0;
        ListNode* dummynode = new ListNode(-1);
        ListNode* ans = dummynode;
        while(l1 && l2){
            int sum = l1->val+l2->val+carry;
            carry = sum/10;
            sum = sum%10;
            // cout<<sum<<carry<<" ";
            ListNode* newnode = new ListNode(sum);
            ans->next = newnode;
            l1 = l1->next;
            l2 = l2->next;
            // cout<<ans->next->val<<" ";
            ans = ans->next;
        }
        while(l1){
            int sum = l1->val+carry;
            carry = sum/10;
            sum = sum%10;
            // cout<<sum<<carry<<" ";
            ListNode* newnode = new ListNode(sum);
            ans->next = newnode;
            l1 = l1->next;
            // cout<<ans->val<<" ";
            ans=ans->next;
        }
        while(l2){
            int sum = l2->val+carry;
            carry = sum/10;
            sum = sum%10;
            // cout<<sum<<carry<<" ";
            ListNode* newnode = new ListNode(sum);
            ans->next = newnode;
            l2 = l2->next;
            // cout<<ans->val<<" ";
            ans=ans->next;
        }
        if(carry!=0){
            ListNode* newnode = new ListNode(carry);
            // cout<<ans->val<<" ";
            ans->next = newnode;
        }
        // cout<<ans->val<<" ";
        dummynode->next = reverse(dummynode->next);
        return dummynode->next;
    }
};