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
    ListNode* reverse(ListNode* head,int left,int right){
        ListNode* nextptr;
        ListNode* currptr=head;
        ListNode* prevptr=NULL;
        while(currptr && left<=right){
            nextptr=currptr->next;
            currptr->next=prevptr;
            prevptr = currptr;
            currptr=nextptr;
            left++;
        }
        if(!currptr) return prevptr;
        ListNode* temp=prevptr;
        while(temp->next){
            temp = temp->next;
        }
        temp->next=currptr;//adding remaining list at the back after reversing from left to right
        return prevptr;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        if(left==1) return reverse(head,left,right);
        int cnt=1;
        ListNode* temp=head;
        while(temp && cnt<left-1){//move till left-1
            cnt++;
            temp = temp->next;
        }
        temp->next = reverse(temp->next,left,right);//now reverse from left pos as temp is at left-1
        return head;
    }
};